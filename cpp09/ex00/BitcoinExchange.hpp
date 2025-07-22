
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <algorithm>

class BitcoinExchange
{
private:
    std::map<std::string, float> _database;

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& databaseFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
    
    // Helper methods
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const float value) const;
    std::string findClosestDate(const std::string& date) const;
    float getRate(const std::string& date) const;

    // Exception classes
    class FileOpenException : public std::exception {
    public:
        virtual const char* what() const throw() { return "Error: could not open file."; }
    };
};

#endif