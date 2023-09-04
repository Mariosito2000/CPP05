#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	
	static int	_randomizer;
	std::string	_target;

public:

/*---CONS/DES---*/

	RobotomyRequestForm();
	~RobotomyRequestForm();

	RobotomyRequestForm(const RobotomyRequestForm &);
	RobotomyRequestForm(std::string);

/*---MEMBER FUNCTIONS---*/

	void		action() const;

/*---OPERATORS---*/

	RobotomyRequestForm & operator = (const RobotomyRequestForm &);

};

#endif