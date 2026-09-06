/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:27:38 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/09/06 17:24:11 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string targetName_;

		virtual void performFormAction() const;
		void writeAsciiTrees(std::ostream& out) const;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& targetName);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		class FailedOpenFileException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class FailedWriteFileException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

#endif