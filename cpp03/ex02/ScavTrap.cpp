/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:38:27 by sutku             #+#    #+#             */
/*   Updated: 2023/10/20 11:33:00 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout<<"ScavTrap default constructor called"<<std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string name)
{
	std::cout<<"ScavTrap parameter constructor called"<<std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}
ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout<<"ScavTrap copy assignment operator called"<<std::endl;
	this->setName(copy.getName());
	this->setHitPoints(copy.getHitPoints());
	this->setEnergyPoints(copy.getEnergyPoints());
	this->setAttackDamage(copy.getAttackDamage());
	return(*this);
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout<<"ScavTrap Copy constructor called"<<std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout<<"ScavTrap "<<this->getName()<<" is now in Gate keeper mode."<<std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
	{
		if (this->getEnergyPoints() <= 0)
			std::cout<<"ScavTrap "<<this->getName()<<" has no enough energy point to attack !"<<std::endl;
		else
			std::cout<<"ScavTrap "<<this->getName()<<" has no enough hit points to attack !"<<std::endl;
		return ;
	}
	std::cout<<"ScavTrap "<<this->getName()<<" attacks "<<target<<" causing "<<this->getAttackDamage()<<" points of damage !"<<std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
} 