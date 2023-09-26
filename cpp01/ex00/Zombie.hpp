/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:23:37 by sutku             #+#    #+#             */
/*   Updated: 2023/09/24 18:55:50 by sutku            ###   ########.fr       */
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
		Zombie(std::string name)
		{
			this->name = name;
		}
		~Zombie()
		{
			std::cout<<this->name<<" is destroyed"<<std::endl;
		}
		void	announce(void);
};
	Zombie* newZombie(std::string name);
	void	randomChump(std::string name );

#endif