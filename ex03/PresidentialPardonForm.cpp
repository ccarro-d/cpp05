/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:27:55 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/31 01:57:58 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5), targetName_("Unnamed") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& targetName)
	: AForm("PresidentialPardonForm", 25, 5), targetName_(targetName) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), targetName_(other.targetName_) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	this->targetName_ = other.targetName_;
	return (*this);
}

void PresidentialPardonForm::performFormAction() const
{
	std::cout << targetName_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
