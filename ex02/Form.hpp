/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:44:48 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/29 16:59:06 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class	Bureaucrat; // forward declaration porque solo utilizamos esta clase por referencia y en este punto el compilador no necesita saber cómo está construida la clase; únicamente necesita saber que ese tipo existe.

class Form
{
	private:
		const std::string name_;
		bool isSigned_;
		const int requiredGradeToSign_;
		const int requiredGradeToExecute_;

		void	checkGrade(int grade);
		void	checkMaxGrade(int grade);
		void	checkMinGrade(int grade);

	public:
		Form();
		Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);
		
		const std::string& getName() const;
		bool getSignatureStatus() const;
		int	getRequiredGradeToSign() const;
		int getRequiredGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif