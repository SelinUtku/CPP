/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:27:00 by sutku             #+#    #+#             */
/*   Updated: 2023/10/16 16:27:27 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Non")
{
	std::cout<<"WrongAnimal default constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout<<"WrongAnimal copy constructor called"<<std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout<<"WrongAnimal copy assignment operator called" << std::endl;
	this->type = copy.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const 
{
	return (this->type);
}

void WrongAnimal::setType(const std::string &name)
{
	this->type = name;
}

void WrongAnimal::makeSound() const
{
	std::cout<<"WrongAnimal doesnt make sound !"<<std::endl;
}