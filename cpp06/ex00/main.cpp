/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:58:50 by sutku             #+#    #+#             */
/*   Updated: 2023/11/27 18:52:24 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[33mUsage: ./convert [string]\033[0m" << std::endl;
		return (1);
	}
	std::cout << std::fixed;
	ScalarConverter::convert(argv[1]);
	
	
	return (0);
}