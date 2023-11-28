/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:50:22 by sutku             #+#    #+#             */
/*   Updated: 2023/11/28 14:54:02 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &copy)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = copy;
}

Serializer &Serializer::operator=(Serializer const &copy)
{
	std::cout << "Serializer assignation operator called" << std::endl;
	(void)copy;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}


uintptr_t Serializer::serialize(t_data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<t_data*>(raw));
}

