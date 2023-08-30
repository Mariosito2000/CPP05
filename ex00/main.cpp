#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{

std::cout << "\nA\n\n";

	Bureaucrat a;
	std::cout << a;
	std::cout << "\nTry decrease\n\n";
	try{
		a.decreaseGrade();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << a;

std::cout << "\nB\n\n";

	Bureaucrat b("Berv", 2);
	std::cout << b;
	std::cout << "\nIncrease\n\n";
	b.increaseGrade();
	std::cout << b;
	std::cout << "\nTry increase\n\n";
	try
	{
		b.increaseGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << b << "\n";
	std::cout << "\nDecrease\n\n";
	b.decreaseGrade();
	std::cout << b << "\n";

std::cout << "\nV\n\n";

	Bureaucrat v(b);
	std::cout << v;
	std::cout << "\nDecrease\n\n";
	v.decreaseGrade();
	std::cout << v;
	std::cout << "\nIncrease\n\n";
	v.increaseGrade();
	std::cout << v;
	std::cout << "\nIncrease\n\n";
	v.increaseGrade();
	std::cout << v;
	std::cout << "\nTry increase\n\n";
	try
	{
		v.increaseGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << v;

std::cout << "\nE\n\n";

	try
	{
		Bureaucrat e("Error", 1234);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << "\n";
	}

	return (0);
}