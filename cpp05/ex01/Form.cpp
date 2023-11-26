/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:00:22 by sutku             #+#    #+#             */
/*   Updated: 2023/11/26 14:51:39 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
	_name("noName"), 
	_signed(false), 
	_gradeSign(1), 
	_gradeExecute(1)
{
	std::cout<<"Form default constuctor called"<<std::endl;
}

Form::Form(const std::string name, int gradeSign, int gradeExecute) : 
	_name(name), 
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExecute(gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw (Form::GradeTooHighException());
	else if (gradeSign > 150 || gradeExecute > 150)
		throw (Form::GradeTooLowException());
	std::cout<<"Form parameter constuctor called"<<std::endl;
}

Form::~Form()
{
	std::cout<<"Form destructor called with "<<this->_name<<std::endl;
}

Form& Form::operator=(const Form &copy)
{
	std::cout<<"Form copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_signed = copy.getSigned();
	return (*this);
}

Form::Form(const Form &copy) : 
	_name(copy.getName()),
	_gradeSign(copy.getGradeSigned()), 
	_gradeExecute(copy.getGradeExecute())
{
	std::cout<<"Form copy constructor called"<<std::endl;
	*this = copy;
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return(this->_signed);
}

int Form::getGradeSigned() const
{
	return (this->_gradeSign);
}

int Form::getGradeExecute() const
{
	return (this->_gradeExecute);
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out<<"Form name: "<<form.getName()<<std::endl<<"Form signed: "<<form.getSigned()<<std::endl<< \
	"Form Grade Sign: "<<form.getGradeSigned()<<std::endl<<"Form Grade Execute: "<<form.getGradeExecute();
	return (out);
}

void Form::beSigned(Bureaucrat &bur)
{
	if (this->_signed != true)
	{
		if (bur.getGrade() > this->_gradeSign)
			throw(Form::GradeTooLowException());
		this->_signed = true;
	}
	else
		throw(Form::AlredySigned());
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("the grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("the grade is too low");
}

const char *Form::AlredySigned::what() const throw()
{
	return ("the form is already signed");
}
