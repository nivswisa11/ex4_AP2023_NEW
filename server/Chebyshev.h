#ifndef EX3_AP_CHEBYSHEV_H
#define EX3_AP_CHEBYSHEV_H
#include "MasterDistance.h"

//A class that inherits from the MasterDistance class.
class Chebyshev : public MasterDistance {
public:
    //A function that calculates the distance between two vectors.
    double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
