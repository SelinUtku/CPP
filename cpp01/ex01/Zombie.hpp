/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:23:39 by sutku             #+#    #+#             */
/*   Updated: 2023/09/25 17:42:56 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie()
		{
			std::cout<<"Default constructer has been created"<<std::endl;
		}
		// Zombie(std::string name)
		// {
		// 	this->name = name;
		// }
		~Zombie()
		{
			std::cout<<this->name<<" is destroyed"<<std::endl;
		}
		void	setName(std::string name);
		void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif