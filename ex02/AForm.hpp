#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:

	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_executeGrade;

public:

/*---CONS/DES---*/

	AForm();
	virtual ~AForm();

	AForm(const AForm &);
	AForm(std::string name, unsigned int signGrade, unsigned int executeGrade);

/*---MEMBER FUNCTIONS---*/

	const std::string	getName() const;
	bool				getSigned() const;
	unsigned int		getSignGrade() const;
	unsigned int		getExecuteGrade() const;
	void				beSigned(const Bureaucrat &);
	void				execute(const Bureaucrat & executor) const;
	virtual void		action() const = 0;

/*---OPERATORS---*/

	AForm &	operator = (const AForm &);

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

	class	FormNotSignedException: public std::exception
	{
		public:
		const char *	what() const _NOEXCEPT;
	};

};

std::ostream& operator<<(std::ostream& os, const AForm &);

#endif