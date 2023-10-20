/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:30:13 by sutku             #+#    #+#             */
/*   Updated: 2023/10/20 10:14:13 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
	
	public:
		ClapTrap(const std::string name);
		//Orthodox Canonical Form
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap& operator=(const ClapTrap &copy);
		~ClapTrap();
		// memnber Functions
		void attack(const std::string& target);
		void takeDamage(int amount);
		void beRepaired(int amount);
		// GETTERS
		std::string getName() const;
		int	getHitPoints() const;
		int	getEnergyPoints() const;
		int	getAttackDamage() const;
		// SETTERS
		void	setName(std::string newName);
		void	setHitPoints(int val);
		void	setEnergyPoints(int val);
		void	setAttackDamage(int val);
};


#endif