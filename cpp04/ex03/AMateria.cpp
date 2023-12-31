/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:44:59 by sutku             #+#    #+#             */
/*   Updated: 2023/10/23 13:37:07 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout<<"AMateria Default Constructor called"<<std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout<<"AMateria Parameter Constructor called"<<std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout<<"AMateria copy constructor called"<<std::endl;
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria &copy)
{
	std::cout<<"AMateria copy assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
	return (*this);
}

std::string const& AMateria::getType() const
{
	return(this->type);
}


void AMateria::use(ICharacter &target)
{
	std::cout<<this->type<<" is using itself to "<<target.getName()<<std::endl;
}

AMateria::~AMateria()
{
	std::cout<<"AMateria Default destructor called"<<std::endl;
}
