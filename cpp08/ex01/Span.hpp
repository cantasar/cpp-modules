#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>


class Span
{
private:
		unsigned int _size;
		std::vector<int> _numbers;
public:
	Span();
	Span(unsigned int n);
	Span(const Span &obj);
	Span &operator = (const Span &obj);
	~Span();

	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;

	std::vector<int> getList() const;

	template<typename Iterator>
	void addNumbers(Iterator begin, Iterator end) {
		if (std::distance(begin, end) + _numbers.size() > _size)
			throw ContainerFullException();
		_numbers.insert(_numbers.end(), begin, end);
	}

	class ContainerFullException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif