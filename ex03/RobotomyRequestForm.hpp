/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:27:38 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/31 01:48:34 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp" 

class RobotomyRequestForm : public AForm {
	private:
		std::string targetName_;

		virtual void performFormAction() const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& targetName);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

};

#endif