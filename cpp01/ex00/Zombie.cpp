/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:28:30 by sutku             #+#    #+#             */
/*   Updated: 2023/10/03 13:02:58 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout<<this->name<<" is destroyed"<<std::endl;
}

void	Zombie::announce()
{
	std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
