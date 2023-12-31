/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:41:39 by sutku             #+#    #+#             */
/*   Updated: 2023/09/25 17:55:39 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	// Object is created in stack;
	Zombie x("StackZombie");
	x.announce();

	// Object is created in heap
	Zombie *ptr = newZombie("HeapZombie");
	ptr->announce();
	delete(ptr);
	
	// Random Chump
	randomChump("RandomZombie");
	return (0);
}
