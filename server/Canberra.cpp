#include "Canberra.h"

/**
 * The function takes two vectors as input and returns the sum of the canberra distance between the two vectors
 *
 * @param v1 The first vector
 * @param v2 The vector of the current document
 *
 * @return The Canberra distance between two vectors.
 */
double Canberra::algorithm(vector<double> &v1, vector<double> &v2) {
    double sum = 0, upperSum, lowerSum, tempOne, tempTwo;
    for (int i = 0; i < v1.size(); i++) {
        upperSum = v1.at(i) - v2.at(i);
        if ((upperSum < 0)) {
            upperSum = upperSum * (-1);
        }
        tempOne = v1.at(i);
        tempTwo = v2.at(i);
        if (tempOne < 0)
            tempOne = tempOne * (-1);
        if (tempTwo < 0)
            tempTwo = tempTwo * (-1);
        if (tempOne == 0 && tempTwo == 0) {
            continue;
        }
        lowerSum = tempOne + tempTwo;
        sum = sum + (upperSum / lowerSum);
    }
    return sum;
}