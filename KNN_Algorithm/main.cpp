#include <iostream>
#include"KNN.h"
#include "CalculateKnn.h"
//* 30 sample points
#define SAMPLES_SIZE 30
//* 10 test points
#define TEST_SIZE 10


int main() {

    CalculateKnn Knn(SAMPLES_SIZE,TEST_SIZE);
    return 0;

}


