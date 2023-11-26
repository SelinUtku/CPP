/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:21:22 by sutku             #+#    #+#             */
/*   Updated: 2023/11/26 15:35:33 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), _target("noTarget")
{
	std::cout<<"RobotomyRequestForm default constuctor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout<<"RobotomyRequestForm parameter constuctor called"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout<<"RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &copy)
		_target = copy.getTarget();
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
	std::cout<<"RobotomyRequestForm copy constructor called"<<std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"RobotomyRequestForm destructor called with "<<this->getName()<<std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout<<"Some drilling noisesssssssss"<<std::endl;
	std::srand(std::time(0));
	if ((std::rand() % 2) == 0)
		std::cout<<this->getTarget()<<" has been robotomized successfully"<<std::endl;
	else
		std::cout<<"Fail occured while "<<this->getTarget()<<" has been robotomized"<<std::endl;
}
