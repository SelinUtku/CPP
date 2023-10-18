/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:39:42 by sutku             #+#    #+#             */
/*   Updated: 2023/10/18 15:05:54 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout<<"MateriaSource default constructor called"<<std::endl;
	int i = -1;
	while (++i < 4)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	// std::cout<<"MateriaSource copy constructor called"<<std::endl;
	*this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
	// std::cout<<"MateriaSource copy assignment operator called" << std::endl;
	int i = -1;
	if (this != &copy)
	{
		while (++i < 4)
			delete this->materias[i];
	}	
	i = -1;
	while (++i < 4)
		this->materias[i] = copy.materias[i]->clone();
	return (*this);
}

void MateriaSource::learnMateria(AMateria *bulls)
{
	int i = 0;
	while (i < 4 && this->materias[i] != NULL)
		i++;
	if (i == 4)
		std::cerr<<"Materias is full."<<std::endl;
	else
		this->materias[i] = bulls->clone();
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	int i = -1;

	while (++i < 4 )
	{
		if (this->materias[i] && this->materias[i]->getType() == type)
			return (this->materias[i]->clone());
	}
	std::cerr<<type<<" did not learned yet."<<std::endl;
	return (0);
}

MateriaSource::~MateriaSource()
{
	// std::cout<<"MateriaSource default constructor called"<<std::endl;
	int i = -1;
	while (++i < 4)
		if (this->materias[i] != NULL)
		{
			delete this->materias[i];
			this->materias[i] = NULL;
		}
}
