#include "Intern.hpp"
#include <string>
#include <iostream>

/*---CONS/DES---*/

Intern::Intern()
{
	std::cout << "Intern default constructor called\n";
}

Intern::~Intern()
{
	std::cout << "Intern default destructor called\n";
}

Intern::Intern(const Intern &a)
{
	(void)a;
	std::cout << "Intern copy constructor called\n";
}

/*---MEMBER FUNCTIONS---*/

AForm *	Intern::makeForm(std::string formType, std::string target)
{
	AForm	*(*Form[3])(std::string) = {(& AForm::makeShrubberyCreationForm),
										(& AForm::makeRobotomyRequestForm),
										(& AForm::makePresidentialPardonForm)};
	std::string	types[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (formType.compare(types[i]) == 0)
		{
			std::cout << "Intern creates " << formType << "\n";
			return (Form[i](target));
		}
	}
	std::cout << "That form does not match any of the oficial form types, try \"ShrubberyCreationForm\", \"RobotomyRequestForm\" or \"PresidentialPardonForm\"\n";
	return (0);
}

/*---OPERATORS---*/

Intern & Intern::operator = (const Intern &a)
{
	(void)	a;
	return (*this);
}