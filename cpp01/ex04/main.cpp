#include <iostream>
#include <fstream>
#include <string>

// Function to replace all occurrences of s1 with s2 in text
std::string replaceAllOccurrences(const std::string& text, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t previousPos = 0;

    // Skip processing if s1 is empty
    if (s1.empty())
    {
        return text;
    }

    // Find and replace all occurrences
    while ((pos = text.find(s1, previousPos)) != std::string::npos)
    {
        // Add the part before the occurrence
        result.append(text, previousPos, pos - previousPos);
        // Add the replacement string
        result.append(s2);
        // Move past this occurrence
        previousPos = pos + s1.length();
    }

    // Add the rest of the original string
    result.append(text, previousPos, text.length() - previousPos);
    
    return result;
}

int main(int argc, char *argv[])
{
    // Check if the number of arguments is correct
    if (argc != 4) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    // Extract arguments
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Check if s1 is empty
    if (s1.empty()) {
        std::cerr << "Error: string1 cannot be empty" << std::endl;
        return 1;
    }

    // Open the input file
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return 1;
    }

    // Create the output filename
    std::string outputFilename = filename + ".replace";

    // Open the output file
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create file " << outputFilename << std::endl;
        inputFile.close();
        return 1;
    }

    // Process the file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        // Replace occurrences in this line
        std::string replacedLine = replaceAllOccurrences(line, s1, s2);
        
        // Write the modified line to the output file
        outputFile << replacedLine;
        
        // Add a newline if not at end of file
        if (!inputFile.eof()) {
            outputFile << std::endl;
        }
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "Replacement complete. Output written to " << outputFilename << std::endl;
    
    return 0;
}