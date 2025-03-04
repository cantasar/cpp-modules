#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void) {
	Base *base;
	
	int random = rand() % 3;
	std::cout << "Random number: " << random << std::endl;
	if (random == 0)
		base = new A;
	else if(random == 1)
		base = new B;
	else
		base = new C;
	return (base);
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "The object type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The object type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The object type: C" << std::endl;
}

void identify(Base& p){
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "The object type: A" << std::endl;
	}
	catch (std::bad_cast &bc) {}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "The object type: B" << std::endl;
	}
	catch (std::bad_cast &bc) {}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "The object type: C" << std::endl;
	}
	catch (std::bad_cast &bc) {}
}