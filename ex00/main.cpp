/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 20:04:06 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/28 21:28:14 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat pepe("Pepe", 0); // No válido
		std::cout << pepe << " Valid bureaucrat." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat luis("Luis", 151); // No válido
		std::cout << luis << " Valid bureaucrat." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat juan("Juan", 1); // Válido
	std::cout << juan << " Valid bureaucrat." << std::endl;
	try
	{
		juan.incrementGrade(); // No válido
		std::cout << juan << " Still a valid bureaucrat." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat charo("Charo", 150); // Válido
	std::cout << charo << " Valid bureaucrat." << std::endl;
	try
	{
		charo.decrementGrade(); // No válido
		std::cout << charo << " Still a valid bureaucrat." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat paco("Paco", 2); // Válido
	std::cout << paco << " Valid bureaucrat." << std::endl;
	try
	{
		paco.incrementGrade(); // Válido
		std::cout << paco << " Still a valid bureaucrat." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat carmen("Carmen", 149); // Válido
	std::cout << carmen << " Valid bureaucrat." << std::endl;
	try
	{
		carmen.decrementGrade(); // Válido
		std::cout << carmen << " Still a valid bureaucrat." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}