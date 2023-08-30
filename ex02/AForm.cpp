#include "AForm.hpp"
#include <iostream>

/*---CONS/DES---*/

AForm::AForm(): _name("God's blessing"), _signGrade(1), _executeGrade(1)
{
	std::cout << "Form default constructor called\n";
	_signed = false;
}

AForm::~AForm()
{
	std::cout << "Form default destructor called\n";
}

AForm::AForm(const AForm &a): _name(a.getName()), _signGrade(a.getSignGrade()), _executeGrade(a.getExecuteGrade())
{
	std::cout << "Form copy constructor called\n";
	_signed = a.getSigned();
}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int executeGrade): _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Form complex constructor called\n";
	if (_signGrade > 150 || _executeGrade > 150)
		throw (AForm::GradeTooLowException());
	else if (_signGrade < 1 || _executeGrade < 1)
		throw (AForm::GradeTooHighException());
	_signed = false;
}

/*---MEMBER FUNCTIONS---*/

const std::string	AForm::getName() const
{
	return (_name);
}

bool				AForm::getSigned() const
{
	return (_signed);
}

unsigned int	AForm::getSignGrade() const
{
	return (_signGrade);
}

unsigned int	AForm::getExecuteGrade() const
{
	return (_executeGrade);
}


void			AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw(AForm::GradeTooLowException());
	_signed = true;
}

void			AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecuteGrade())
		throw (AForm::GradeTooLowException());
	if (!getSigned())
		throw (AForm::FormNotSignedException());
	action();
}

/*---OPERATORS---*/

AForm & AForm::operator = (const AForm &a)
{
	_signed = a.getSigned();
	return (*this);
}

std::ostream& operator << (std::ostream& os, const AForm &a)
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

const char *	AForm::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Exception: Grade is too high for this form");
}

const char *	AForm::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Exception: Grade is too low for this form");
}

const char *	AForm::FormNotSignedException::what() const _NOEXCEPT
{
	return ("Exception: Form is not signed");
}