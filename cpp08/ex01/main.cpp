#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Test 1 - Subject:" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << std::endl << "Test 2 - Iterator:" << std::endl;
		Span sp2 = Span(1000);
		std::vector<int> numbers;
		for (int i = 0; i < 1000; i++) {
			numbers.push_back(i);
		}
		sp2.addNumbers(numbers.begin(), numbers.end());
		
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

		std::cout << std::endl << "Test 3 - Exception:" << std::endl;
		Span sp3 = Span(5);
		std::vector<int> tooManyNumbers = {1, 2, 3, 4, 5, 6};
		sp3.addNumbers(tooManyNumbers.begin(), tooManyNumbers.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
