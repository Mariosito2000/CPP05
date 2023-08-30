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
	try
	{
		RR.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	RR.beSigned(b);
	b.executeForm(RR);
	
	return (0);
}