#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{

private:

	const std::string	_name;
	unsigned int		_grade;

public:

/*---CONS/DES---*/

	Bureaucrat();
	~Bureaucrat();

	Bureaucrat(const Bureaucrat &);
	Bureaucrat(std::string, unsigned int);

/*---MEMBER FUNCTIONS---*/

	std::string		getName() const;
	unsigned int	getGrade() const;
	void			increaseGrade();
	void			decreaseGrade();

/*---OPERATORS---*/

	Bureaucrat & operator = (const Bureaucrat &);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &);

#endif