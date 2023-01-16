#ifndef EX3_AP_VECTORBASE_H
#define EX3_AP_VECTORBASE_H
#include <vector>
#include <string>

using namespace std;

//This is a class that represents a vector base.
class VectorBase {
private:
    string vectorClassification;
    vector<double> v;
    double algoDistance;
public:
    //This is a constructor.
    VectorBase(string flowerName, vector<double> v, double algoDistance);
    //This function returns the distance of the vector.
    double getDistance();
    //This function returns the name of the flower.
    string getStr();
};

#endif
