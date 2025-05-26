#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <ctime>  
#include <cctype>   

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
T PmergeMe::sort(T nums) {
	if (nums.size() < 2)
		return nums;

	if (nums.size() == 2)
		return sortPair(nums);

	T bigger;
	T smaller;
	processPairs(nums, bigger, smaller);
	
	T right = sort(bigger);
	T left = smaller;

	typename T::value_type keys;
	for (typename T::iterator it = right.begin(); it != right.end(); ++it)
		keys.push_back(it->front());

	size_t index = 1;
	int k = 1;
	int val = left[0].front();
	right.insert(right.begin(), left[0]);
	keys.insert(keys.begin(), val);

	while (keys.size() < nums.size()) {
		if (index == jacobsthal(k - 1)) {
			k += 1;
			index = jacobsthal(k);
		}
		if (index - 1 >= left.size()) {
			index -= 1;
			continue;
		}
		val = left[index - 1].front();

		typename T::value_type::iterator keyPos = std::lower_bound(keys.begin(), keys.end(), val);
		int ind = keyPos - keys.begin();

		typename T::iterator insertPos = right.begin();
		std::advance(insertPos, ind);
		right.insert(insertPos, left[index - 1]);
		keys.insert(keyPos, val);

		index -= 1;
	}

	return right;
}

#endif
