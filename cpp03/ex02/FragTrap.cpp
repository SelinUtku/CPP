/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:38:27 by sutku             #+#    #+#             */
/*   Updated: 2023/10/16 12:40:05 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout<<"FragTrap default constructor called"<<std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout<<"FragTrap parameter constructor called"<<std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}
FragTrap& FragTrap::operator=(const FragTrap &copy)
{
	std::cout<<"FragTrap copy assignment operator called"<<std::endl;
	this->setName(copy.getName());
	this->setHitPoints(copy.getHitPoints());
	this->setEnergyPoints(copy.getEnergyPoints());
	this->setAttackDamage(copy.getAttackDamage());
	return(*this);
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout<<"FragTrap Copy constructor called"<<std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout<<"FragTrap is giving you high five ! ."<<std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
	{
		if (this->getEnergyPoints() <= 0)
			std::cout<<"FragTrap "<<this->getName()<<" has no enough energy point to attack !"<<std::endl;
		else
			std::cout<<"FragTrap "<<this->getName()<<" has no enough hit point to attack !"<<std::endl;
		return ;
	}
	std::cout<<"FragTrap "<<this->getName()<<" attacks "<<target<<" causing "<<this->getAttackDamage()<<" points of damage !"<<std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
} 