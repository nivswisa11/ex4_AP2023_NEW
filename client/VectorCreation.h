#include <vector>
#include <string>

using namespace std;

/**
 * If the first character is a digit or a negative sign, and if there are no more than one decimal point, and if all the
 * characters are digits or a decimal point, then return 1, else return 0
 *
 * @param s The string to be checked
 *
 * @return a boolean value.
 */
int numCheck(string s);

/**
 * It checks if the string is empty, if the first character is a space, and if there are any double spaces
 *
 * @param textLine The string that is being checked.
 *
 * @return an integer.
 */
int stringValidation(string textLine);

/**
 * It takes a vector of doubles as a parameter, reads a line from the standard input, checks if the line is valid, and
 * if it is, it parses the line and inserts the numbers into the vector
 *
 * @param vector the vector to insert the numbers into
 *
 * @return 1 if the function was successful, 0 if it was not.
 */
int insertToVector(vector<double> &vector);
