#include "PmergeMe.hpp"
#include <sys/time.h>

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

bool PmergeMe::isValidNumber(const std::string& s) {
    if (s.empty() || s[0] == '-') return false;
    for (size_t i = 0; i < s.length(); ++i) {
        if (!std::isdigit(s[i])) return false;
    }
    std::istringstream iss(s);
    long n;
    iss >> n;
    return (n >= 0 && n <= 2147483647);
}

void PmergeMe::checkInput(const std::vector<std::string>& input) {
    if (input.empty()) {
        throw std::invalid_argument("Error: No arguments provided");
    }
    for (size_t i = 0; i < input.size(); ++i) {
        if (!isValidNumber(input[i])) {
            throw std::invalid_argument("Error: Invalid number format");
        }
    }
}

void PmergeMe::setInput(const std::vector<std::string>& input) {
    checkInput(input);
    _vectorData.clear();
    _listData.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        int n = std::atoi(input[i].c_str());
        _vectorData.push_back(n);
        _listData.push_back(n);
    }
}

std::vector<size_t> PmergeMe::makeJacobsthal(size_t n) {
    std::vector<size_t> jac;
    if (n == 0) return jac;
    jac.push_back(1);
    if (n == 1) return jac;
    jac.push_back(1);
    size_t i = 2;
    while (true) {
        size_t next = jac[i-1] + 2 * jac[i-2];
        if (next > n) break;
        jac.push_back(next);
        ++i;
    }
    return jac;
}

void PmergeMe::insertSorted(std::vector<int>& arr, int val) {
    std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), val);
    arr.insert(pos, val);
}

void PmergeMe::insertSorted(std::list<int>& arr, int val) {
    std::list<int>::iterator pos = findPos(arr, val);
    arr.insert(pos, val);
}

std::list<int>::iterator PmergeMe::findPos(std::list<int>& arr, int val) {
    std::list<int>::iterator it = arr.begin();
    while (it != arr.end() && *it < val) {
        ++it;
    }
    return it;
}

std::vector<int> PmergeMe::mergeSortVec(std::vector<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return arr;
    std::vector<std::pair<int, int> > pairs;
    bool odd = (n % 2 == 1);
    int last = odd ? arr[n - 1] : 0;
    for (size_t i = 0; i < n - (odd ? 1 : 0); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a > b) pairs.push_back(std::make_pair(b, a));
        else pairs.push_back(std::make_pair(a, b));
    }
    std::vector<int> bigs;
    for (size_t i = 0; i < pairs.size(); ++i) {
        bigs.push_back(pairs[i].second);
    }
    if (bigs.size() > 1) {
        bigs = mergeSortVec(bigs);
    }
    std::vector<int> mainArr = bigs;
    std::vector<int> smalls;
    for (size_t i = 0; i < pairs.size(); ++i) {
        smalls.push_back(pairs[i].first);
    }
    if (!smalls.empty()) {
        mainArr.insert(mainArr.begin(), smalls[0]);
        std::vector<size_t> jac = makeJacobsthal(smalls.size());
        std::vector<bool> done(smalls.size(), false);
        done[0] = true;
        for (size_t j = 0; j < jac.size(); ++j) {
            size_t idx = jac[j] - 1;
            if (idx < smalls.size() && !done[idx]) {
                insertSorted(mainArr, smalls[idx]);
                done[idx] = true;
            }
            if (j > 0) {
                for (size_t k = jac[j] - 1; k > jac[j-1] - 1; --k) {
                    if (k < smalls.size() && !done[k]) {
                        insertSorted(mainArr, smalls[k]);
                        done[k] = true;
                    }
                }
            }
        }
        for (size_t i = 1; i < smalls.size(); ++i) {
            if (!done[i]) {
                insertSorted(mainArr, smalls[i]);
            }
        }
    }
    if (odd) {
        insertSorted(mainArr, last);
    }
    return mainArr;
}

std::list<int> PmergeMe::mergeSortList(std::list<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return arr;
    std::vector<int> tmp(arr.begin(), arr.end());
    std::vector<int> res = mergeSortVec(tmp);
    std::list<int> out(res.begin(), res.end());
    return out;
}

void PmergeMe::sortVec(std::vector<int>& arr) {
    arr = mergeSortVec(arr);
}

void PmergeMe::sortList(std::list<int>& arr) {
    arr = mergeSortList(arr);
}

void PmergeMe::printArr(const std::vector<int>& arr, const std::string& txt) {
    std::cout << txt;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

void PmergeMe::sort() {
    printArr(_vectorData, "Before: ");
    clock_t t1 = clock();
    sortVec(_vectorData);
    clock_t t2 = clock();
    double tVec = (double)(t2 - t1) / CLOCKS_PER_SEC * 1000000;
    t1 = clock();
    sortList(_listData);
    t2 = clock();
    double tList = (double)(t2 - t1) / CLOCKS_PER_SEC * 1000000;
    printArr(_vectorData, "After:  ");
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << std::fixed << tVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _listData.size() 
              << " elements with std::list   : " << std::fixed << tList << " us" << std::endl;
}

