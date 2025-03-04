#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	srand(time(NULL));

    Base* obj1 = generate();
    Base* obj2 = generate();
    Base* obj3 = generate();
    Base* obj4 = generate();
    Base* obj5 = generate();


    identify(obj1);
    identify(obj2);
    identify(obj3);
    identify(obj4);
    identify(obj5);

    std::cout << std::endl;

    identify(*obj1);
    identify(*obj2);
    identify(*obj3);
    identify(*obj4);
    identify(*obj5);

    delete obj1;
    delete obj2;
    delete obj3;
    delete obj4;
    delete obj5;

    return 0;
}