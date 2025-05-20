#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <climits>

class PmergeMe {
    private:
        std::list<int> lst;
        std::vector<int> vector;

        std::vector<int> mergeVectors(const std::vector<int> &first, const std::vector<int> &second);
        std::vector<int> sortVector(std::vector<int> &arr);

        std::list<int> mergeLists(const std::list<int> &first, const std::list<int> &second);
        std::list<int> sortList(std::list<int> &arr);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &rhs);
        ~PmergeMe();

        void parseInput(int ac, char **av);
        void execute(int ac, char **av);

        void displayVector(std::string title, std::vector<int> &arr);
        void displayList(std::string title, std::list<int> &arr);
};

#endif