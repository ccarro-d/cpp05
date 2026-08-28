/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:44:48 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/28 22:33:46 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class	Bureaucrat;

class Form
{
	private:
		const std::string name_;
		bool isSigned_;
		const int requiredGradeToSign_;
		const int requiredGradeToExecute_;

	public:
		Form();
		Form(const std::string &name, bool isSigned, int requiredGradeToSign, int requiredGradeToExecute);
		Form(const Form &other);
		~Form();
		
		Form &operator=(const Form &other);
		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif