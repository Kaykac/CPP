//
// Created by kaykac on 03.01.2023.
//

#include "CalculateKnn.h"


typedef multimap<double, int, less<double> > Mmap;



void CalculateKnn::setT(int a){
    if(a>0)
        t=a;
    else
        throw invalid_argument("T value must be positive ");
}
int CalculateKnn::getT()	const{
    return t;
}


void CalculateKnn::setS(int a){
    if(a>0)
        s=a;
    else
        throw invalid_argument("S value must be positive");
}
int CalculateKnn::getS()	const{
    return s;
}





/*!
 * This constructor asks whether to include srand(). Then it creates sample and test groups according to the a and b values with the generate() function. Calls the knn() function, which implement the latest knn algorithm. outputs to the terminal at each step.
 * @param a -->number of sample group
 * @param b -->number of test group
 */

CalculateKnn::CalculateKnn(int a, int b) : s(a), t(b){

    char c;
    cout<<"Do you want samples to be randomly selected depend on time?\nPlease enter your choice (y-n):";
    while(true){  //choosing to activating or inactivating for srand(time(NULL)).
        cin>>c;
        if(c=='y'||c=='Y'){
            srand(time(NULL));
            break;
        }
        else if(c=='n'||c=='N')
            break;
        else
            cerr<<endl<<"Invalid choice please try again!"<<"(y-n):";

    }

    //!creating vector that storing KNN type class for samples
    vector<KNN> samples(a);

    //!creating vector that storing KNN type class for test samples
    vector<KNN> test(b);

    //!creating samples vector that x-y values are randomly and 1st 10 class' ID is 0, 2nd 10 class' ID is 1, 3rd 10 class' ID is 2, with 'generate()' function
    generate(samples.begin(),samples.end(),CalculateKnn::randSamples);
    cout<<"SAMPLES:"<<endl;
    printVector(samples);

    //!creating test vector that x-y values are randomly their ID unknow
    generate(test.begin(),test.end(),test_func);
    cout<<"TESTS:"<<endl;
    printVector(test);

    //!'knn()' func. calls those functions in order eucDist, detectId. and calculates the ID according to knn.
    knn(samples,test);
    cout<<"Tests after calculation:"<<endl;
    printVector(test);

    //!test vector insert to end of samples vector.
    samples.insert(samples.end(), test.begin(), test.end());
    cout<<"Samples after inserting:"<<endl;
    printVector(samples);


}







/*!
 * @param samples -->samples group
 * @param test  -->test group
 */
void CalculateKnn::knn(vector<KNN> &samples ,vector<KNN> &test){


    int n=0;
    cout<<"Please enter the #neighborhood:";
    cin>>n;
    cout<<endl<<"****************************"<<endl;

    for(int i=0;i<getT();i++){
        Mmap dic;
        dic=eucDist(samples,test[i]); //!Calculates the euclidean distance and return a multimap. (multimap's size is equal to samples vector's size)
        int ve=detectId(dic,n);	//!Return catagory ID according to n nearest neighbors.
        cout<<"("<<test[i].getX()<<","<<test[i].getY()<<")		"<<"ID->"<<ve<<endl; //!Outputs location and new ID for test.
        //printMap(dic);
        test[i].setID(ve); //!Assign new category ID.
    }
    cout<<endl<<"****************************"<<endl<<endl;

}


/*!
 * @param a -->map for sorted category ID.
 * @param k -->number of neighbors
 * @return  --> returning category ID (43 for error detection).
 */
int CalculateKnn::detectId(Mmap &a,int k){
    int z=0,o=0,t=0;
    Mmap::const_iterator it=a.begin();


    if(k<=0)
        return 43;
    else
        for(int i=0;i<k;i++){
            if(it->second==0)
                z++;
            else if(it->second==1)
                o++;
            else if(it->second==2)
                t++;

            it++;
        }
    it=a.begin();
    int ar[3]={z,o,t};


    if(ar[0]==ar[1] && ar[1]==ar[2])
        return it->second;
    else if((max_element(ar,ar+3))==&ar[0])
        return 0;
    else if((max_element(ar,ar+3))==&ar[1])
        return 1;
    else if((max_element(ar,ar+3))==&ar[2])
        return 2;
    else
        return 43;

}




/*!
 * @param a -->first 30 samples
 * @param b -->test point
 * @return	-->map (1st item of map is distance. 2nd item of map is catagory ID.)
 */
Mmap CalculateKnn::eucDist(vector<KNN> &a, KNN &b){
    Mmap temp;
    for(int i=0;i<a.size();i++){
        double soma = pow((a[i].getX() - b.getX()), 2) +pow((a[i].getY() - b.getY()), 2);
        double v= sqrt(soma);
        int Id=a[i].getID();
        temp.insert(Mmap::value_type(v,Id));
    }
    return temp;
}


/*!
 * @param a --> name of map
 */
void CalculateKnn::printMap(Mmap &a)	const{
    cout<<"------------MAP------------"<<endl;
    cout<<"Euc_Dist	Cat_ID"<<endl;
    for(Mmap::const_iterator it=a.begin();it!=a.end();++it){
        cout<<it->first<<"		"<<it->second<<endl;
    }
}


/*!
 * @return -->returning test points
 */
KNN CalculateKnn::randSamples(){
    KNN temp;
    static int i=0;
    if(i<10)
        temp.setID(0);
    else if(i<20)
        temp.setID(1);
    else
        temp.setID(2);

    temp.setIndex(i);
    temp.setX(rand()%10-5);
    temp.setY(rand()%10-5);
    i++;
    return temp;
}



/*!
 * @return -->returning samples
 */
KNN CalculateKnn::test_func(){

    KNN temp;
    static int i=0;

    temp.setID(43);//! 43 is invalide number for ID.
    temp.setIndex(i+30);
    temp.setX(rand()%10-5); //! random coordinate for x (from -5 to 5).
    temp.setY(rand()%10-5); //! random coordinate for y (from -5 to 5).
    i++;
    return temp;
}



/*!
 * @param a -->name of vector
 */
void CalculateKnn::printVector(vector<KNN> &a)	const{
    cout<<"Index  ID   X-Y"<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i].getIndex()<<"     "<<a[i].getID()<<"     ("<<a[i].getX()<<","<<a[i].getY()<<")"<<endl;
    }
    cout<<"-------------------------------"<<endl;
    cout<<endl;
}
