/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:01:16 by sutku             #+#    #+#             */
/*   Updated: 2023/10/23 11:07:59 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Non")
{
	std::cout<<"Animal default constructor called"<<std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout<<"Animal copy constructor called"<<std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
	std::cout<<"Animal copy assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout<<"Animal destructor called" << std::endl;
}

std::string Animal::getType() const 
{
	return (this->type);
}

void Animal::setType(const std::string &name)
{
	this->type = name;
}
