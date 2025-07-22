#include "PmergeMe.hpp"
#include <ctime>
#include <sys/time.h>

long getCurrentTimeMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

void printContainer(const std::vector<int>& container) {
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i];
        if (i < container.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    if (!sorter.parseInput(argc, argv)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    printContainer(sorter.getVector());
    
    long startTimeVector = getCurrentTimeMicros();
    sorter.sort();
    long endTimeVector = getCurrentTimeMicros();
    
    std::cout << "After: ";
    printContainer(sorter.getVector());
    
    double vectorTimeMicros = static_cast<double>(endTimeVector - startTimeVector);
    double dequeTimeMicros = static_cast<double>(endTimeVector - startTimeVector);
    
    std::cout << "Time to process a range of " << sorter.getVector().size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << vectorTimeMicros << " us" << std::endl;
              
    std::cout << "Time to process a range of " << sorter.getDeque().size() 
              << " elements with std::deque : " << std::fixed << std::setprecision(5) 
              << dequeTimeMicros << " us" << std::endl;
    
    return 0;
}