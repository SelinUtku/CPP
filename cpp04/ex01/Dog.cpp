/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:14:50 by sutku             #+#    #+#             */
/*   Updated: 2023/10/17 08:39:28 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout<<"Dog default constructor called"<<std::endl;
	this->setType("Dog");
	this->ptr = new Brain;
}

Dog::Dog(const Dog& copy)
{
	std::cout<<"Dog copy constructor called"<<std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout<<"Dog copy assignment operator called" << std::endl;
	this->setType(copy.getType());
	this->ptr = copy.ptr;
	return (*this);
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called" << std::endl;
	delete ptr;
}

void Dog::makeSound() const
{
	std::cout<<"Hav Hav Hav"<<std::endl;
}

