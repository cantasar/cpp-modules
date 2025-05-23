#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stdexcept>

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::list<int> _listData;
    
    std::vector<size_t> makeJacobsthal(size_t n);
    
    void sortVec(std::vector<int>& arr);
    std::vector<int> mergeSortVec(std::vector<int>& arr);
    void insertSorted(std::vector<int>& arr, int val);
    
    void sortList(std::list<int>& arr);
    std::list<int> mergeSortList(std::list<int>& arr);
    void insertSorted(std::list<int>& arr, int val);
    std::list<int>::iterator findPos(std::list<int>& arr, int val);
    
    bool isValidNumber(const std::string& s);
    void checkInput(const std::vector<std::string>& input);
    void printArr(const std::vector<int>& arr, const std::string& txt);
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void setInput(const std::vector<std::string>& input);
    void sort();
};

#endif