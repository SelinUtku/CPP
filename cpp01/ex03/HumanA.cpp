/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:23:12 by sutku             #+#    #+#             */
/*   Updated: 2023/10/03 16:24:27 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA :: HumanA(std::string str, Weapon& arm) : name(str), a(arm)
{
}

HumanA :: ~HumanA()
{
	std::cout<<this->name<<" destructor called"<<std::endl;
}

void	HumanA::attack()
{
	std::cout<<this->name<<" attacks with their "<<this->a.getType()<<std::endl;
}
