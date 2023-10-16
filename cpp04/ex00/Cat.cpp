/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:44:42 by sutku             #+#    #+#             */
/*   Updated: 2023/10/16 16:17:34 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout<<"Cat default constructor called"<<std::endl;
	this->setType("Cat");
}

Cat::Cat(const Cat& copy)
{
	std::cout<<"Cat copy constructor called"<<std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout<<"Cat copy assignment operator called" << std::endl;
	this->setType(copy.getType());
	return (*this);
}

Cat::~Cat()
{
	std::cout<<"Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout<<"Meoww Meowww"<<std::endl;
}
