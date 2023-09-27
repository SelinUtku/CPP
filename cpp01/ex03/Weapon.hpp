/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:26:26 by sutku             #+#    #+#             */
/*   Updated: 2023/09/27 15:38:11 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon()
		{
			std::cout<<"Default constructer has been created"<<std::endl;
		}
		Weapon(std::string type)
		{
			this->setType(type);
			std::cout<<this->type<<" constructer has been created"<<std::endl;
		}
		~Weapon()
		{
			std::cout<<this->type<<" destructer called."<<std::endl;
		}
		const std::string& getType();
		void	setType(std::string str);
		
};
#endif