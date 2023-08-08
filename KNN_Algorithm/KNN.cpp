//
// Created by kaykac on 27.12.2022.
//

#include "KNN.h"


KNN::KNN(int a,int b,int c):index(a),x(b),y(c)
{

}

KNN::KNN()
{
}
KNN::~KNN()
{
}

void KNN::setIndex(int a){
    index=a;
}
void KNN::setID(int a){
    if((a>=0 && a<=2) || a==43 )
        ID=a;
    else
        throw invalid_argument("ID value must be 0,1 or 2");

}
void KNN::setX(int a){
    if(a>=-5 && a<=5)
    x=a;
    else
        throw invalid_argument("x value must be between -5,5");
}
void KNN::setY(int a){
    if(a>=-5 && a<=5)
        y=a;
    else
        throw invalid_argument("y value must be between -5,5");
}

int KNN::getIndex()	const{
    return index;
}
int KNN::getID()	const{
    return ID;
}
int KNN::getX()	const{
    return x;
}
int KNN::getY()	const{
    return y;
}
