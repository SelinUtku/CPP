/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:10:33 by sutku             #+#    #+#             */
/*   Updated: 2023/09/22 16:26:41 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	int	flag = 0;
	int	counter = 0;
	int	display = 0;
	std::string command;
	PhoneBook	pb;

	while(flag == 0)
	{
		std::cout<<"Please select an option : ADD, SEARCH, EXIT"<< std::endl;
		getline(std::cin, command);
		if (command.compare("EXIT") == 0 || std::cin.eof())
			flag = 1;
		else if (command.compare("ADD") == 0)
		{
			pb.AddNewContact(counter);
			display++;
			counter++;
			counter %= 8;
		}
		else if (command.compare("SEARCH") == 0)
		{
			if (display > 8)
				display = 8;
			pb.DisplayPhoneBook(display);
		}
		else
			std::cout<<"Wrong option, Please try again !"<<std::endl;
	}
	return (0);
} 
