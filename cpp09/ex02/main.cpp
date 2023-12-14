/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:32:00 by sutku             #+#    #+#             */
/*   Updated: 2023/12/14 16:15:20 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	PmergeMe p;

	if (argc < 2)
		return (0);

	p.readInput(argv);
	p.makePairs();
	p.mergePairs();
	p.createChains();
	


	// std::vector<std::pair<unsigned int, unsigned int> >::iterator it = p._pairs.begin();
	// while (it != p._pairs.end())
	// {
	// 	std::cout << it->first << " " << it->second << std::endl;
	// 	it++;
	// }
	return (0);

}