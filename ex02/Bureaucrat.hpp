#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include "AForm.hpp"

class AForm;

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
	void			signForm(const AForm &);
	void			executeForm(AForm const & form);

/*---OPERATORS---*/

	Bureaucrat & operator = (const Bureaucrat &);

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat &);

#endif