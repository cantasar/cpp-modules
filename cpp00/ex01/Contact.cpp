#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}


void Contact::set_contact(std::string f_n, std::string l_n, std::string n_n, std::string p_n, std::string d_s)
{
	this->first_name = f_n;
	this->last_name = l_n;
	this->nickname = n_n;
	this->phone_number = p_n;
	this->darkest_secret = d_s;
}

std::string Contact::get_name()
{
	return (this->first_name);
}
std::string Contact::get_last_name()
{
	return (this->last_name);
}
std::string Contact::get_nickname()
{
	return (this->nickname);
}
std::string Contact::get_phone_number()
{
	return (this->phone_number);
}
std::string Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}
