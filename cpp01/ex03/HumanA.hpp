/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:35:27 by sutku             #+#    #+#             */
/*   Updated: 2023/09/27 15:37:28 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon &a; //here we need to use reference because humanA should have a weapon from the start.
		std::string name;
	public:
		HumanA(std::string str, Weapon& arm) : name(str), a(arm)
		{
			/*
			So, in your HumanA class, you need to set up the reference 
			a when the HumanA object is created, and you can't change 
			it to refer to a different Weapon later. That's why 
			the reference must be initialized in the constructor's i
			nitializer list when you create the HumanA object.*/
		}
		~HumanA()
		{
			std::cout<<this->name<<" destructer called"<<std::endl;
		}
		void	attack();
};


#endif