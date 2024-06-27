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
		int  getSize(void);
		void add(void);
		void search(void);
		void exit(void);
		void show_variables(void);
};

#endif