/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:56:31 by sutku             #+#    #+#             */
/*   Updated: 2023/10/27 13:55:46 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;
	public:
		Form();
		Form(const std::string name, int gradeSign, int gradeExecute);
		Form(const Form &copy);
		Form& operator=(const Form &copy);
		~Form();
		
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSigned() const;
		int			getGradeExecute() const;
		void		beSigned(Bureaucrat &bur);
	
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public  std::exception
		{
			public:
				const char* what() const throw();
		};
		class AlredySigned : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif