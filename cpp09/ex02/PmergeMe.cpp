#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _hasStraggler(false), _straggler(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) 
    : _vector(other._vector), _deque(other._deque),
      _hasStraggler(other._hasStraggler), _straggler(other._straggler) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
        _hasStraggler = other._hasStraggler;
        _straggler = other._straggler;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        for (size_t j = 0; j < arg.size(); ++j) {
            if (!isdigit(arg[j])) {
                return false;
            }
        }
        
        int num;
        std::stringstream ss(arg);
        ss >> num;
        
        if (num < 0) {
            return false;
        }
        
        _vector.push_back(num);
        _deque.push_back(num);
    }
    return true;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    _hasStraggler = arr.size() % 2 == 1;
    if (_hasStraggler) {
        _straggler = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a < b) {
            std::swap(a, b);
        }
        pairs.push_back(std::make_pair(a, b));
    }

    mergePairsVector(pairs);

    std::vector<int> sorted;
    std::vector<int> toInsert;

    for (size_t i = 0; i < pairs.size(); ++i) {
        sorted.push_back(pairs[i].first);
        toInsert.push_back(pairs[i].second);
    }

    insertSmallerElementsVector(sorted, toInsert);

    if (_hasStraggler) {
        int pos = binarySearchVector(sorted, _straggler, 0, sorted.size() - 1);
        sorted.insert(sorted.begin() + pos, _straggler);
    }

    arr = sorted;
}

void PmergeMe::mergePairsVector(std::vector<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1) {
        return;
    }

    size_t mid = pairs.size() / 2;
    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    mergePairsVector(left);
    mergePairsVector(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].first <= right[j].first) {
            pairs[k++] = left[i++];
        } else {
            pairs[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        pairs[k++] = left[i++];
    }

    while (j < right.size()) {
        pairs[k++] = right[j++];
    }
}

void PmergeMe::insertSmallerElementsVector(std::vector<int>& sorted, std::vector<int>& toInsert) {
    for (size_t i = 0; i < toInsert.size(); ++i) {
        int val = toInsert[i];
        int pos = binarySearchVector(sorted, val, 0, i);
        sorted.insert(sorted.begin() + pos, val);
    }
}

int PmergeMe::binarySearchVector(const std::vector<int>& arr, int val, int start, int end) {
    if (start > end) {
        return start;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == val) {
        return mid;
    }

    if (arr[mid] > val) {
        return binarySearchVector(arr, val, start, mid - 1);
    }

    return binarySearchVector(arr, val, mid + 1, end);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    bool hasStraggler = arr.size() % 2 == 1;
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a < b) {
            std::swap(a, b);
        }
        pairs.push_back(std::make_pair(a, b));
    }

    mergePairsDeque(pairs);

    std::deque<int> sorted;
    std::deque<int> toInsert;

    for (size_t i = 0; i < pairs.size(); ++i) {
        sorted.push_back(pairs[i].first);
        toInsert.push_back(pairs[i].second);
    }

    insertSmallerElementsDeque(sorted, toInsert);

    if (hasStraggler) {
        int pos = binarySearchDeque(sorted, straggler, 0, sorted.size() - 1);
        sorted.insert(sorted.begin() + pos, straggler);
    }

    arr = sorted;
}

void PmergeMe::mergePairsDeque(std::deque<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1) {
        return;
    }

    size_t mid = pairs.size() / 2;
    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    mergePairsDeque(left);
    mergePairsDeque(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].first <= right[j].first) {
            pairs[k++] = left[i++];
        } else {
            pairs[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        pairs[k++] = left[i++];
    }

    while (j < right.size()) {
        pairs[k++] = right[j++];
    }
}

void PmergeMe::insertSmallerElementsDeque(std::deque<int>& sorted, std::deque<int>& toInsert) {
    for (size_t i = 0; i < toInsert.size(); ++i) {
        int val = toInsert[i];
        int pos = binarySearchDeque(sorted, val, 0, i);
        sorted.insert(sorted.begin() + pos, val);
    }
}

int PmergeMe::binarySearchDeque(const std::deque<int>& arr, int val, int start, int end) {
    if (start > end) {
        return start;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == val) {
        return mid;
    }

    if (arr[mid] > val) {
        return binarySearchDeque(arr, val, start, mid - 1);
    }

    return binarySearchDeque(arr, val, mid + 1, end);
}

void PmergeMe::sort() {
    fordJohnsonSortVector(_vector);
    fordJohnsonSortDeque(_deque);
}

const std::vector<int>& PmergeMe::getVector() const {
    return _vector;
}

const std::deque<int>& PmergeMe::getDeque() const {
    return _deque;
}