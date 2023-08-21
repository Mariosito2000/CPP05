#include "Bureaucrat.hpp"

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
	std::cout << "Bureaucrat name +  constructor called\n";
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
	//exceptions
}

void			Bureaucrat::decreaseGrade()
{
	//exceptions
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