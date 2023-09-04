#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{

public:

/*---CONS/DES---*/

	Intern();
	~Intern();

	Intern(const Intern &);

/*---MEMBER FUNCTIONS---*/

	AForm *	makeForm(std::string, std::string);

/*---OPERATORS---*/

	Intern & operator = (const Intern &);

};

#endif