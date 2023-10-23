/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:44:42 by sutku             #+#    #+#             */
/*   Updated: 2023/10/23 11:59:04 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout<<"Cat default constructor called"<<std::endl;
	this->setType("Cat");
	this->brain = new Brain;
}

Cat::Cat(const Cat& copy) : Animal()
{
	std::cout<<"Cat copy constructor called"<<std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout<<"Cat copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->setType(copy.getType());
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*copy.brain);
	}		
	return (*this);
}


Cat::~Cat()
{
	std::cout<<"Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout<<"Meoww Meowww"<<std::endl;
}
