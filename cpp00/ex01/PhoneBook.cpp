/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:17:38 by sutku             #+#    #+#             */
/*   Updated: 2023/09/21 18:33:28 by sutku            ###   ########.fr       */
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
		std::cout<<"Information can not be empty. Try again ! "<< std::endl;
		std::cout<<str;
		getline(std::cin, info);
	}
	return(info);
}

void PhoneBook::DisplayPhoneBook(int counter)
{
	int	i = 0;

	while (i < counter)
	{
		std::cout<<arr[i].GetFirstName()<<std::endl;
		std::cout<<arr[i].GetLastName()<<std::endl;
		std::cout<<arr[i].GetNickName()<<std::endl;
		std::cout<<arr[i].GetPhoneNumber()<<std::endl;
		std::cout<<arr[i].GetDarkestSecret()<<std::endl;
		i++;
	}
}