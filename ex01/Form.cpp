/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:44:51 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/28 22:33:24 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: name_("Unnamed"),
		isSigned_(false),
		requiredGradeToSign_(0),
		requiredGradeToExecute_(0)
{
}

Form::Form(const std::string &name, bool isSigned, int requiredGradeToSign, int requiredGradeToExecute)
	: name_(name), isSigned_(isSigned),
		requiredGradeToSign_(requiredGradeToSign),
		requiredGradeToExecute_(requiredGradeToExecute)
{}

Form::Form(const Form& other)
{
	if (this != &other)
		this->isSigned_ = other.isSigned_;
}

Form::Form(const Form& other)
{
	if (this != &other)
		this->isSigned_ = other.isSigned_;
}

Form::~Form(void) {}