#ifndef EX3_AP_CANBERRA_H
#define EX3_AP_CANBERRA_H
#include "MasterDistance.h"

//A class that inherits from the MasterDistance class.
class Canberra : public MasterDistance {
public:
    //A function that calculates the Canberra distance between two vectors.
    double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
