/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:52:54 by sutku             #+#    #+#             */
/*   Updated: 2023/11/26 15:12:43 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
	_name("noName"), 
	_signed(false), 
	_gradeSign(1), 
	_gradeExecute(1)
{
	std::cout<<"AForm default constuctor called"<<std::endl;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExecute) : 
	_name(name), 
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExecute(gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw (AForm::GradeTooHighException());
	else if (gradeSign > 150 || gradeExecute > 150)
		throw (AForm::GradeTooLowException());
	std::cout<<"AForm parameter constuctor called"<<std::endl;
}

AForm::~AForm()
{
	std::cout<<"AForm destructor called with "<<this->_name<<std::endl;
}

AForm& AForm::operator=(const AForm &copy)
{
	std::cout<<"AForm copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_signed = copy.getSigned();
	}
	return (*this);
}

AForm::AForm(const AForm &copy) : 
	_name(copy.getName()),
	_gradeSign(copy.getGradeSigned()), 
	_gradeExecute(copy.getGradeExecute())
{
	std::cout<<"AForm copy constructor called"<<std::endl;
	*this = copy;
}

//GETTERS

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return(this->_signed);
}

int AForm::getGradeSigned() const
{
	return (this->_gradeSign);
}

int AForm::getGradeExecute() const
{
	return (this->_gradeExecute);
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out<<"Form name: "<<form.getName()<<std::endl<<"Form signed: "<<form.getSigned()<<std::endl<< \
	"Form Grade Sign: "<<form.getGradeSigned()<<std::endl<<"Form Grade Execute: "<<form.getGradeExecute();
	return (out);
}

void AForm::beSigned(Bureaucrat &bur)
{
	if (this->_signed != true)
	{
		if (bur.getGrade() > this->_gradeSign)
			throw(AForm::GradeTooLowException());
		this->_signed = true;
	}
	else
		throw(AForm::AlredySignedException());
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed != true)
		throw (AForm::NotSignedYetException());
	if (executor.getGrade() > this->_gradeExecute)
		throw(AForm::GradeTooLowException());
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("the grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("the grade is too low");
}

const char *AForm::AlredySignedException::what() const throw()
{
	return ("the form is already signed");
}

const char *AForm::NotSignedYetException::what() const throw()
{
	return("the form didnt signed yet, you can not execute");
}
