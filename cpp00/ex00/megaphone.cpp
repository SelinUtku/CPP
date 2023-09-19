/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:07:32 by sutku             #+#    #+#             */
/*   Updated: 2023/09/16 16:43:33 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				std::cout<<(char)toupper(argv[i][j]);
				j++;
			}
			i++;
		}
		std::cout<<std::endl;
	}
	return (0);
}
