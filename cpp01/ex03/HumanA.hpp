/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:35:27 by sutku             #+#    #+#             */
/*   Updated: 2023/10/03 13:33:07 by sutku            ###   ########.fr       */
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
		HumanA(std::string str, Weapon& arm);
		~HumanA();
		void	attack();
};


#endif