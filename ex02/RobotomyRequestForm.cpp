/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:27:55 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/31 02:27:32 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include <cstdlib> // para rand() y srand()
# include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), targetName_("Unnamed") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& targetName)
	: AForm("RobotomyRequestForm", 72, 45), targetName_(targetName) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), targetName_(other.targetName_) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	this->targetName_ = other.targetName_;
	return (*this);
}

void RobotomyRequestForm::performFormAction() const
{
	static bool seeded = false; // para que la semilla solo se ejecute una vez
	if (!seeded)
	{
		srand(time(NULL)); // obtenemos la semilla de la hora actual (cuenta hasta segundos)
		seeded = true;
	}
	std::cout << "Some drilling noises" << std::endl;
	if (rand() % 2) // la semilla inicializa el estado del PRNG; cada rand() genera el siguiente valor haciendo evolucionar ese estado
		std::cout << targetName_ << " successfully robotomized" << std::endl;
	else // no lo lanzamos como excepcion porque el formulario realmente sí se ha ejecutado y lo que falla es la robotomía
		std::cout << targetName_ << " couldn't be robotomized" << std::endl;
}
