/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:25:26 by sutku             #+#    #+#             */
/*   Updated: 2023/10/20 08:15:12 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout<<"Cure default constructor called"<<std::endl;
}


Cure::Cure(const Cure &copy)
{
	std::cout<<"Cure copy constructor called"<<std::endl;
	*this = copy;
}

Cure& Cure::operator=(const Cure &copy)
{
	std::cout<<"Cure copy assignment operator called" << std::endl;
	this->type = copy.getType();
	return (*this);
}


AMateria* Cure::clone() const
{
	AMateria *cloneCure = new Cure(*this);

	return (cloneCure);
}

void Cure::use(ICharacter &target)
{
	std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}

Cure::~Cure()
{
	std::cout<<"Cure default constructor called"<<std::endl;
}
