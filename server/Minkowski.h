#ifndef EX3_AP_MINKOWSKI_H
#define EX3_AP_MINKOWSKI_H
#include "MasterDistance.h"

//This is a class that inherits from the MasterDistance class.
class Minkowski : public MasterDistance {
public:
    //This is a function that calculates the Minkowski distance between two vectors.
    double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
