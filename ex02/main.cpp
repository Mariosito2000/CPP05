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
	PresidentialPardonForm PP("jyurri");
	RobotomyRequestForm RR("daccvonza");
	ShrubberyCreationForm SC("pablofu");
	RR.beSigned(b);
	b.executeForm(RR);
	b.executeForm(RR);
	b.executeForm(RR);
	b.executeForm(RR);
	b.executeForm(RR);
	
	return (0);
}