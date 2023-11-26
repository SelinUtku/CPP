/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:05:08 by sutku             #+#    #+#             */
/*   Updated: 2023/11/26 15:35:03 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), _target("noTarget")
{
	std::cout<<"PresidentialPardonForm default constuctor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout<<"PresidentialPardonForm parameter constuctor called"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout<<"PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &copy)
		_target = copy.getTarget();
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
	std::cout<<"PresidentialPardonForm copy constructor called"<<std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardonForm destructor called with "<<this->getName()<<std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}