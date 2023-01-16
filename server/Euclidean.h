#ifndef EX3_AP_EUCLIDEAN_H
#define EX3_AP_EUCLIDEAN_H
#include "MasterDistance.h"

//This is a class that inherits from the MasterDistance class. It has a function called algorithm that takes two
//vectors and returns a double.
class Euclidean : public MasterDistance {
public:
    //A function that takes two vectors and returns a double.
    double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
