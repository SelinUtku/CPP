/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:58:49 by sutku             #+#    #+#             */
/*   Updated: 2023/10/23 13:39:23 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout<<"Ice default Constructor called"<<std::endl;
}


Ice::Ice(const Ice &copy) : AMateria()
{
	std::cout<<"Ice copy constructor called"<<std::endl;
	*this = copy;
}

Ice& Ice::operator=(const Ice &copy)
{
	std::cout<<"Ice copy assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
	return (*this);
}


AMateria* Ice::clone() const
{
	AMateria *cloneIce = new Ice(*this);

	return (cloneIce);
}

void Ice::use(ICharacter &target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}

Ice::~Ice()
{
	std::cout<<"Ice default constructor called"<<std::endl;
}
