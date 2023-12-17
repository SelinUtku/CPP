/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:32:00 by sutku             #+#    #+#             */
/*   Updated: 2023/12/15 18:16:07 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv)
{

	if (argc < 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	PmergeMe p(argv);
	
	return (0);
}