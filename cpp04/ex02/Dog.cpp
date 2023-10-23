/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:14:50 by sutku             #+#    #+#             */
/*   Updated: 2023/10/23 11:11:08 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout<<"Dog default constructor called"<<std::endl;
	this->setType("Dog");
	this->brain = new Brain;
}

Dog::Dog(const Dog& copy) : Animal()
{
	std::cout<<"Dog copy constructor called"<<std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog &copy)
{
	std::cout<<"Dog copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->setType(copy.getType());
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout<<"Hav Hav Hav"<<std::endl;
}

