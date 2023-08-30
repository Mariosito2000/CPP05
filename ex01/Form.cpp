#include "Form.hpp"
#include <iostream>

/*---CONS/DES---*/

Form::Form(): _name("God's blessing"), _signGrade(1), _executeGrade(1)
{
	std::cout << "Form default constructor called\n";
	_signed = false;
}

Form::~Form()
{
	std::cout << "Form default destructor called\n";
}

Form::Form(const Form &a): _name(a.getName()), _signGrade(a.getSignGrade()), _executeGrade(a.getExecuteGrade())
{
	std::cout << "Form copy constructor called\n";
	_signed = a.getSigned();
}

Form::Form(std::string name, unsigned int signGrade, unsigned int executeGrade): _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Form complex constructor called\n";
	if (_signGrade > 150 || _executeGrade > 150)
		throw (Form::GradeTooLowException());
	else if (_signGrade < 1 || _executeGrade < 1)
		throw (Form::GradeTooHighException());
	_signed = false;
}

/*---MEMBER FUNCTIONS---*/

const std::string	Form::getName() const
{
	return (_name);
}

bool				Form::getSigned() const
{
	return (_signed);
}

unsigned int	Form::getSignGrade() const
{
	return (_signGrade);
}

unsigned int	Form::getExecuteGrade() const
{
	return (_executeGrade);
}

void			Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw(Form::GradeTooLowException());
	_signed = true;
}

/*---OPERATORS---*/

Form & Form::operator = (const Form &a)
{
	_signed = a.getSigned();
	return (*this);
}

std::ostream& operator << (std::ostream& os, const Form &a)
{
	if (a.getSigned())
		std::cout << a.getName() << " form needs a " << a.getSignGrade()
		<< " grade to be signed and a " << a.getExecuteGrade()
		<< " grade to be executed, it's current state is signed\n";
	else
		std::cout << a.getName() << " form needs a " << a.getSignGrade()
		<< " grade to be signed and a " << a.getExecuteGrade()
		<< " grade to be executed, it's current state is not signed\n";
	return (os);
}

/*---EXCEPTIONS---*/

const char *	Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Exception: Grade is too high");
}

const char *	Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Exception: Grade is too low");
}