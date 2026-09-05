/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:40:12 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/09/05 12:43:42 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int	main(void)
{
	Bureaucrat presidente("Presidente", 1);
	Intern elKevin;
	Intern frikillo;
	Intern nepoBaby;
	Intern becarioBecariez;

	AForm *informeJefe = elKevin.makeForm("shrubbery creation", "Jefe");
	AForm *robotito = frikillo.makeForm("robotomy request", "C3PO");
	AForm *indultoPapa = nepoBaby.makeForm("presidential pardon", "Papa");
	AForm *buscateLaVida = becarioBecariez.makeForm("noseque form", "nosequien");

	if (informeJefe != NULL)
	{
		presidente.signForm(*informeJefe);
		presidente.executeForm(*informeJefe);
	}
	if (robotito != NULL)
	{
		presidente.signForm(*robotito);
		presidente.executeForm(*robotito);
	}
	if (indultoPapa != NULL)
	{
		presidente.signForm(*indultoPapa);
		presidente.executeForm(*indultoPapa);
	}
	if (buscateLaVida != NULL)
	{
		presidente.signForm(*buscateLaVida);
		presidente.executeForm(*buscateLaVida);
	}

	delete informeJefe;
	delete indultoPapa;
	delete buscateLaVida;

	return (0);
}
