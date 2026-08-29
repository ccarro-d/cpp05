/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:40:12 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/29 17:24:33 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void)
{
	Bureaucrat paco("Paco", 2); // Válido
	std::cout << paco << " Valid bureaucrat." << std::endl; // Se ejecutará
	try
	{
		paco.incrementGrade(); // Válido
		std::cout << paco << " Still a valid bureaucrat." << std::endl; // Se ejecutará
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl; // No se ejecutará
	}
	Bureaucrat carmen("Carmen", 149); // Válido
	std::cout << carmen << " Valid bureaucrat." << std::endl; // Se ejecutará
	try
	{
		carmen.decrementGrade(); // Válido
		std::cout << carmen << " Still a valid bureaucrat." << std::endl; // Se ejecutará
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl; // No se ejecutará
	}

	try
	{
		Form horoscopo("horoscopo", 200, 100); // No válido
		std::cout << horoscopo << " Valid form." << std::endl; // No se ejecutará
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n'; // Se ejecutará
	}
	
	Form encuesta("encuesta", 150, 150); // Válido
	std::cout << encuesta; // No firmado de inicio
	paco.signForm(encuesta); // Válido
	std::cout << encuesta; // Firmado
	Form encarcelar("encarcelar", 50, 50);
	std::cout << encarcelar; // No firmado de inicio
	carmen.signForm(encarcelar); // No válido
	std::cout << encarcelar; // Sigue sin firmar
	return (0);
}