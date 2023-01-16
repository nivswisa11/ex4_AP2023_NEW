#ifndef EX3_AP_CSVREADING_H
#define EX3_AP_CSVREADING_H
#include "VectorCreation.h"
#include "VectorBase.h"
#include "algorithm"

using namespace std;

/**
 * It takes in a string, two vectors, and returns a double value according to the distance calculation algorithm
 *
 * @param distanceAlgo The distance algorithm to be used.
 * @param v1 vector of the file
 * @param v2 vector of the user
 *
 * @return The distance between two vectors.
 */
double distanceCalculator(string distanceAlgo, vector<double> &v1, vector<double> &v2);

/**
 * If the size of the masterVector is less than k or k is less than or equal to 0, then return 0
 *
 * @param k The number of clusters to be created.
 * @param masterVector The vector of vectors that we're going to be using to find the k-means.
 *
 * @return 1 if the k is valid, 0 otherwise.
 */
int kCheck(int k, vector<VectorBase> &masterVector);

/**
 * It sorts the vector of VectorBase objects by distance
 *
 * @param masterVector The vector that contains all the vectors that are being sorted.
 */
void sortVector(vector<VectorBase> &masterVector);

/**
 * Iterate over the last k elements of the master vector, count the number of occurrences of each string, and return the
 * string with the highest count
 *
 * @param k The number of elements to consider in the vector
 * @param masterVector The vector of VectorBase objects that we created in the previous step.
 *
 * @return The final classification string.
 */
string highestOccurrence(int k, vector<VectorBase> &masterVector);

/**
 * This function reads each row from the file and inserts it to an object containing a vector a string and a double.
 * it checks the validity of the user input and then calls all the other functions in the class. it returns final
 * classification.
 *
 * @param k The number of nearest neighbors to find.
 * @param fileName The name of the file that is being read.
 * @param distanceAlgo This is the distance algorithm that the user has chosen.
 * @param masterVector This is the vector that holds all the vectors that are read in from the csv file.
 * @param inputVector This is the vector that the user inputs.
 *
 * @return The final classification string.
 */
string csvIsValid(int k,string fileName, string distanceAlgo, vector<VectorBase> &masterVector,
                vector<double> &inputVector);

#endif
