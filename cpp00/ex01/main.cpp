#include "Phonebook.hpp"
#include "Contact.hpp"

#include <string>
#include <iostream>
#include <iomanip>

int main()
{
	PhoneBook myPhone;
	std::string input;
	while(1)
	{
		std::cout << std::endl << "Please Enter a command: ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, input);
		if(input == "ADD")
			myPhone.add();
		else if (input == "SEARCH")
			myPhone.search();
		else if (input == "EXIT")
			return (0);
	}

	return (0);
}

