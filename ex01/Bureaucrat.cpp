#include "Bureaucrat.hpp"
#include <iostream>

/*---CONS/DES---*/

Bureaucrat::Bureaucrat(): _name("Joe")
{
	std::cout << "Bureaucrat default constructor called\n";
	_grade = 150;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &a): _name(a.getName())
{
	std::cout << "Bureaucrat copy constructor called\n";
	_grade = a.getGrade();
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name)
{
	std::cout << "Bureaucrat complex constructor called\n";
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade = grade;
}

/*---MEMBER FUNCTIONS---*/

std::string		Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void			Bureaucrat::increaseGrade()
{
	if (_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade--;
}

void			Bureaucrat::decreaseGrade()
{
	if (_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade++;
}

void			Bureaucrat::signForm(Form &form)
{
	if (form.getSigned() == true)
	{
		std::cout << _name << " couldn’t sign " << form.getName() << " because it's already been signed.\n";
		return;
	}
	try
	{
		form.beSigned(*this);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << _name << " couldn’t sign " << form.getName() << " because bureaucrat grade is too low\n";
		return;
	}
	std::cout << _name << " signed " << form.getName() << "\n";
}

/*---OPERATORS---*/

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &a)
{
	this->_grade = a.getGrade();
	return (*this);
}

std::ostream& operator << (std::ostream& os, const Bureaucrat &a)
{
	std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << ".\n";
	return (os);
}

/*---EXCEPTIONS---*/

const char *	Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Exception: Grade is too high");
}

const char *	Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Exception: Grade is too low");
}