/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:40:12 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/31 02:30:01 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat paco("Paco", 2); // Válido
	Bureaucrat carmen("Carmen", 149); // Válido
	Bureaucrat charo("Charo", 13); // Válido
	
	ShrubberyCreationForm encuesta; // Válido
	std::cout << encuesta; // No firmado de inicio
	paco.signForm(encuesta); // Válido
	std::cout << encuesta; // Firmado
	paco.executeForm(encuesta); // Ejecutado
	std::cout << std::endl;
	ShrubberyCreationForm cuestionario("cuestionario"); // Válido
	std::cout << cuestionario; // No firmado de inicio
	carmen.signForm(cuestionario); // No válido
	std::cout << cuestionario; // Sigue sin firmar
	carmen.executeForm(cuestionario); // No válido
	std::cout << std::endl << std::endl << std::endl;

	RobotomyRequestForm robotomia; // Válido
	std::cout << robotomia; // No firmado de inicio
	paco.signForm(robotomia); // Válido
	std::cout << robotomia; // Firmado
	paco.executeForm(robotomia); // Ejecutado
	paco.executeForm(robotomia); // Para ver otro resultado
	paco.executeForm(robotomia); // Ídem
	std::cout << std::endl;
	RobotomyRequestForm robotomizacion("robotomizacion"); // Válido
	std::cout << robotomizacion; // No firmado de inicio
	carmen.signForm(robotomizacion); // No válido
	std::cout << robotomizacion; // Sigue sin firmar
	carmen.executeForm(robotomizacion); // No válido
	std::cout << std::endl << std::endl << std::endl;

	
	PresidentialPardonForm indulto; // Válido
	std::cout << indulto; // No firmado de inicio
	paco.signForm(indulto); // Válido
	std::cout << indulto; // Firmado
	paco.executeForm(indulto); // Ejecutado
	std::cout << std::endl;
	PresidentialPardonForm amnistia("amnistia"); // Válido
	std::cout << amnistia; // No firmado de inicio
	carmen.signForm(amnistia); // No válido
	std::cout << amnistia; // Sigue sin firmar
	carmen.executeForm(amnistia); // No válido
	std::cout << std::endl;
	PresidentialPardonForm clemencia("clemencia"); // Válido
	std::cout << clemencia; // No firmado de inicio
	charo.signForm(clemencia); // Válido
	std::cout << clemencia; // Firmado
	charo.executeForm(clemencia); // No válido

	return (0);
}