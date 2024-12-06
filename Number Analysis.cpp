// File Name: Number Analysis
// Name of Programmer: Ebram Azer
// Date: Dec 2024
// Rquirments:Write a program that asks the user for a file name.Assume the file contains a series of numbers, 
// each written on a separate line.
//The program should read the contents of the file into an array then display the following data :
//• The lowest number in the array
//• The highest number in the array
//• The total of the numbers in the array
//• The average of the numbers in the array






#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

int main() {
    using namespace std;

    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    vector<int> numbers;
    int num;

    // Read numbers from the file into a vector
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        cerr << "Error: The file is empty or contains no valid numbers." << endl;
        return 1;
    }

    // Initialize variables
    int lowest = numeric_limits<int>::max();
    int highest = numeric_limits<int>::min();
    int total = 0;

    // Process the numbers
    for (int n : numbers) {
        if (n < lowest) lowest = n;
        if (n > highest) highest = n;
        total += n;
    }

    double average = static_cast<double>(total) / numbers.size();

    // Display the results
    cout << "Lowest number: " << lowest << endl;
    cout << "Highest number: " << highest << endl;
    cout << "Total of numbers: " << total << endl;
    cout << "Average of numbers: " << average << endl;

    return 0;
}
