/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:34:40 by sutku             #+#    #+#             */
/*   Updated: 2023/10/03 16:22:01 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*x;
	int N = 5;

	x = zombieHorde(N, "Selin");
	int i = 0;
	while (i < N)
	{
		x[i].announce();
		i++;
	}
	delete[] x;
	return (0);
}
