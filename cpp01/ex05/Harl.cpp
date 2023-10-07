/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:21:08 by sutku             #+#    #+#             */
/*   Updated: 2023/10/03 17:57:01 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"<<std::endl;
}

void Harl::info(void)
{
	std::cout<<"I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!"<<std::endl;
}

void Harl::warning(void)
{
	std::cout<<"I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month."<<std::endl;
}

void Harl::error(void)
{
	std::cout<<"This is unacceptable, I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*fptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i = 0;
	while (i < 4)
	{
		if (levels[i].compare(level) == 0)
		{
			(this->*fptr[i])();
			return ;
		}
		i++;
	}
	std::cout<<"Invalid level"<<std::endl;
}
