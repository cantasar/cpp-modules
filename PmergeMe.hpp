#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <climits>

class PmergeMe
{
private:
	static size_t jacobsthal(int k);

	template<typename T>
	static T sortPair(T nums);

	template<typename T>
	static void processPairs(T& nums, T& bigger, T& smaller);

	template<typename T>
	static T sort(T nums);

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

	void sort(int argc, char* argv[]);
};

template<typename T>
T PmergeMe::sortPair(T nums) {
	typename T::iterator it = nums.begin();
	typename T::iterator next = it;
	++next;
	
	if (it->front() > next->front())
		std::iter_swap(it, next);
	return nums;
}

template<typename T>
void PmergeMe::processPairs(T& nums, T& bigger, T& smaller) {
	typename T::iterator it = nums.begin();

	for (size_t i = 0; i < nums.size() - 1; i += 2) {
		typename T::iterator first = it + i;
		typename T::iterator second = first + 1;
		
		if (first->front() > second->front()) {
			first->insert(first->end(), second->begin(), second->end());
			bigger.push_back(*first);
			smaller.push_back(*second);
		} else {
			second->insert(second->end(), first->begin(), first->end());
			bigger.push_back(*second);
			smaller.push_back(*first);
		}
	}

	if (nums.size() % 2)
		smaller.push_back(*(--nums.end()));
}

template<typename T>
T PmergeMe::sort(T sequence) {
    if (sequence.size() < 2)
        return sequence;

    if (sequence.size() == 2)
        return sortPair(sequence);

    T largerElements;
    T smallerElements;
    processPairs(sequence, largerElements, smallerElements);
    
    T sortedLarger = sort(largerElements);
    T pendingElements = smallerElements;

    typename T::value_type sortedKeys;
    for (typename T::iterator it = sortedLarger.begin(); it != sortedLarger.end(); ++it)
        sortedKeys.push_back(it->front());

    size_t currentIndex = 1;
    int jacobsthalStep = 1;
    int currentValue = pendingElements[0].front();
    sortedLarger.insert(sortedLarger.begin(), pendingElements[0]);
    sortedKeys.insert(sortedKeys.begin(), currentValue);

    while (sortedKeys.size() < sequence.size()) {
        if (currentIndex == jacobsthal(jacobsthalStep - 1)) {
            jacobsthalStep += 1;
            currentIndex = jacobsthal(jacobsthalStep);
        }
        if (currentIndex - 1 >= pendingElements.size()) {
            currentIndex -= 1;
            continue;
        }
        currentValue = pendingElements[currentIndex - 1].front();

        typename T::value_type::iterator insertPosition = std::lower_bound(sortedKeys.begin(), sortedKeys.end(), currentValue);
        int insertIndex = insertPosition - sortedKeys.begin();

        typename T::iterator elementPosition = sortedLarger.begin();
        std::advance(elementPosition, insertIndex);
        sortedLarger.insert(elementPosition, pendingElements[currentIndex - 1]);
        sortedKeys.insert(insertPosition, currentValue);

        currentIndex -= 1;
    }

    return sortedLarger;
}

#endif
