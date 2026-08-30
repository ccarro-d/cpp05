/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:40:12 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/30 23:00:59 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat paco("Paco", 2); // Válido
	Bureaucrat carmen("Carmen", 149); // Válido
	
	ShrubberyCreationForm encuesta; // Válido
	std::cout << encuesta; // No firmado de inicio
	paco.signForm(encuesta); // Válido
	std::cout << encuesta; // Firmado
	paco.executeForm(encuesta); // Ejecutado
	ShrubberyCreationForm cuestionario("cuestionario"); // Válido
	std::cout << cuestionario; // No firmado de inicio
	carmen.signForm(cuestionario); // No válido
	std::cout << cuestionario; // Sigue sin firmar
	carmen.executeForm(cuestionario); // No válido
	return (0);
}