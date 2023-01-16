#include "MasterDistance.h"
#include "VectorCreation.h"
#include "VectorBase.h"
#include "CsvReading.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <sstream>

using namespace std;


string calculate(char buffer[], string fileName);


/**
 * It creates a socket, binds it to a port, listens to it, accepts a client, receives a message from the client,
 * calculates the result, sends the result back to the client, and closes the connection
 *
 * @param argc the number of arguments passed to the program.
 * @param argv the arguments passed to the program.
 *
 * @return the value of the expression.
 */
int main(int argc, char *argv[]) {
    // It checks if the number of arguments passed to the program is 3. If it is not, it exits the program.
    if (argc != 3) {
        exit(0);
    }
    string fileName = argv[1];
    int server_port;
    try {
        server_port = stoi(argv[2]);
    }
    catch (exception &e) {
        exit(0);
    }
    // Checking if the port number is valid.
    if (server_port < 1025 || server_port > 65536) {
        exit(0);
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // Checking if the socket was created successfully. If it was not, it prints an error message.
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    // It binds the socket to the port number.
    if (::bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    // Listening to the socket.
    if (listen(sock, 1) < 0) {
        perror("error listening to a socket");
    }
    // Creating a socket, binding it to a port, listening to it, accepting a client, receiving a message from the
    // client calculating the result, sending the result back to the client, and closing the connection.
    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        // Receiving the input from the client, calculating the result, and sending the result back to the client.
        while (true) {
            char buffer[4096];
            int expected_data_len = sizeof(buffer);
            // Receiving the input from the client.
            int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            string c;
            if (read_bytes == 0) {
                cout << "connection closed";
                break;
            } else if (read_bytes < 0) {
                cout << "failed to read data";
                break;
            } else {
                c = calculate(buffer, fileName);
                if (c == "-1") {
                    break;
                }
                // Setting the buffer to 0.
                memset(&buffer, 0, sizeof(buffer));
                // Copying the string c into the buffer.
                strncpy(buffer, c.c_str(), c.size());
                buffer[c.size()] = '\0';
            }
            read_bytes = c.length();
            // It sends the result back to the client.
            int sent_bytes = send(client_sock, buffer, read_bytes, 0);
            // It checks if the number of bytes sent to the client is less than 0. If it is, it prints an error message.
            if (sent_bytes < 0) {
                perror("error sending to client");
                break;
            }
        }
        close(client_sock);
    }
    close(sock);
    return 0;
}


/**
 * It takes in a string, extracts the numbers,distance algorithm and K from it, and then uses those values to calculate
 * the distance
 *
 * @param buffer The string that contains the input from the user
 * @param fileName The name of the csv file that contains the data
 *
 * @return the class of the input vector.
 */
string calculate(char buffer[], std::string fileName) {
    // Initialize the stringstream with the buffer string
    std::stringstream ss(buffer);
    // Extract all the numbers until the first letter and save them in inputVector
    std::vector<double> inputVector;
    string s, distanceAlgo;
    int k;
    // Extracting the numbers from the input string and saving them in inputVector.
    while (ss >> s) {
        try {
            // Converting the string to a double and then pushing it to the inputVector.
            inputVector.push_back(stod(s));
        } catch (exception &e) {
            distanceAlgo = s;
            ss >> s;
            try {
                k = stoi(s);
            } catch (exception &e) {
                string retStr = "invalid input";
                return retStr;
            }
        }
    }
    // Use the extracted values to calculate the distance
    std::vector<VectorBase> masterVector;

    string finalClass = csvIsValid(k, fileName, distanceAlgo, masterVector, inputVector);
    masterVector.clear();
    inputVector.clear();
    return finalClass;
}

