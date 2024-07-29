#include "Phonebook.hpp"
#include "Contact.hpp"


#include <iomanip>

PhoneBook::PhoneBook()
{
	this->id = 0;
	this->size = 0;
}

int is_digit(std::string s)
{
	int i = -1;
	while(s[++i])
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	return (1);
}

void PhoneBook::add()
{
	std::string f_n, l_n, n_n, p_n, d_s;

	while (true)
	{
		std::cout << "First Name: ";
		std::getline(std::cin, f_n);
		if (f_n.empty())
			continue;
		std::cout << "Last Name: ";
		std::getline(std::cin, l_n);
		if (l_n.empty())
			continue;
		std::cout << "Nick Name: ";
		std::getline(std::cin, n_n);
		if (n_n.empty())
			continue;
		std::cout << "Phone Number: ";
		std::getline(std::cin, p_n);
		if (p_n.empty())
			continue;
		if (!is_digit(p_n))
			continue;
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, d_s);
		if (d_s.empty())
			continue;
		this->contacts[this->id++].set_contact(f_n,l_n,n_n, p_n, d_s);
		if (this->id == 8)
			this->id = 0;
		this->size++;
		break;
	}
}

void PhoneBook::search()
{
	std::cout << std::endl << "     index|      name|  lastname|  nickname|" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		if (this->contacts[i].get_name().length() > 10)
			std::cout << std::setw(10) << this->contacts[i].get_name().substr(0,9) + "." << "|";
		else
			std::cout << std::setw(10) << this->contacts[i].get_name() << "|";

		if (this->contacts[i].get_last_name().length() > 10)
			std::cout << std::setw(10) << this->contacts[i].get_last_name().substr(0,9) + "." << "|";
		else
			std::cout << std::setw(10) << this->contacts[i].get_last_name() << "|";

		if (this->contacts[i].get_nickname().length() > 10)
			std::cout << std::setw(10) << this->contacts[i].get_nickname().substr(0,9) + "." << "|" << std::endl;
		else
			std::cout << std::setw(10) << this->contacts[i].get_nickname() << "|" << std::endl;
	}

	std::string input;

	while (1)
	{
		int index;
		std::cout << "Please write index that you want to show." << std::endl;
        if (std::cin >> input)
		{
            if (!is_digit(input))
                continue;
            index = std::atoi(input.c_str());
            if (index >=0 && index <=7 && index < this->size)
			{
				std::cout << "Index: " << index << std::endl;
				std::cout << "First Name: " << this->contacts[index].get_name() << std::endl;
				std::cout << "Last Name: " << this->contacts[index].get_last_name() << std::endl;
				std::cout << "Nick Name: " << this->contacts[index].get_nickname() << std::endl;
				break;
			}
			else
			{
				std::cout << "Invalid input. Please enter a valid index." << std::endl;
				break;
			}
		}
	}
}
