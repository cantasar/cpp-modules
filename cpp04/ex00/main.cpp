#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	cout << j->getType() << " " << endl;
	cout << i->getType() << " " << endl; 
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();

	cout << endl << "------WrongAnimal------" << endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongCat();

	cout << j2->getType() << " " << endl;
	j2->makeSound();
	meta2->makeSound();

	return 0;
}