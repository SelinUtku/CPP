/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:15:27 by sutku             #+#    #+#             */
/*   Updated: 2023/12/13 12:34:30 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2)
	{
		std::cout << "\033[0;93mUsage: ./rpn \"[expression]\"\033[0;39m" << std::endl;
		return 0;
	}
	rpn.calculate(argv[1]);
	return 0;
}