#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int	main()
{
	//std::cout << ent;
	Bureaucrat b("Manu", 2);

	std::cout << "\nSHRUBBERY\n\n";
	ShrubberyCreationForm SC("pablofu");
	try
	{
		b.executeForm(SC);
	}
	catch(const AForm::FormNotSignedException& e)
	{
		std::cerr << e.what() << '\n';
	}
	b.signForm(SC);
	b.executeForm(SC);

	std::cout << "\nP.PARDON\n\n";
	PresidentialPardonForm PP("jyurri");
	b.signForm(PP);
	b.signForm(PP);
	b.executeForm(PP);

	std::cout << "\nROBOTOMY\n\n";
	RobotomyRequestForm RR("daccvonza");
	b.signForm(RR);
	std::cout << "\n";
	b.executeForm(RR);
	std::cout << "\n";
	b.executeForm(RR);
	std::cout << "\n";
	b.executeForm(RR);
	std::cout << "\n";
	b.executeForm(RR);
	std::cout << "\n";
	b.executeForm(RR);
	std::cout << "\n";
	
	return (0);
}