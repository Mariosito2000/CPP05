#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
std::cout << "\nPaco\n\n";
	Bureaucrat Paco("Francisco Javie", 51);
	std::cout << Paco;

std::cout << "\nForm _A\n\n";
	Form _A;
	std::cout << _A;

std::cout << "\nForm _B\n\n";
	Form _B("Permiso de conducir", 50, 100);
	std::cout << _B;

std::cout << "\nForm _E\n\n";
	try
	{
		Form _E("", -1, 2);
		std::cout << _E;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

std::cout << "\nTry sign _B\n\n";
	try
	{
		Paco.signForm(_B);
		_B.beSigned(Paco);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

std::cout << "\nTry again\n\n";
	Paco.increaseGrade();
	Paco.signForm(_B);
	_B.beSigned(Paco);
	std::cout << _B;

std::cout << "\nLast time I swear\n\n";
	Paco.signForm(_B);
	std::cout << Paco;
	std::cout << _B;

	return (0);
}