/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:26:04 by sutku             #+#    #+#             */
/*   Updated: 2023/10/16 16:26:41 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout<<"WrongCat default constructor called"<<std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout<<"WrongCat copy constructor called"<<std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout<<"WrongCat copy assignment operator called" << std::endl;
	this->setType(copy.getType());
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout<<"WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout<<"Meoww Meowww"<<std::endl;
}