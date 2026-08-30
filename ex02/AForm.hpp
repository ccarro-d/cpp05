/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:44:48 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/08/30 10:14:28 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>

class	Bureaucrat; // forward declaration porque solo utilizamos esta clase por referencia y en este punto el compilador no necesita saber cómo está construida la clase; únicamente necesita saber que ese tipo existe.

class AForm {
	private:
		const std::string name_;
		bool isSigned_;
		const int requiredGradeToSign_;
		const int requiredGradeToExecute_;

		void	checkGrade(int grade) const;
		void	checkMaxGrade(int grade) const;
		void	checkMinGrade(int grade) const;
	
	protected:
		virtual void performFormAction() const = 0;

	public:
		AForm();
		AForm(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);
		
		const std::string& getName() const;
		bool getSignatureStatus() const;
		int	getRequiredGradeToSign() const;
		int getRequiredGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);
		void execute(const Bureaucrat& executor) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif