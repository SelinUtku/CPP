/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:40:15 by sutku             #+#    #+#             */
/*   Updated: 2023/11/25 17:07:11 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout<<"Intern default constuctor called"<<std::endl;
}

Intern& Intern::operator=(const Intern &copy)
{
	std::cout<<"Intern copy assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

Intern::Intern(const Intern &copy)
{
	std::cout<<"Intern copy constructor called"<<std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout<<"Intern destructor called "<<std::endl;
}

const char * Intern::InvalidFormException::what() const throw()
{
	return ("Invalid formName");
}


AForm* Intern::makeForm(const std::string formName, const std::string targetName)
{
	AForm* (Intern::*fptr[3])(std::string targetName) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
	std::string forms[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	int i = 0;
	while (i < 3)
	{
		if (formName == forms[i])
			return((this->*fptr[i])(targetName));
		i++;
	}
	throw(InvalidFormException());
}

AForm* Intern::createShrubbery(const std::string targetName)
{
	AForm *ptr = new ShrubberyCreationForm(targetName);
	return (ptr);
}

AForm* Intern::createRobotomy(const std::string targetName)
{
	AForm *ptr = new RobotomyRequestForm(targetName);
	return (ptr);
}

AForm* Intern::createPresidential(const std::string targetName)
{
	AForm *ptr = new PresidentialPardonForm(targetName);
	return (ptr);
}