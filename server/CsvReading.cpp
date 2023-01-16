#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include "CsvReading.h"
#include "Minkowski.h"
#include "Euclidean.h"
#include "Canberra.h"
#include "Manhattan.h"
#include "Chebyshev.h"

using namespace std;

double distanceCalculator(string distanceAlgo, vector<double> &v1, vector<double> &v2) {
    // This is checking the distance algorithm that the user has inputted. If the user has inputted a valid distance
    // algorithm, the program will calculate the distance between the two vectors.
    double distance = 0;
    if (distanceAlgo == "AUC") {
        Euclidean m;
        distance = m.algorithm(v1, v2);
    } else if (distanceAlgo == "MAN") {
        Manhattan m;
        distance = m.algorithm(v1, v2);
    } else if (distanceAlgo == "CHB") {
        Chebyshev m;
        distance = m.algorithm(v1, v2);
    } else if (distanceAlgo == "CAN") {
        Canberra m;
        distance = m.algorithm(v1, v2);
    } else if (distanceAlgo == "MIN") {
        Minkowski m;
        distance = m.algorithm(v1, v2);
    }
    return distance;
}

int kCheck(int k, vector<VectorBase> &masterVector) {
    if (masterVector.size() < k || k <= 0) {
        return 0;
    }
    return 1;
}

void sortVector(vector<VectorBase> &masterVector) {
    for (int i = 0; i < masterVector.size(); i++) {
        for (int j = 0; j < masterVector.size(); j++) {
            // This is sorting the vector by distance.
            if (masterVector.at(i).getDistance() > masterVector.at(j).getDistance()) {
                swap(masterVector.at(i), masterVector.at(j));
            }
        }
    }
}

string highestOccurrence(int k, vector<VectorBase> &masterVector) {
    vector<string> stringVector;
    for (int i = masterVector.size(); i > masterVector.size() - k; i--) {
        stringVector.push_back(masterVector.at(i - 1).getStr());
    }
    // Create a map to count the number of occurrences of each string
    map<string, int> counts;
    // Iterate over the strings in the vector and increment the count for each string
    for (const std::string &str: stringVector) {
        counts[str]++;
    }
    // Find the string with the highest count
    std::string most_common;
    int max_count = 0;
    map<string, int>::iterator it;
    for (it = counts.begin(); it != counts.end(); it++) {
        if (it->second > max_count) {
            most_common = it->first;
            max_count = it->second;
        }
    }
    return most_common;
}

string csvIsValid(int k, string fileName, string distanceAlgo, vector<VectorBase> &masterVector,
                  vector<double> &inputVector) {
    string textLine;
    double vectorDistanceValue;
    // This is checking if the distance algorithm that the user has inputted is valid. If it is not, the program will
    // exit.
    if (distanceAlgo != "AUC" && distanceAlgo != "MAN" && distanceAlgo != "CHB" && distanceAlgo != "CAN"
        && distanceAlgo != "MIN") {
        string retStr = "invalid input";
        return retStr;
    }
    // Opening the file and reading it.
    fstream file(fileName, ios::in);
    // This is reading the csv file and storing the data into a vector.
    if (file.is_open()) {
        while (getline(file, textLine)) {
            istringstream lineStream(textLine);
            string s;
            vector<double> digitVector;
            while (getline(lineStream, s, ',')) {
                // This is checking if the string is a number. If it is, it will convert it to a double and push it into
                //the vector.
                if (numCheck(s)) {
                    try {
                        double d = stod(s);
                        digitVector.push_back(d);
                    }
                    catch (exception &e) {
                        break;
                    }
                }
                // This is checking if the input vector and the digit vector are the same size. If they are not, the
                //program exits.
                if (!numCheck(s)) {
                    if (inputVector.size() != digitVector.size()) {
                        string retStr = "invalid input";
                        return retStr;
                    } else {
                        vectorDistanceValue = distanceCalculator(distanceAlgo, digitVector, inputVector);

                    }
                }
            }
            VectorBase rowVector(s, digitVector, vectorDistanceValue);
            masterVector.push_back(rowVector);
            // Clearing the string stream.
            lineStream.str("");
            // Clearing the vector.
            digitVector.clear();
        }
        int valCheck = kCheck(k, masterVector);
        // This is checking if the k value is valid. If it is not, the program will exit.
        if (valCheck == 0) {
            string retStr = "invalid input";
            return retStr;
        }
        sortVector(masterVector);
        string classification = highestOccurrence(k, masterVector);
        return classification;
    } else {
        cout << "Could not open the file\n";
        exit(0);
    }
}



