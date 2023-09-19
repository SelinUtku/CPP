/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:10:33 by sutku             #+#    #+#             */
/*   Updated: 2023/09/19 19:17:07 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	int	flag = 0;

	std::string command;
	PhoneBook	pb;
	Contact		ct;
	while(flag == 0)
	{
		std::cout<<"Please select an option : ADD, SEARCH, EXIT"<< std::endl;
		std::cin>>command;
		if (command.compare("EXIT") == 0)
			flag = 1;
		else if (command.compare("ADD") == 0)
		{
		}
		else if (command.compare("SEARCH") == 0)
		{
			
		}
		else
		{
			std::cout<<"Wrong option, Please try again !"<<std::endl;
		}
	}
	return (0);
} 