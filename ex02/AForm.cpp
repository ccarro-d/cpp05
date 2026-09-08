/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:44:51 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/09/08 21:57:31 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high for this operation.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low for this operation.");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Signature needed before execution.");
}

void	AForm::checkMaxGrade(int grade) const
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
}

void	AForm::checkMinGrade(int grade) const
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

void	AForm::checkGrade(int grade) const
{
	checkMaxGrade(grade);
	checkMinGrade(grade);
}

AForm::AForm(void)
	: name_("Unnamed"),
		isSigned_(false),
		requiredGradeToSign_(150),
		requiredGradeToExecute_(150) {}

AForm::AForm(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute)
	: name_(name), isSigned_(false),
		requiredGradeToSign_(requiredGradeToSign),
		requiredGradeToExecute_(requiredGradeToExecute)
{	try
	{
		checkGrade(requiredGradeToSign);
	}
	catch (const std::exception&) // no damos nombre "e" de variable porque no lo usaremos y se quejaría -Werror
	{
		std::cerr << "Problem with requiredGradeToSign. ";
		throw; // vuelve a lanzar la excepción que estamos manejando
	}
	try
	{
		checkGrade(requiredGradeToExecute);
	}
	catch (const std::exception&) // no damos nombre "e" de variable porque no lo usaremos y se quejaría -Werror
	{
		std::cerr << "Problem with requiredGradeToExecute. ";
		throw; // vuelve a lanzar la excepción que estamos manejando
	}
}

AForm::AForm(const AForm& other)
	: name_(other.name_), isSigned_(other.isSigned_),
		requiredGradeToSign_(other.requiredGradeToSign_),
		requiredGradeToExecute_(other.requiredGradeToExecute_) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->isSigned_ = other.isSigned_;
	return (*this);
}

AForm::~AForm(void) {}

const std::string& AForm::getName(void) const
{
	return (name_);
}

bool AForm::getSignatureStatus(void) const
{
	return (isSigned_);
}

int AForm::getRequiredGradeToSign(void) const
{
	return (requiredGradeToSign_);
}

int AForm::getRequiredGradeToExecute(void) const
{
	return (requiredGradeToExecute_);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->requiredGradeToSign_)
		throw AForm::GradeTooLowException();
	this->isSigned_ = true;
}


void AForm::execute(const Bureaucrat& executor) const
{
	if (isSigned_ == false)
		throw AForm::NotSignedException();
	if (requiredGradeToExecute_ < executor.getGrade())
		throw AForm::GradeTooLowException();
	performFormAction();
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	std::string	formSignatureStatus = "true";
	if (form.getSignatureStatus() == false)
		formSignatureStatus = "false";
	out << form.getName() << " , form grade " << form.getRequiredGradeToSign() << " to sign and grade " << form.getRequiredGradeToExecute() << " to execute, signature is " << formSignatureStatus << "." << std::endl;
	return (out);
}