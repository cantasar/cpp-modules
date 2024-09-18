#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();

	std::cout << "Type: " << j->getType() << " " << std::endl;
	std::cout << "Type: "  << i->getType() << " " << std::endl;

	std::cout << "----- AAnimal ------" << std::endl;
	std::cout << "Cat Sound: ";
	i->makeSound();
	std::cout << "Dog Sound: ";
	j->makeSound();

	return (0);
}