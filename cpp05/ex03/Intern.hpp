/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:35:51 by sutku             #+#    #+#             */
/*   Updated: 2023/11/25 17:07:15 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		Intern& operator=(const Intern &copy);
		~Intern();
		
		AForm * createShrubbery(const std::string targetName);
		AForm * createRobotomy(const std::string targetName);
		AForm * createPresidential(const std::string targetName);
		AForm * makeForm(const std::string formName, const std::string targetName);
		class InvalidFormException : public std::exception
		{
			public:
			const char* what() const throw();
		};
};

#endif