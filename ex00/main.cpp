/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:40:12 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/29 17:08:33 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat pepe("Pepe", 0); // No válido
		std::cout << pepe << " Valid bureaucrat." << std::endl; // No se ejecutará
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;  // Se ejecutará
	}
	try
	{
		Bureaucrat luis("Luis", 151); // No válido
		std::cout << luis << " Valid bureaucrat." << std::endl; // No se ejecutará
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;  // Se ejecutará
	}
	Bureaucrat juan("Juan", 1); // Válido
	std::cout << juan << " Valid bureaucrat." << std::endl; // Se ejecutará
	try
	{
		juan.incrementGrade(); // No válido
		std::cout << juan << " Still a valid bureaucrat." << std::endl; // No se ejecutará
	}
	catch (const std::exception& e) // Se ejecutará
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat charo("Charo", 150); // Válido
	std::cout << charo << " Valid bureaucrat." << std::endl; // Se ejecutará
	try
	{
		charo.decrementGrade(); // No válido
		std::cout << charo << " Still a valid bureaucrat." << std::endl; // No se ejecutará
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl; // Se ejecutará
	}
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
	return (0);
}