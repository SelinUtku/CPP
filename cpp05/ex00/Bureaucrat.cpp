/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:00:39 by sutku             #+#    #+#             */
/*   Updated: 2023/11/26 13:43:59 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
_name("noName"), 
_grade(150)
{
	std::cout<<"Bureaucrat default constuctor called"<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) :
_name(name)
{
	if (grade >= 1 && grade <= 150)
		this->_grade = grade;
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		throw (Bureaucrat::GradeTooHighException());
	std::cout<<"Bureaucrat parameter constuctor called"<<std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat destructor called with "<<this->_name<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout<<"Bureaucrat copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_grade = copy.getGrade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :
_name(copy.getName())
{
	std::cout<<"Bureaucrat copy constructor called"<<std::endl;
	*this = copy;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The Grade is too high !");	
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The Grade is too low !");	
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur)
{
	out << bur.getName()<<", bureaucrat grade "<<bur.getGrade();
	return (out);
}
