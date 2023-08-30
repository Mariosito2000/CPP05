#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

/*---CONS/DES---*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
	_target = "Luca";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a): AForm(a)
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
	_target = a._target;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137)
{
	std::cout << "ShrubberyCreationForm target constructor called\n";
	_target = target;
}

/*---MEMBER FUNCTIONS---*/

void		ShrubberyCreationForm::action() const
{
	std::ofstream outfile (_target + "_shrubbery");
	outfile << ent;
	outfile.close();
}

/*---OPERATORS---*/

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm &a)
{
	_target = a._target;
	return (*this);
}
