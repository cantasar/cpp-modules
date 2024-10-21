#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal*	cat = new Cat();
	const Animal*	dog = new Dog();
	const Animal*	animal = new Animal();

	delete	cat;
	delete	dog;
	delete	animal;

	cout << endl;
	cout << "----------Extra Subject request----------" << endl;
	cout << endl;

	int		len = 4;
	int		i = 0;
	Animal	*tab[len];

	while (i < (len / 2))
	{
		tab[i] = new Dog();
		tab[i]->makeSound();
		i++;
	}
	
	while (i < len)
	{
		tab[i] = new Cat();
		tab[i]->makeSound();
		i++;
	}

	while (--i >= 0)
		delete tab[i];
	
	return (0);
}
