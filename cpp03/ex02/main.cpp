/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:26:23 by sutku             #+#    #+#             */
/*   Updated: 2023/10/20 11:31:10 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap cagatay("Cagatay");
	FragTrap selin("Selin");
	
	std::cout<<std::endl<<"------------Default Cagatay------------"<<std::endl;
	std::cout<<"Hit Point : "<<cagatay.getHitPoints()<<std::endl;
	std::cout<<"Energy Point : "<<cagatay.getEnergyPoints()<<std::endl;
	std::cout<<"Attack Damage : "<<cagatay.getAttackDamage()<<std::endl;
	std::cout<<std::endl<<"------------Default Selin------------"<<std::endl;
	std::cout<<"Hit Point : "<<selin.getHitPoints()<<std::endl;
	std::cout<<"Energy Point : "<<selin.getEnergyPoints()<<std::endl;
	std::cout<<"Attack Damage : "<<selin.getAttackDamage()<<std::endl;
	std::cout<<std::endl;
	
	selin.attack("Cagatay");
	cagatay.takeDamage(selin.getAttackDamage());
	cagatay.attack("Selin");
	selin.takeDamage(cagatay.getAttackDamage());
	cagatay.beRepaired(40);
	selin.beRepaired(20);
	cagatay.guardGate();
	selin.highFivesGuys();
	
	std::cout<<std::endl<<"AFTER"<<std::endl;
	std::cout<<"---------cagatay----------"<<std::endl;
	std::cout<<"Hit Point : "<<cagatay.getHitPoints()<<std::endl;
	std::cout<<"Energy Point : "<<cagatay.getEnergyPoints()<<std::endl;
	std::cout<<"Attack Damage : "<<cagatay.getAttackDamage()<<std::endl;
	std::cout<<"---------selin----------"<<std::endl;
	std::cout<<"Hit Point : "<<selin.getHitPoints()<<std::endl;
	std::cout<<"Energy Point : "<<selin.getEnergyPoints()<<std::endl;
	std::cout<<"Attack Damage : "<<selin.getAttackDamage()<<std::endl;
	std::cout<<std::endl;
	return (0);
}
