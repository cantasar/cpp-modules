#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    if (this != &src)
    {
        this->lst = src.lst;
        this->vector = src.vector;
    }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        this->lst = rhs.lst;
        this->vector = rhs.vector;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void handleError()
{
    std::cout << "Error\n";
    exit(1);
}

bool isNumeric(const std::string &str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!(*it >= '0' && *it <= '9'))
            return false;
    }
    return true;
}

int stringToInt(const std::string &str)
{
    if (str.empty())
        handleError();

    size_t i = 0;
    bool isNegative = false;

    if (str[i] == '-' || str[i] == '+')
    {
        isNegative = (str[i] == '-');
        ++i;
    }

    long num = 0;
    for (; i < str.length(); ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num = num * 10 + (str[i] - '0');
        }
        else
        {
            handleError();
        }
    }

    if (isNegative)
        num = -num;
    if (num > INT_MAX || num < INT_MIN)
        handleError();

    return static_cast<int>(num);
}

void PmergeMe::parseInput(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        std::string input(av[i]);
        if (!isNumeric(input))
            handleError();

        int value = stringToInt(input);
        if (value < 1)
            handleError();

        vector.push_back(value);
        lst.push_back(value);
    }
}

std::vector<int> PmergeMe::mergeVectors(const std::vector<int> &first, const std::vector<int> &second)
{
    std::vector<int> result;
    size_t i = 0, j = 0;

    while (i < first.size() && j < second.size())
    {
        if (first[i] <= second[j])
            result.push_back(first[i++]);
        else
            result.push_back(second[j++]);
    }

    while (i < first.size())
        result.push_back(first[i++]);
    while (j < second.size())
        result.push_back(second[j++]);

    return result;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return arr;

    size_t mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    left = sortVector(left);
    right = sortVector(right);

    return mergeVectors(left, right);
}

void PmergeMe::displayVector(std::string title, std::vector<int> &arr)
{
    std::cout << title;
    for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::list<int> PmergeMe::mergeLists(const std::list<int> &first, const std::list<int> &second)
{
    std::list<int> result;
    std::list<int>::const_iterator it1 = first.begin();
    std::list<int>::const_iterator it2 = second.begin();

    while (it1 != first.end() && it2 != second.end())
    {
        if (*it1 <= *it2)
        {
            result.push_back(*it1++);
        }
        else
        {
            result.push_back(*it2++);
        }
    }

    while (it1 != first.end())
        result.push_back(*it1++);
    while (it2 != second.end())
        result.push_back(*it2++);

    return result;
}

std::list<int> PmergeMe::sortList(std::list<int> &arr)
{
    if (arr.size() <= 1)
        return arr;

    std::list<int>::iterator mid = arr.begin();
    std::advance(mid, arr.size() / 2);

    std::list<int> left(arr.begin(), mid);
    std::list<int> right(mid, arr.end());

    left = sortList(left);
    right = sortList(right);

    return mergeLists(left, right);
}

void PmergeMe::displayList(std::string title, std::list<int> &arr)
{
    std::cout << title;
    for (std::list<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::execute(int ac, char **av)
{
    std::vector<int> sortedVector;
    std::list<int> sortedList;
    parseInput(ac, av);

    displayVector("Before: ", vector);

    std::clock_t startVector = std::clock();
    sortedVector = sortVector(vector);
    std::clock_t endVector = std::clock();
    double vectorTime = 1000.0 * (endVector - startVector) / CLOCKS_PER_SEC;

    displayVector("After: ", sortedVector);

    std::clock_t startList = std::clock();
    sortedList = sortList(lst);
    std::clock_t endList = std::clock();
    double listTime = 1000.0 * (endList - startList) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << sortedVector.size()
              << " elements with std::vector: " << vectorTime << " ms\n";
    std::cout << "Time to process a range of " << sortedList.size()
              << " elements with std::list: " << listTime << " ms\n";
}
