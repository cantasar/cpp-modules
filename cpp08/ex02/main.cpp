#include "MutantStack.hpp"
#include <iostream>
#include <string>

int main()
{
	{
		std::cout << "Test 1 - Subject" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(-42);

		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "---------------" << std::endl << std::endl;
	}

	{
		std::cout << "Test 2 - String Stack" << std::endl;
		MutantStack<std::string> mstack_str;

		mstack_str.push("hello");
		mstack_str.push("world");
		mstack_str.push("cpp");

		std::cout << "Top: " << mstack_str.top() << std::endl;

		mstack_str.pop();

		std::cout << "Size after pop: " << mstack_str.size() << std::endl;

		mstack_str.push("mutant");
		mstack_str.push("stack");

		MutantStack<std::string>::iterator it_str = mstack_str.begin();
		MutantStack<std::string>::iterator ite_str = mstack_str.end();

		std::cout << "Stack elements:" << std::endl;
		for (; it_str != ite_str; ++it_str)
			std::cout << *it_str << std::endl;

		std::cout << "---------------" << std::endl << std::endl;
	}

	{
		std::cout << "Test 3 - Empty Stack" << std::endl;
		MutantStack<double> mstack_empty;

		std::cout << "Is empty? " << (mstack_empty.empty() ? "Yes" : "No") << std::endl;
		std::cout << "Size: " << mstack_empty.size() << std::endl;

		std::cout << "---------------" << std::endl << std::endl;
	}

	return 0;
}
