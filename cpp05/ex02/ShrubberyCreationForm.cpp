/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:36:30 by sutku             #+#    #+#             */
/*   Updated: 2023/11/25 17:18:24 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout<<"ShrubberyCreationForm parameter constuctor called"<<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout<<"ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &copy)
		_target = copy.getTarget();
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	std::cout<<"ShrubberyCreationForm copy constructor called"<<std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm destructor called with "<<this->getName()<<std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

	AForm::execute(executor);
	std::ofstream outFile;
	outFile.open((this->getTarget() + "_shrubbery").c_str());
	if (outFile.is_open())
	{
        outFile << "     ^    \n";
        outFile << "    /\\    \n";
        outFile << "   /  \\   \n";
        outFile << "  /    \\  \n";
        outFile << " /      \\ \n";
        outFile << "----------\n";
        outFile.close();
	}
	else
		std::cout << "Unable to open file"<<std::endl;
}