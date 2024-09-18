#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "Brain.hpp"


class Animal {
	protected:
		string type;
	public:
		Animal();
		Animal(string type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		~Animal();
		string getType() const;
		virtual void makeSound() const ;
};




#endif