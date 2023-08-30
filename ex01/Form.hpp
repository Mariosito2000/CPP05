#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:

	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_executeGrade;

public:

/*---CONS/DES---*/

	Form();
	~Form();

	Form(const Form &);
	Form(std::string, unsigned int, unsigned int);

/*---MEMBER FUNCTIONS---*/

	const std::string	getName() const;
	bool				getSigned() const;
	unsigned int	getSignGrade() const;
	unsigned int	getExecuteGrade() const;
	void				beSigned(const Bureaucrat &);

/*---OPERATORS---*/

	Form & operator = (const Form &);

/*---EXCEPTIONS---*/

	class	GradeTooHighException: public std::exception
	{
		public:
		const char *	what() const _NOEXCEPT;
	};

	class	GradeTooLowException: public std::exception
	{
		public:
		const char *	what() const _NOEXCEPT;
	};

};

std::ostream& operator<<(std::ostream& os, const Form &);

#endif