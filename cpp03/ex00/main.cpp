/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:26:23 by sutku             #+#    #+#             */
/*   Updated: 2023/10/20 10:30:09 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	
	ClapTrap cagatay("Cagatay");
	ClapTrap selin("Selin");
	std::cout<<std::endl<<"---------------Default---------------"<<std::endl<<std::endl;
	std::cout<<"Hit Point : "<<cagatay.getHitPoints()<<std::endl;
	std::cout<<"Energy Point : "<<cagatay.getEnergyPoints()<<std::endl;
	std::cout<<"Attack Damage : "<<cagatay.getAttackDamage()<<std::endl;

	std::cout<<std::endl<<"--------------------------------------"<<std::endl<<std::endl;
	cagatay.setAttackDamage(6);
	selin.setAttackDamage(3);
	cagatay.attack("Selin");
	selin.takeDamage(6);
	selin.beRepaired(5);
	selin.attack("Cagatay");
	cagatay.takeDamage(3);
	std::cout<<std::endl<<"---------------AFTER---------------"<<std::endl<<std::endl;
	std::cout<<cagatay.getName()<<" New Hit Point : "<<cagatay.getHitPoints()<<std::endl;
	std::cout<<cagatay.getName()<<" New Energy Point : "<<cagatay.getEnergyPoints()<<std::endl;
	std::cout<<cagatay.getName()<<" New Attack Damage : "<<cagatay.getAttackDamage()<<std::endl;
	std::cout<<std::endl<<"---------------AFTER---------------"<<std::endl<<std::endl;
	std::cout<<selin.getName()<<" New Hit Point : "<<selin.getHitPoints()<<std::endl;
	std::cout<<selin.getName()<<" New Energy Point : "<<selin.getEnergyPoints()<<std::endl;
	std::cout<<selin.getName()<<" New Attack Damage : "<<selin.getAttackDamage()<<std::endl;
	std::cout<<std::endl<<"--------------------------------------"<<std::endl<<std::endl;
	return (0);
}
