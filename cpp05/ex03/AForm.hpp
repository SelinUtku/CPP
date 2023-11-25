/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:52:57 by sutku             #+#    #+#             */
/*   Updated: 2023/11/25 15:14:25 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;
	public:	
		AForm();
		AForm(const std::string name, int gradeSign, int gradeExecute);
		AForm(const AForm &copy);
		AForm& operator=(const AForm &copy);
		virtual ~AForm();
		//GETTERS
		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeSigned() const;
		int				getGradeExecute() const;

		void			beSigned(Bureaucrat &bur);
		virtual void	execute(Bureaucrat const &executor) const = 0;
	
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
		class AlredySignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NotSignedYetException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif