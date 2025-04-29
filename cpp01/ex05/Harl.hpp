#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    // Function pointer type for member functions
    typedef void (Harl::*ComplaintFunction)(void);
    
    // Array to store level names
    static const std::string levels[4];
    // Array to store corresponding member function pointers
    static const ComplaintFunction functions[4];

public:
    Harl(void);
    ~Harl(void);
    
    void complain(std::string level);
};

#endif