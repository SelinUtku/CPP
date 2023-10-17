/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:44:38 by sutku             #+#    #+#             */
/*   Updated: 2023/10/17 08:06:58 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void leaks(void)
{
	system("leaks brain");
}

int main()
{
	atexit(&leaks);
	int i = 0;
	Animal *ptr[10];
	while (i < 10)
	{
		if (i < 5)
			ptr[i] = new Dog;
		else
			ptr[i] = new Cat;
		i++;
	}
	i = -1;
	while (++i < 10)
		delete ptr[i];

	return 0;
}