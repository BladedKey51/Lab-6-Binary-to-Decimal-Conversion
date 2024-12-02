/*
Lane Jones-Popp
Computer Science Fall 2024
Dec. 3
Lab 6, Binary to Decimal Conversion
Convert Binary numbers into its decimal counter part and you have to have error codes.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Open the input file
    ifstream inputFile("Binaryln.dat");

    // Check if the file opened successfully
    if (!inputFile) {
        cout << "Error: Unable to open file Binaryln.dat" << endl;
        return 1;
    }

    // Print column headers
    cout << setw (18) << "Binary Number" << setw(30) << "Decimal Equivalent" << endl;

    string line;
    while (getline(inputFile, line)) {
        int decimalValue = 0;    // To store the decimal equivalent
        bool isValid = true;    // checks to see if the binary number is vaild 
        bool founddigit = false; // checks if a digit has been read or not
        int Widithset = 0;
        string binaryNumber;    // To store the binary number as a string

        // Process the line character by character
        for (char c : line) {
            if (c == ' ') {
                if (founddigit) {
                    isValid = false;
                    break;
                }
            }
            else if (c == '0' || c == '1') {
                founddigit = true;
                decimalValue = decimalValue * 2 + (c - '0'); // Update decimal value
                binaryNumber += c; // Append valid binary digit to binaryNumber
                Widithset++;
            }
            else {
                // Invalid character encountered
                isValid = false;
                break;
            }
        }

        // Output the result
        if (isValid && !binaryNumber.empty()) {
            cout << setw(18) << binaryNumber << setw(22) << decimalValue << endl;
            Widithset = 0;
        }
        else if (!isValid) {
            cout << "Bad digit on input" << endl;
        }
    }

    // Close the input file
    inputFile.close();

    return 0;
}

