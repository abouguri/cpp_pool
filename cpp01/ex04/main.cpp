#include <iostream>
#include <fstream>
#include <string>

std::string replaceAllOccurrences(const std::string& text, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t pos = 0;
    size_t previousPos = 0;

    if (s1.empty())
    {
        return text;
    }

    while ((pos = text.find(s1, previousPos)) != std::string::npos)
    {
        result.append(text, previousPos, pos - previousPos);
        result.append(s2);
        previousPos = pos + s1.length();
    }

    result.append(text, previousPos, text.length() - previousPos);
    
    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: string1 cannot be empty" << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return 1;
    }

    std::string outputFilename = filename + ".replace";

    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot create file " << outputFilename << std::endl;
        inputFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string replacedLine = replaceAllOccurrences(line, s1, s2);
        
        outputFile << replacedLine;
        
        if (!inputFile.eof())
        {
            outputFile << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Replacement complete. Output written to " << outputFilename << std::endl;
    
    return 0;
}