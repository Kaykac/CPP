//
// Created by kaykac on 27.12.2022.
//

#ifndef OPP_LAB_KNN_H
#define OPP_LAB_KNN_H
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include<vector>
#include<map>
#include<stdexcept>




using namespace std;
class KNN {

public:
	//! overloaded constructor that assigns index and coordinates.
    KNN(int a,int b,int c);
    //! Empty constructor.
    KNN();
    //! Destructor
    ~KNN();

    //! get functions for Index
    int getIndex()	const;
    //! get functions for ID
    int getID()	const;
    //! get functions for X
    int getX()	const;
    //! get functions for Y
    int getY()	const;
    //! set functions for Index
    void setIndex(int a);
    //! set functions for ID
    void setID(int a);
    //! set functions for X
    void setX(int a);
    //! set functions for Y
    void setY(int a);
private:
	//! an integer for index number
    int index;
    //! an integer for ID number
    int ID;
    //! an integer for x  coordinate
    int x;
	//! an integer for y coordinate
    int y;

};


#endif //OPP_LAB_KNN_H
