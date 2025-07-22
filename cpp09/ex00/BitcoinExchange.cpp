#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    loadDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw FileOpenException();
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string value_str;
        
        if (std::getline(ss, date, ',') && std::getline(ss, value_str)) {
            float value = std::atof(value_str.c_str());
            _database[date] = value;
        }
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10)
        return false;
        
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2025)
        return false;

    if (month < 1 || month > 12)
        return false;
    
    if (day < 1 || day > 31)
        return false;
    
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeapYear ? 29 : 28))
            return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(const float value) const {
    return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _database.upper_bound(date);
    if (it == _database.begin()) {
        return ""; 
    }
    return (--it)->first;
}

float BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _database.find(date);
    if (it != _database.end()) {
        return it->second;
    }
    
    std::string closestDate = findClosestDate(date);
    if (closestDate.empty()) {
        return 0;
    }
    return _database.at(closestDate);
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw FileOpenException();
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t delimiter_pos = line.find(" | ");
        if (delimiter_pos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delimiter_pos);
        std::string value_str = line.substr(delimiter_pos + 3);
        
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        value_str.erase(0, value_str.find_first_not_of(" \t"));
        value_str.erase(value_str.find_last_not_of(" \t") + 1);
        
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        try {
            char* endptr;
            value = std::strtof(value_str.c_str(), &endptr);
            
            if (*endptr != '\0') {
                std::cout << "Error: invalid number format." << std::endl;
                continue;
            }
        } catch (...) {
            std::cout << "Error: invalid number format." << std::endl;
            continue;
        }
        
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = getRate(date);
        float result = value * rate;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    
    file.close();
}