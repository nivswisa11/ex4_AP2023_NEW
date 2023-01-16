#ifndef EX3_AP_MASTERDISTANCE_H
#define EX3_AP_MASTERDISTANCE_H
#include <cmath>
#include <vector>

using namespace std;

//This is a class that has two vectors of doubles, v1 and v2. It also has a virtual function called algorithm
// that takes two vectors of doubles as parameters.
class MasterDistance {
private:
    vector<double> v1;
    vector<double> v2;
public:
    //A virtual function that takes two vectors of doubles as parameters.
    virtual double algorithm(vector<double> &v1, vector<double> &v2);
};

#endif
