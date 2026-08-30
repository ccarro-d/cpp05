/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:44:51 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/30 11:22:43 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high for this operation.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low for this operation.");
}

void	Form::checkMaxGrade(int grade) const
{
	if (grade < 1)
		throw Form::GradeTooHighException();
}

void	Form::checkMinGrade(int grade) const
{
	if (grade > 150)
		throw Form::GradeTooLowException();
}

void	Form::checkGrade(int grade) const
{
	checkMaxGrade(grade);
	checkMinGrade(grade);
}

Form::Form(void)
	: name_("Unnamed"),
		isSigned_(false),
		requiredGradeToSign_(150),
		requiredGradeToExecute_(150) {}

Form::Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute)
	: name_(name), isSigned_(false),
		requiredGradeToSign_(requiredGradeToSign),
		requiredGradeToExecute_(requiredGradeToExecute)
{	try
	{
		checkGrade(requiredGradeToSign);
	}
	catch (const std::exception&) // no damos nombre "e" de variable porque no lo usaremos y se quejaría -Werror
	{
		std::cout << "Problem with requiredGradeToSign. ";
		throw; // vuelve a lanzar la excepción que estamos manejando
	}
	try
	{
		checkGrade(requiredGradeToExecute);
	}
	catch (const std::exception&) // no damos nombre "e" de variable porque no lo usaremos y se quejaría -Werror
	{
		std::cout << "Problem with requiredGradeToExecute. ";
		throw; // vuelve a lanzar la excepción que estamos manejando
	}
}

Form::Form(const Form& other)
	: name_(other.name_), isSigned_(other.isSigned_),
		requiredGradeToSign_(other.requiredGradeToSign_),
		requiredGradeToExecute_(other.requiredGradeToExecute_) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->isSigned_ = other.isSigned_;
	return (*this);
}

Form::~Form(void) {}

const std::string& Form::getName(void) const
{
	return (name_);
}

bool Form::getSignatureStatus(void) const
{
	return (isSigned_);
}

int Form::getRequiredGradeToSign(void) const
{
	return (requiredGradeToSign_);
}

int Form::getRequiredGradeToExecute(void) const
{
	return (requiredGradeToExecute_);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->requiredGradeToSign_)
		throw Form::GradeTooLowException();
	this->isSigned_ = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	std::string	formSignatureStatus = "true";
	if (form.getSignatureStatus() == false)
		formSignatureStatus = "false";
	out << form.getName() << " , form grade " << form.getRequiredGradeToSign() << " to sign and grade " << form.getRequiredGradeToExecute() << " to execute, signature is " << formSignatureStatus << "." << std::endl;
	return (out);
}