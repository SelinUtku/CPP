/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:17:55 by sutku             #+#    #+#             */
/*   Updated: 2023/12/12 14:44:23 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	Bitcoin bitcoin;

	if (argc != 2)
	{
		std::cerr << "\033[0;93mUsage: ./bitcoin [filename]\033[0;39m" << std::endl;
		return (1);
	}

	bitcoin.readDataBase();
	bitcoin.readInput(argv);
	
	return (0);
}
