/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 00:54:59 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/09/08 22:04:04 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	*this = other;
}
Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other)
{
	//No hace falta if (this != &other) porque no hay estado interno que copiar
	(void)other;
	return (*this);
}

AForm* Intern::makeShrubberyForm(const std::string& targetName)
{
	AForm *newShrubberyForm = new ShrubberyCreationForm(targetName);
	std::cout << "Intern creates newShrubberyForm" << std::endl;
	return (newShrubberyForm);
}

AForm* Intern::makeRobotomyForm(const std::string& targetName)
{
	AForm *newRobotomyForm = new RobotomyRequestForm(targetName);
	std::cout << "Intern creates newRobotomyForm" << std::endl;
	return (newRobotomyForm);
}

AForm* Intern::makePresidentialForm(const std::string& targetName)
{
	AForm *newPresidentialForm = new PresidentialPardonForm(targetName);
	std::cout << "Intern creates newPresidentialForm" << std::endl;
	return (newPresidentialForm);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& targetName)
{
	std::string forms[3]
	= {"shrubbery creation",
		"robotomy request",
		"presidential pardon"};
	
	AForm* (Intern::*functionsPtr[3])(const std::string& targetName)
	= {&Intern::makeShrubberyForm,
		&Intern::makeRobotomyForm,
		&Intern::makePresidentialForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
			return((this->*functionsPtr[i])(targetName));		
	}
	std::cerr << "Inexistent form type: " << formName << std::endl;
	return (NULL);
}
