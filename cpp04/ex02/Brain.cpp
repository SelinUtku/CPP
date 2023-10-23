/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:41:55 by sutku             #+#    #+#             */
/*   Updated: 2023/10/23 11:08:22 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"Brain Default Constructor called"<<std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout<<"Brain copy constructor called"<<std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
	std::cout<<"Brain copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		int	i = -1;
		while (++i < 100)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout<<"Brain Destructor called"<<std::endl;
}