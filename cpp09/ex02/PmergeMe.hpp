#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <deque>
#include <iterator>

class PmergeMe {
private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    bool _hasStraggler;
    int _straggler;

    void fordJohnsonSortVector(std::vector<int>& arr);
    void mergePairsVector(std::vector<std::pair<int, int> >& pairs);
    void insertSmallerElementsVector(std::vector<int>& sorted, std::vector<int>& toInsert);
    int binarySearchVector(const std::vector<int>& arr, int val, int start, int end);

    void fordJohnsonSortDeque(std::deque<int>& arr);
    void mergePairsDeque(std::deque<std::pair<int, int> >& pairs);
    void insertSmallerElementsDeque(std::deque<int>& sorted, std::deque<int>& toInsert);
    int binarySearchDeque(const std::deque<int>& arr, int val, int start, int end);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool parseInput(int argc, char* argv[]);
    void sort();
    
    const std::vector<int>& getVector() const;
    const std::deque<int>& getDeque() const;
};

#endif