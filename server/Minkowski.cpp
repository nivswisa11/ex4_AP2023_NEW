#include "Minkowski.h"

/**
 * It takes two vectors of doubles, and returns the Minkowski distance between them
 *
 * @param v1 The first vector
 * @param v2 The vector that we are comparing to.
 *
 * @return The distance between two vectors.
 */
double Minkowski::algorithm(vector<double> &v1, vector<double> &v2) {
    int i;
    double sum = 0;
    for (i = 0; i < v1.size(); i++) {
        double temp = v1.at(i) - v2.at(i);
        if (temp < 0) {
            temp = temp * (-1);
        }
        sum += pow(temp, 2);
    }
    double distance = pow(sum, 1.0 / (double) 2);
    return distance;
}