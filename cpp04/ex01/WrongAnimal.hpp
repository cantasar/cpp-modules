#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
using std::string;
using std::cout;
using std::endl;

class WrongAnimal {
	protected:
		string type;
	public:
		WrongAnimal();
		WrongAnimal(string type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		~WrongAnimal();

		string getType() const;
		void makeSound() const;
};


#endif