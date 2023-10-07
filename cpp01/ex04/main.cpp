/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:17:03 by sutku             #+#    #+#             */
/*   Updated: 2023/10/03 14:01:50 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout <<"Usage: ./replace <filename> <s1> <s2>"<< std::endl;
		return (1);
	}
	Sed	sed(argv[1]);
	sed.replace(argv[2], argv[3]);
	return (0);
}
