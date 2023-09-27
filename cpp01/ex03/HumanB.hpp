/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:38:48 by sutku             #+#    #+#             */
/*   Updated: 2023/09/27 15:37:51 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *b; // here we need to use pointer because humanB can have no weapon at the start.
		std::string name;
	public:
		HumanB(std::string str) : name(str), b(nullptr)//thats why we initialize it with nullptr.
		{
		}
		void	attack();
		void	setWeapon(Weapon arm);
		~HumanB()
		{
			std::cout <<this->name<<" destructor called" << std::endl;
		}
};


#endif