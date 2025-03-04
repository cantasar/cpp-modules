#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
private:
	std::string _name;
public:
	Data();
	Data(const Data &obj);
	Data &operator=(const Data &obj);
	~Data();

	void setName(std::string name);
	std::string getName() const;
};

#endif