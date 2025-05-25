#include "PmergeMe.hpp"
#include <sys/time.h>
#include <algorithm>
#include <iterator>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _listData(other._listData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _listData = other._listData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string& str) {
    if (str.empty() || str[0] == '-') return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }
    long number;
    std::istringstream iss(str);
    iss >> number;
    return (number >= 0 && number <= 2147483647);
}

void PmergeMe::checkInput(const std::vector<std::string>& input) {
    if (input.empty()) 
        throw std::invalid_argument("Error: No arguments");
    for (size_t i = 0; i < input.size(); ++i) {
        if (!isValidNumber(input[i])) throw std::invalid_argument("Error: Invalid number");
    }
}

void PmergeMe::setInput(const std::vector<std::string>& input) {
    checkInput(input);
    _vectorData.clear();
    _listData.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        int number = std::atoi(input[i].c_str());
        _vectorData.push_back(number);
        _listData.push_back(number);
    }
}

std::vector<size_t> PmergeMe::makeJacobsthal(size_t size) {
    std::vector<size_t> seq;
    if (size == 0) return seq;
    seq.push_back(1);
    if (size == 1) return seq;
    seq.push_back(1);
    for (size_t i = 2;; ++i) {
        size_t next = seq[i-1] + 2 * seq[i-2];
        if (next > size) break;
        seq.push_back(next);
    }
    return seq;
}

void PmergeMe::insertSorted(std::vector<int>& arr, int value) {
    arr.insert(std::lower_bound(arr.begin(), arr.end(), value), value);
}

void PmergeMe::insertSorted(std::list<int>& arr, int value) {
    arr.insert(findPos(arr, value), value);
}

std::list<int>::iterator PmergeMe::findPos(std::list<int>& arr, int value) {
    std::list<int>::iterator it = arr.begin();
    while (it != arr.end() && *it < value)
        ++it;
    return it;
}

std::vector<int> PmergeMe::mergeSortVec(std::vector<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) 
        return arr;
    std::vector<std::pair<int, int> > pairs;
    bool extra = (n % 2 == 1);
    int last = 0;
    if (extra) {
        last = arr[n - 1];
    }
    size_t loopEnd = n;
    if (extra) {
        loopEnd = n - 1;
    }
    for (size_t i = 0; i < loopEnd; i += 2) {
        int a = arr[i], b = arr[i + 1];
        if (a > b) {
            pairs.push_back(std::make_pair(b, a));
        } else {
            pairs.push_back(std::make_pair(a, b));
        }
    }
    std::vector<int> bigs;
    std::vector<int> smalls;
    for (size_t i = 0; i < pairs.size(); ++i) {
        smalls.push_back(pairs[i].first);
        bigs.push_back(pairs[i].second);
    }
    if (bigs.size() > 1) bigs = mergeSortVec(bigs);
    std::vector<int> result = bigs;
    if (!smalls.empty()) {
        result.insert(result.begin(), smalls[0]);
        std::vector<size_t> jacob = makeJacobsthal(smalls.size());
        std::vector<bool> inserted(smalls.size(), false);
        inserted[0] = true;
        for (size_t j = 0; j < jacob.size(); ++j) {
            size_t index = jacob[j] - 1;
            if (index < smalls.size() && !inserted[index]) {
                insertSorted(result, smalls[index]);
                inserted[index] = true;
            }
            if (j > 0) {
                for (size_t k = jacob[j] - 1; k > jacob[j-1] - 1; --k) {
                    if (k < smalls.size() && !inserted[k]) {
                        insertSorted(result, smalls[k]);
                        inserted[k] = true;
                    }
                }
            }
        }
        for (size_t i = 1; i < smalls.size(); ++i) {
            if (!inserted[i]) insertSorted(result, smalls[i]);
        }
    }
    if (extra) insertSorted(result, last);
    return result;
}

std::list<int> PmergeMe::mergeSortList(std::list<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return arr;
    std::list<std::pair<int, int> > pairs;
    bool extra = (n % 2 == 1);
    int last = 0;
    if (extra) {
        last = *std::prev(arr.end());
    }
    std::list<int>::iterator it = arr.begin();
    size_t loopEnd = n;
    if (extra) {
        loopEnd = n - 1;
    }
    for (size_t i = 0; i < loopEnd; i += 2) {
        int a = *it; ++it;
        int b = *it; ++it;
        if (a > b) {
            pairs.push_back(std::make_pair(b, a));
        } else {
            pairs.push_back(std::make_pair(a, b));
        }
    }
    std::list<int> bigs, smalls;
    for (std::list<std::pair<int, int> >::iterator pit = pairs.begin(); pit != pairs.end(); ++pit) {
        smalls.push_back(pit->first);
        bigs.push_back(pit->second);
    }
    if (bigs.size() > 1) bigs = mergeSortList(bigs);
    std::list<int> result = bigs;
    if (!smalls.empty()) {
        result.insert(result.begin(), smalls.front());
        std::vector<size_t> jacob = makeJacobsthal(smalls.size());
        std::vector<bool> inserted(smalls.size(), false);
        inserted[0] = true;
        std::list<int>::iterator sml;
        for (size_t j = 0; j < jacob.size(); ++j) {
            size_t index = jacob[j] - 1;
            if (index < smalls.size() && !inserted[index]) {
                sml = smalls.begin(); std::advance(sml, index);
                insertSorted(result, *sml);
                inserted[index] = true;
            }
            if (j > 0) {
                for (size_t k = jacob[j] - 1; k > jacob[j-1] - 1; --k) {
                    if (k < smalls.size() && !inserted[k]) {
                        sml = smalls.begin(); std::advance(sml, k);
                        insertSorted(result, *sml);
                        inserted[k] = true;
                    }
                }
            }
        }
        for (size_t i = 1; i < smalls.size(); ++i) {
            if (!inserted[i]) {
                sml = smalls.begin(); std::advance(sml, i);
                insertSorted(result, *sml);
            }
        }
    }
    if (extra) insertSorted(result, last);
    return result;
}

void PmergeMe::sortVec(std::vector<int>& arr) {
    arr = mergeSortVec(arr);
}

void PmergeMe::sortList(std::list<int>& arr) {
    arr = mergeSortList(arr);
}

void PmergeMe::printArr(const std::vector<int>& arr, const std::string& label) {
    std::cout << label;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

void PmergeMe::sort() {
    printArr(_vectorData, "Before: ");
    clock_t start = clock();
    sortVec(_vectorData);
    clock_t end = clock();
    double vecTime = (double)(end - start) / CLOCKS_PER_SEC * 10000;
    start = clock();
    sortList(_listData);
    end = clock();
    double listTime = (double)(end - start) / CLOCKS_PER_SEC * 10000;
    printArr(_vectorData, "After:  ");
    std::cout << "Time to process a range of " << _vectorData.size()
              << " elements with std::vector : " << std::fixed << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _listData.size()
              << " elements with std::list   : " << std::fixed << listTime << " us" << std::endl;
}

