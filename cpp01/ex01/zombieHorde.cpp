/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:24:50 by sutku             #+#    #+#             */
/*   Updated: 2023/10/03 13:08:18 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *ptr;
	int	i = 0;

	ptr = new Zombie[N];
	while (i < N)
	{
		ptr[i].setName(name);
		i++;
	}
	return (ptr);
}
