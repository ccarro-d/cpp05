/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:27:55 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/09/06 17:49:58 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include <fstream> // para los file streams (en este caso std::ofstream)

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), targetName_("Unnamed") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& targetName)
	: AForm("ShrubberyCreationForm", 145, 137), targetName_(targetName) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), targetName_(other.targetName_) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	this->targetName_ = other.targetName_;
	return (*this);
}

const char *ShrubberyCreationForm::FailedOpenFileException::what() const throw()
{
	return ("Failure at opening file");
}

const char *ShrubberyCreationForm::FailedWriteFileException::what() const throw()
{
	return ("Failure at writing file");
}

void ShrubberyCreationForm::writeAsciiTrees(std::ostream& out) const // pasamos file como tipo ostream generico porque la función no necesita saber que escribe específicamente en un archivo (aunque se podría). Solo necesita un stream de salida > std::ofstream IS-A std::ostream
{
	out << "				,@@@@@@@,				" << std::endl;
	out << "		,,,.   ,@@@@@@/@@,  .oo8888o.	" << std::endl;
	out << "	,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o	" << std::endl;
	out << "	,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'	" << std::endl;
	out << "	%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'	" << std::endl;
	out << "	%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'	" << std::endl;
	out << "	`&%\\ ` /%&'    |.|        \\ '|8'	" << std::endl;
	out << "		|o|        | |         | |		" << std::endl;
	out << "		|.|        | |         | |		" << std::endl;
	out << "	\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//_/_" << std::endl;

}

void ShrubberyCreationForm::performFormAction() const
{
	std::string	fileName = targetName_ + "_shrubbery";
	std::ofstream file(fileName.c_str()); // En C++98 la interfaz clásica de std::ofstream recibe un const char* y no un std::string
	if (file.is_open() == false)
		throw FailedOpenFileException();
	writeAsciiTrees(file);
	if (file.fail()) // Comprobamos si alguna operación de escritura dejó el stream en estado de fallo
		throw FailedWriteFileException();
	file.close(); // Se podría quitar ya que no es necesario realmente al cerrarse solo al ejecutarse el destructor de "std::ofstream file" cuando termina el cuerpo de la función
	if (file.fail()) // Comprobamos si el flush/cierre final dejó el stream en estado de fallo
		throw FailedWriteFileException();
}
