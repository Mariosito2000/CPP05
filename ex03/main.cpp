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
	Bureaucrat b("Manu", 2);
	Intern	Pinfloid;
	PresidentialPardonForm PP("jyurri");
	RobotomyRequestForm RR("daccvonza");
	ShrubberyCreationForm SC("pablofu");
	AForm * Form = Pinfloid.makeForm("ShrubberyCreationForm", "Josu");
	if (Form != 0)
	{
		b.signForm(*Form);
		Form->beSigned(b);
		//b.executeForm(*Form);
	}
	RR.beSigned(b);
	b.executeForm(RR);
	RR.execute(b);

	return (0);
}