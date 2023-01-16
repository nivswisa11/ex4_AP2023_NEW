#include "Manhattan.h"

/**
 * The function takes two vectors of doubles as parameters and returns the Manhattan distance between them
 *
 * @param v1 The first vector
 * @param v2 the vector of the test data
 *
 * @return The distance between the two vectors.
 */
double Manhattan::algorithm(vector<double> &v1, vector<double> &v2) {
    int i;
    double sum = 0;
    for (i = 0; i < v1.size(); i++) {
        double temp = v1.at(i) - v2.at(i);
        if (temp < 0) {
            temp = temp * (-1);
        }
        sum += pow(temp, 1);
    }
    double distance = pow(sum, 1.0 / (double) 1);
    return distance;
}