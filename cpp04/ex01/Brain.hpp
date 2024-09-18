#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Brain {
	private:
		string ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();
};

#endif