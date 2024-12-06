//============================================================================
// Name        : CSC450_CTA4_UserInputProgram.cpp
// Author      : Abnel Franquez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
    Program: File Content Appender and Reverser
    Purpose:
    This program is designed to perform two key tasks:
    1. **Append User Input**: It takes input from the user and appends it to an existing text file (`CSC450_CT5_mod5.txt`).
    2. **Reverse File Content**: It reads the content of the same file, reverses all its characters, and writes the reversed content to a new file (`CSC450-mod5-reverse.txt`).

    Key Features:
    - Ensures proper file handling by checking if files are successfully opened.
    - Uses efficient string operations to handle content.
    - Demonstrates dynamic file writing and reading operations in C++.

    Usage:
    - The user inputs a string, which is appended to the `CSC450_CT5_mod5.txt` file.
    - The program then creates `CSC450-mod5-reverse.txt`, containing the reversed content of the input file.

   
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

/*
    Program: File Content Reversal
    Purpose:
    This program appends user-provided input to an existing file and then reads the file's content, reverses it,
    and writes the reversed content to a new file.

    
*/

// Function to reverse the content of a file and write it to another file
void reverseFileContent(const std::string& inputFile, const std::string& outputFile) {
    // Open the input file for reading
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open " << inputFile << " for reading.\n";
        return;
    }

    // Read the entire content of the file into a string
    std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close(); // Close the input file

    // Reverse the content
    std::reverse(content.begin(), content.end());

    // Open the output file for writing
    std::ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open " << outputFile << " for writing.\n";
        return;
    }

    // Write the reversed content to the output file
    outFile << content;
    outFile.close(); // Close the output file

    std::cout << "Reversed content has been written to " << outputFile << ".\n";
}

int main() {
    // Use the absolute paths for the files
    const std::string inputFile = "C:/Users/AFranquez/eclipse-workspace/CSC450_CT5_mod5.txt";
    const std::string outputFile = "C:/Users/AFranquez/eclipse-workspace/CSC450-mod5-reverse.txt";

    // Open the input file in append mode
    std::ofstream file(inputFile, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << inputFile << " for writing.\n";
        return 1;
    }

    // Prompt the user for input
    std::string userInput;
    std::cout << "Enter text to append to " << inputFile << ": ";
    std::getline(std::cin, userInput);

    // Append the user input to the file
    file << userInput << '\n';
    file.close(); // Close the file
    std::cout << "Text appended to " << inputFile << ".\n";

    // Reverse the content of the file and write to the output file
    reverseFileContent(inputFile, outputFile);

    return 0;
}
