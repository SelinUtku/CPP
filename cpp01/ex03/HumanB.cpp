/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:32:17 by sutku             #+#    #+#             */
/*   Updated: 2023/10/03 17:39:07 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB :: HumanB(std::string str) : name(str), b(nullptr)
{
}

HumanB :: ~HumanB()
{
	std::cout<<this->name<<" destructor called"<<std::endl;
}

void	HumanB::setWeapon(Weapon& arm)
{
	this->b = &arm;
}

void	HumanB::attack()
{
	if (this->b != NULL)
		std::cout<<this->name<<" attacks with their "<<this->b->getType()<<std::endl;
	else
		std::cout<<this->name<<" has no weapon"<<std::endl;
}
