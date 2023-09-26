/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:34:40 by sutku             #+#    #+#             */
/*   Updated: 2023/09/25 17:55:35 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*x;
	int N;
	std::string str;

	std::cout<<"How many zombies do you want to have :  ";
	std::cin >> N;
	std::cin.ignore();
	std::cout<<"What is your zombie's name :  ";
	getline(std::cin, str);
	x = zombieHorde(N, str);
	int i = 0;
	while (i < N)
	{
		x[i].announce();
		i++;
	}
	delete[] x;
	return (0);
}
