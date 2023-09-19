/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:17:38 by sutku             #+#    #+#             */
/*   Updated: 2023/09/19 23:51:57 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::AddNewContact(int index)
{
	Contact newContact;
	std::string str;

	arr[index].SetFirstName(GetValidInput("First Name : "));
	arr[index].SetLastName(GetValidInput("Last Name : "));
	arr[index].SetNickName(GetValidInput("Nick Name : "));
	arr[index].SetPhoneNumber(GetValidInput("Phone Number : "));
	arr[index].SetDarkestSecret(GetValidInput("Darkest Secret : "));
		
}

std::string	PhoneBook::GetValidInput(std::string str)
{
	std::string info;

	std::cout<<str;
	getline(std::cin, info);
	while(info.empty())
	{
		std::cout<<"Information can not be empty. Try again ! "<<std::endl;
		getline(std::cin, info);
	}
	return(info);
}