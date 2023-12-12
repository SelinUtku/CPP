/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:15:27 by sutku             #+#    #+#             */
/*   Updated: 2023/12/12 18:15:52 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2)
	{
		std::cout << "Usage: ./rpn \"[expression]\"" << std::endl;
		return 0;
	}
	rpn.calculate(argv[1]);
	return 0;
}