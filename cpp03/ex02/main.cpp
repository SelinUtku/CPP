/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:26:23 by sutku             #+#    #+#             */
/*   Updated: 2023/10/16 12:25:52 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap cagatay("Cagatay");
	FragTrap selin("Selin");
	
	selin.attack("Cagatay");
	cagatay.takeDamage(selin.getAttackDamage());
	cagatay.attack("Selin");
	cagatay.beRepaired(40);
	selin.takeDamage(10);
	std::cout<<std::endl;
	std::cout<<"---------cagatay----------"<<std::endl;
	std::cout<<"New Hit Point : "<<cagatay.getHitPoints()<<std::endl;
	std::cout<<"New Energy Point : "<<cagatay.getEnergyPoints()<<std::endl;
	std::cout<<"New Attack Damage : "<<cagatay.getAttackDamage()<<std::endl;
	std::cout<<"---------selin----------"<<std::endl;
	std::cout<<"New Hit Point : "<<selin.getHitPoints()<<std::endl;
	std::cout<<"New Energy Point : "<<selin.getEnergyPoints()<<std::endl;
	std::cout<<"New Attack Damage : "<<selin.getAttackDamage()<<std::endl;
	std::cout<<std::endl;
	selin.highFivesGuys();
	
	return (0);
}