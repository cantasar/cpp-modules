#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

const char* NotFound::what() const throw() {
    return "This value is not in the container!";
}

#endif