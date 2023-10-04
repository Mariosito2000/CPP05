#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main()
{
	//std::cout << ent;
	Bureaucrat b("Manue", 1);
	Intern	Pinfloid;

	std::cout << "\nMake form\n\n";
	AForm * SCF = Pinfloid.makeForm("ShrubberyCreationForm", "Josu");
	if (SCF != 0)
	{
		b.signForm(*SCF);
		b.executeForm(*SCF);
	}
std::cout << "\n";
	AForm * PP = Pinfloid.makeForm("PresidentialPardonForm", "Joseph");
	if (PP != 0)
	{
		b.signForm(*PP);
		b.executeForm(*PP);
	}
std::cout << "\n";
	AForm * RR = Pinfloid.makeForm("RobotomyRequestForm", "Hezú");
	if (RR != 0)
	{
		b.signForm(*RR);
		b.executeForm(*RR);
	}
	std::cout << "\nEnd\n";

	return (0);
}