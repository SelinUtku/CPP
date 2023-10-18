/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:26:27 by sutku             #+#    #+#             */
/*   Updated: 2023/10/18 15:26:07 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void leaks(void)
{
	system("leaks materials");
}

int main()
{
	atexit(&leaks);
	IMateriaSource* src = new MateriaSource();
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	// std::cout<<tmp<<std::endl;
	me->equip(tmp);
	me->unequip(0);
	me->unequip(1);
	// std::cout<<tmp<<std::endl;
	// ICharacter* bob = new Character("bob");
	// delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;
	// tmp = new Ice();
	return 0;
}

