/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:39:38 by sutku             #+#    #+#             */
/*   Updated: 2023/10/20 08:14:38 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout<<"Character default constructor called"<<std::endl;
	int i = -1;
	while (++i < 4)
		this->inventory[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
	std::cout<<"Character parameter constructor called"<<std::endl;
	int i = -1;
	while (++i < 4)
		this->inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	std::cout<<"Character copy constructor called"<<std::endl;
	*this = copy;
}

Character& Character::operator=(const Character &copy)
{
	std::cout<<"Character copy assignment operator called" << std::endl;
	this->name = copy.getName();
	int i = -1;
	if (this != &copy)
	{
		while (++i < 4)
			delete this->inventory[i];
	}
	i = -1;
	while (++i < 4)
		this->inventory[i] = copy.inventory[i]->clone();
	return (*this);
}

std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;
	int i = 0;
	while (i < 4 && this->inventory[i] != NULL)
		i++;
	if (i == 4)
		std::cerr<<this->name<<" can not equip "<<m->getType()<<". Inventory is full."<<std::endl;
	else
	{
		this->inventory[i] = m;
		std::cerr<<this->name<<" equipped "<<m->getType()<<std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
		std::cerr<<"Given index is wrong !"<<std::endl;
	else if (this->inventory[idx] == NULL)
		std::cerr<<this->name<<" can not unequip."<<std::endl;
	else
	{
		std::cout<<this->name<<" unequipped "<<(this->inventory[idx]->getType())<<std::endl;
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >=0 && idx <= 3 && this->inventory[idx] != NULL)
	{
		std::cout<<this->name<<" is using "<<this->inventory[idx]->getType()<<std::endl;
		this->inventory[idx]->use(target);
	}
}


AMateria*::Character::getInventory(int idx)
{
	if (idx >= 0 && idx <=3)
		return (this->inventory[idx]);
	return (NULL);
}

Character::~Character()
{
	std::cout<<"Character default constructor called"<<std::endl;
	int i = -1;
	while (++i < 4)
	{
		if (this->inventory[i] != NULL)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}
