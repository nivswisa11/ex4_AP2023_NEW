#ifndef EX3_AP_MANHATTAN_H
#define EX3_AP_MANHATTAN_H
#include "MasterDistance.h"

//A class that inherits from MasterDistance. It implements the algorithm function.
class Manhattan : public MasterDistance{
public:
    //A function that calculates the distance between two vectors.
    double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
