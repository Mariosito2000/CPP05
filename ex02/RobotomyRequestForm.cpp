#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <sys/time.h>

/*---CONS/DES---*/

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called\n";
	_target = "Luca";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a): AForm(a)
{
	std::cout << "RobotomyRequestForm copy constructor called\n";
	_target = a._target;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45)
{
	std::cout << "RobotomyRequestForm target constructor called\n";
	_target = target;
}

/*---MEMBER FUNCTIONS---*/

void		RobotomyRequestForm::action() const
{
	std::cout << "** Drilling noises... **\n";
	timeval	time;
	gettimeofday(&time, NULL);
	if (time.tv_usec % 2 == 1)
		std::cout << _target << " has been robotomized\n";
	else
		std::cout << "Robotomy failed\n";
}

/*---OPERATORS---*/

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm &a)
{
	_target = a._target;
	return (*this);
}