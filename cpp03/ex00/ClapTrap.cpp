/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:33:10 by sutku             #+#    #+#             */
/*   Updated: 2023/10/08 21:26:56 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout<<this->name<<" object is created"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = copy.getName();
	this->hitPoints = copy.getHitPoints();
	this->energyPoints = copy.getEnergyPoints();
	this->attackDamage = copy.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

// GETTER FUNCTIONS

std::string ClapTrap::getName() const
{
	return (this->name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
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

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout<<"ClapTrap "<<this->name<<" got "<<amount<<" point of demage !"<<std::endl;
	if (this->hitPoints >= amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
	{
		std::cout<<"ClapTrap "<<this->name<<" has no enough energy point to attack !"<<std::endl;
		return ;
	}
	this->hitPoints += amount;
	std::cout<<"ClapTrap "<<this->name<<" "<<amount<<" repaired itself !"<<std::endl;
	this->energyPoints--;
}
