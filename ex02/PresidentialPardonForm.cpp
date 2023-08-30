#include "PresidentialPardonForm.hpp"
#include <iostream>

/*---CONS/DES---*/

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called\n";
	_target = "Luca";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a): AForm(a)
{
	std::cout << "PresidentialPardonForm copy constructor called\n";
	_target = a._target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon", 25, 5)
{
	std::cout << "PresidentialPardonForm target constructor called\n";
	_target = target;
}

/*---MEMBER FUNCTIONS---*/

void		PresidentialPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}

/*---OPERATORS---*/

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm &a)
{
	_target = a._target;
	return (*this);
}