/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:10:33 by sutku             #+#    #+#             */
/*   Updated: 2023/09/23 18:14:57 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	int	counter = 0;
	int	display = 0;
	std::string command;
	PhoneBook	pb;

	while (1)
	{
		std::cout<<"Please select an option : ADD / SEARCH / EXIT"<< std::endl;
		getline(std::cin, command);
		if (command.compare("EXIT") == 0 || std::cin.eof())
			return (0);
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
			std::cerr<<"Wrong option, Please try again !"<<std::endl;
	}
	return (0);
} 
