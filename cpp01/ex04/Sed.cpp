/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:20:10 by sutku             #+#    #+#             */
/*   Updated: 2023/10/03 14:00:46 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"


Sed::Sed(std::string fileName) : inputFile(fileName)
{
	this->outFile = this->inputFile + ".replace";
}
Sed::~Sed()
{
}

void	Sed::replace(std::string s1, std::string s2)
{
	std::ifstream	inp(this->inputFile);
	std::ofstream	out(this->outFile);
	std::string		line;
	size_t			pos;
	if (!inp)
	{
		std::cerr <<this->inputFile<<" file could not open !" << std::endl;
		exit(1);
	}
	if (!out)
	{
		std::cout <<this->outFile<<" file could not open !" << std::endl;
		exit(1);
	}
	while (getline(inp, line))
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}
		out << line << std::endl;
	}
	inp.close();
	out.close();
}
