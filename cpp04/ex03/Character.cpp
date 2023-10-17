/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:39:38 by sutku             #+#    #+#             */
/*   Updated: 2023/10/17 18:27:32 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout<<"Character default Constructor called"<<std::endl;
	int i = -1;
	while (i < 4)
		this->inventory[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
	std::cout<<"Character parameter Constructor called"<<std::endl;
	int i = -1;
	while (i < 4)
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
	while (++i < 4)
		this->inventory[i] = copy.inventory[i];
	return (*this);
}

Character::~Character()
{
	std::cout<<"Character default constructor called"<<std::endl;
}

std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	int i = 0;
	while (i < 4 && this->inventory[i] != NULL)
		i++;
	if (i == 4)
		std::cerr<<"Inventory is full. You can not equip more !"<<std::endl;
	else
		this->inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
		std::cerr<<"Given index is wrong !"<<std::endl;
	else if (this->inventory[0] == NULL)
		std::cerr<<"Inventory is empty. You can not unequip !"<<std::endl;
	else
	{
		int i, j = 0;
		AMateria *temp[4];
		while (i < 4 && j < 4)
		{
			if (j != idx)
				temp[i] = this->inventory[j];
			else
				j++;
			i++;
		}
		this->inventory[idx] = NULL;
		this->inventory = temp;//// why ????
	}
	

}

void Character::use(int idx, ICharacter &target)
{
	
}