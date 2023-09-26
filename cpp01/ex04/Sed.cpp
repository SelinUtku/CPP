/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:20:10 by sutku             #+#    #+#             */
/*   Updated: 2023/09/26 19:48:26 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"


Sed::Sed(std::string fileName, std::string s1, std::string s2)
{
	this->fileName = fileName;
	this->s1 = s1;
	this->s2 = s2;
}
Sed::~Sed()
{
}

