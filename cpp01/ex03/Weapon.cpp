/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:26:20 by sutku             #+#    #+#             */
/*   Updated: 2023/10/03 16:31:01 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon :: Weapon()
{
	std::cout<<"Default constructor has been created"<<std::endl;
}

Weapon::Weapon(std::string str)
{
	this->setType(str);
	std::cout<<this->type<<" constructor has been created"<<std::endl;
}

Weapon :: ~Weapon()
{
	std::cout<<this->type<<" destructor called."<<std::endl;
}

void Weapon::setType(std::string str)
{
	this->type = str;
}

const std::string& Weapon:: getType()
{
	const std::string& newType = this->type;
	return (newType);
}
