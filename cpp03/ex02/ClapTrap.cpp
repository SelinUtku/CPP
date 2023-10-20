/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:33:10 by sutku             #+#    #+#             */
/*   Updated: 2023/10/20 11:04:28 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout<<"ClapTrap Default constructor called"<<std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout<<"ClapTrap Object "<<this->name<<" is created"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout<<"ClapTrap Copy constructor called"<<std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	this->name = copy.getName();
	this->hitPoints = copy.getHitPoints();
	this->energyPoints = copy.getEnergyPoints();
	this->attackDamage = copy.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

// GETTER FUNCTIONS

std::string ClapTrap::getName() const
{
	return (this->name);
}

int ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

// SETTER FUNCTIONS

void ClapTrap::setName(std::string newName)
{
	this->name = newName;
}

void ClapTrap::setHitPoints(int val)
{
	if (val < 0)
		this->hitPoints = 0;
	else
		this->hitPoints = val;
}

void ClapTrap::setEnergyPoints(int val)
{
	if (val < 0)
		this->energyPoints = 0;
	else
		this->energyPoints = val;
}

void ClapTrap::setAttackDamage(int val)
{
	if (val < 0)
		this->attackDamage = 0;
	else
		this->attackDamage = val;
}

// MEMBER FUNCTIONS

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		if (energyPoints <= 0)
			std::cout<<"ClapTrap "<<this->name<<" has no enough energy point to attack !"<<std::endl;
		else
			std::cout<<"ClapTrap "<<this->name<<" has no enough hit point to attack !"<<std::endl;
		return ;
	}
	std::cout<<"ClapTrap "<<this->name<<" attacks "<<target<<" causing "<<this->attackDamage<<" points of damage !"<<std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(int amount)
{
	if (amount >= 0)
	{
		std::cout<<"ClapTrap "<<this->name<<" got "<<amount<<" points of damage !"<<std::endl;
		if (this->hitPoints >= amount)
			this->hitPoints -= amount;
		else
			this->hitPoints = 0;
	}
}

void ClapTrap::beRepaired(int amount)
{
	if (amount >= 0)
	{
		if (this->hitPoints == 0)
		{
			std::cout<<"ClapTrap "<<this->name<<" has no enough hit points to be repaired !"<<std::endl;
			return ;
		}
		if (this->energyPoints <= 0)
		{
			std::cout<<"ClapTrap "<<this->name<<" has no enough energy point to be repaired !"<<std::endl;
			return ;
		}
		this->hitPoints += amount;
		std::cout<<"ClapTrap "<<this->name<<" "<<amount<<" repaired itself !"<<std::endl;
		this->energyPoints--;
	}
}
