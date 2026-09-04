/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:27:38 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/31 01:53:02 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp" 

class PresidentialPardonForm : public AForm {
	private:
		std::string targetName_;

		virtual void performFormAction() const;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& targetName);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

};

#endif