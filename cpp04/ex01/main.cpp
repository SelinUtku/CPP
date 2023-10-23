/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:44:38 by sutku             #+#    #+#             */
/*   Updated: 2023/10/23 13:17:37 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int i = 0;
	Animal *ptr[6];
	while (i < 6)
	{
		if (i < 3)
			ptr[i] = new Dog;
		else
			ptr[i] = new Cat;
		i++;
	}
	i = -1;
	while (++i < 6)
		delete ptr[i];

	// Dog *tmp = new Dog();
	// Dog *tmp2 = new Dog(*tmp2);
	

	// delete tmp;
	// delete tmp2;
//-----------------------------------
	// Dog *tmp = new Dog();
	// Dog *tmp2 = new Dog();
	
	// *tmp = *tmp2;

	// delete tmp;
	// delete tmp2;
	return 0;
}
