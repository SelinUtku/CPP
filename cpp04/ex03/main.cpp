/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:26:27 by sutku             #+#    #+#             */
/*   Updated: 2023/10/20 08:12:53 by sutku            ###   ########.fr       */
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
	AMateria	*tmp;
	AMateria	*ice;
	AMateria	*cure;
	AMateria	*del;
	ICharacter	*me;
	
	IMateriaSource* src = new MateriaSource();
	ice = new Ice();
	cure = new Cure();
	me = new Character("me");

	src->learnMateria(ice);
	src->learnMateria(cure);
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// unequip
	// del = ((Character *)me)->getInventory(0);
	// me->unequip(0);
	// delete(del);
	// del = ((Character *)me)->getInventory(1);
	// me->unequip(1);
	// delete(del);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;
	return 0;
}

