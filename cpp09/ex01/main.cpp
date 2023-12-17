/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:15:27 by sutku             #+#    #+#             */
/*   Updated: 2023/12/15 19:48:08 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "\033[0;93mUsage: ./RPN \"[expression]\"\033[0;39m" << std::endl;
		return 0;
	}
	RPN rpn;
	rpn.calculate(argv[1]);

	return (0);
}
