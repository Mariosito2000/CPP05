#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:

	std::string	_target;

public:

/*---CONS/DES---*/

	PresidentialPardonForm();
	~PresidentialPardonForm();

	PresidentialPardonForm(const PresidentialPardonForm &);
	PresidentialPardonForm(std::string);

/*---MEMBER FUNCTIONS---*/

	void		action() const;

/*---OPERATORS---*/

	PresidentialPardonForm & operator = (const PresidentialPardonForm &);

};

#endif