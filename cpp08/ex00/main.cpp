#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec = {1, 2, 3, 4, 5};

	try
	{
		std::cout << "Finding 3: " << *easyfind(vec, 3) << std::endl;
		std::cout << "Finding 6: " << *easyfind(vec, 6) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}