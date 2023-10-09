/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:26:23 by sutku             #+#    #+#             */
/*   Updated: 2023/10/08 21:31:50 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap cagatay("Cagatay");
	ClapTrap selin("Selin");
	std::cout<<"Hit Point : "<<cagatay.getHitPoints()<<std::endl;
	std::cout<<"Energy Point : "<<cagatay.getEnergyPoints()<<std::endl;
	std::cout<<"Attack Damage : "<<cagatay.getAttackDamage()<<std::endl;
	
	cagatay.attack("Selin");
	selin.takeDamage(6);
	selin.beRepaired(5);
	cagatay.takeDamage(3);

	std::cout<<"New Hit Point : "<<cagatay.getHitPoints()<<std::endl;
	std::cout<<"New Energy Point : "<<cagatay.getEnergyPoints()<<std::endl;
	std::cout<<"New Attack Damage : "<<cagatay.getAttackDamage()<<std::endl;
	std::cout<<std::endl;
	std::cout<<"New Hit Point : "<<selin.getHitPoints()<<std::endl;
	std::cout<<"New Energy Point : "<<selin.getEnergyPoints()<<std::endl;
	std::cout<<"New Attack Damage : "<<selin.getAttackDamage()<<std::endl;
	return (0);
}