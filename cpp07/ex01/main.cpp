#include "iter.hpp"

template <typename T>
void print(T &x)
{
    x += 10;
    std::cout << x << std::endl;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

    std::cout << "intArray: " << std::endl;
    iter(intArray, 5, print);

    std::cout << "charArray: " << std::endl;
    iter(charArray, 5, print);

    std::cout << "floatArray: " << std::endl;
    iter(floatArray, 5, print);

    return 0;
}