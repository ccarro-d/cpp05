/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 00:54:56 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/09/04 19:37:34 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {
private:
	AForm *makeShrubberyForm(const std::string& targetName);
	AForm *makeRobotomyForm(const std::string& targetName);
	AForm *makePresidentialForm(const std::string& targetName);

public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern& operator=(const Intern& other);
	AForm *makeForm(const std::string& formName, const std::string& targetName);
};

#endif