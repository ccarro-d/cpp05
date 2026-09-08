/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:39:41 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/09/08 22:07:39 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"


Bureaucrat::Bureaucrat(void) : name_("Unnamed"), grade_(150) {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high for this operation.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low for this operation.");
}

void Bureaucrat::checkMaxGrade(int grade) const
{
	if (grade < maxGrade)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::checkMinGrade(int grade) const
{
	if (grade > minGrade)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::checkGrade(int grade) const
{
	checkMaxGrade(grade);
	checkMinGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name)
{
	checkGrade(grade);
	grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->grade_ = other.getGrade();
	//El nombre no se puede igualar porque es constante en cada objeto
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}

const std::string& Bureaucrat::getName(void) const
{
	return (name_);
}

int Bureaucrat::getGrade(void) const
{
	return (grade_);
}

void Bureaucrat::incrementGrade()
{
	checkMaxGrade(grade_ - 1);
	grade_--;
}

void Bureaucrat::decrementGrade()
{
	checkMinGrade(grade_ + 1);
	grade_++;	
}

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cerr << name_ << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << name_ << " signed " << form.getName() << "." << std::endl;
}
