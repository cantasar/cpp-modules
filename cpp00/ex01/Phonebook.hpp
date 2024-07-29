#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int id;
        int size;
	public:
		PhoneBook();
		void add(void);
		void search(void);
};

#endif