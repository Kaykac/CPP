//
// Created by kaykac on 03.01.2023.
//

#ifndef OPP_LAB_CALCULATEKNN_H
#define OPP_LAB_CALCULATEKNN_H
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include<vector>
#include<map>
#include<stdexcept>

#include "KNN.h"


class CalculateKnn {
public:
	typedef multimap<double, int, less<double> > Mmap;
	
	
    CalculateKnn(int a, int b);
     //! function for creating random samples
     static KNN randSamples();
     //! function for creating test samples
     static KNN test_func();
     //! function for printing vectors that type of "KNN"
     void printVector(vector<KNN> &a)	const;
     //! function for printing maps
     void printMap(Mmap &a)	const;
     //! function for detection category ID
     int detectId(Mmap &a,int k);
     //! function for calculating euclidean distance
     Mmap eucDist(vector<KNN> &a, KNN &b);
     //! most general function for KNN algorithm
     void knn(vector<KNN> &samples ,vector<KNN> &test);
     //! set function for s
     void setS(int a);
    //! get function for return s
     int getS()	const;
     //! set function for t
     void setT(int a);
     //! get function for return t
     int getT() const;





private:
    //! integer to hold SAMPLES_SIZE value
    int s;

    //! integer to hold TEST_SIZE value
    int t;



};


#endif //OPP_LAB_CALCULATEKNN_H
