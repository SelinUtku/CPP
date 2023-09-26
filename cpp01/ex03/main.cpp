/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:38:29 by sutku             #+#    #+#             */
/*   Updated: 2023/09/26 19:10:22 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		std::cout<<"-----HumanA-----"<<std::endl;
		Weapon club("gun");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("sharp knife");
		bob.attack();
	}
	{
		std::cout<<"-----HumanB-----"<<std::endl;
		Weapon club;
		HumanB jim("Jim");
		jim.attack();
		club.setType("sharp knife");
		jim.setWeapon(club);
		jim.attack();
	}
	return 0;
}