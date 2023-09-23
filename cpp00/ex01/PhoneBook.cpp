/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:17:38 by sutku             #+#    #+#             */
/*   Updated: 2023/09/23 18:19:12 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::AddNewContact(int index)
{
	std::string str;

	arr[index].SetFirstName(GetValidInput("First Name : "));
	arr[index].SetLastName(GetValidInput("Last Name : "));
	arr[index].SetNickName(GetValidInput("Nick Name : "));
	arr[index].SetPhoneNumber(GetValidInput("Phone Number : "));
	arr[index].SetDarkestSecret(GetValidInput("Darkest Secret : "));
}

std::string	PhoneBook::GetValidInput(const std::string &str)
{
	std::string info;

	std::cout<<str;
	getline(std::cin, info);
	while(info.empty())
	{
		if (std::cin.eof())
			exit(1);
		std::cerr<<"Information can not be empty. Try again ! "<< std::endl;
		std::cout<<str;
		getline(std::cin, info);
	}
	return(info);
}

void	PhoneBook::DisplayPhoneBook(int index)
{
	int	i = -1;

	while (++i < index)
	{
		std::cout<<std::setw(9)<<(i + 1)<<'|';
		if (arr[i].GetFirstName().length() > 10)
			std::cout<<std::setw(9)<<(arr[i].GetFirstName()).substr(0, 9)<<'.';
		else
			std::cout<<std::setw(10)<<(arr[i].GetFirstName());
		std::cout<<'|';
		if (arr[i].GetLastName().length() > 10)
			std::cout<<std::setw(9)<<(arr[i].GetLastName()).substr(0, 9)<<'.';
		else
			std::cout<<std::setw(10)<<(arr[i].GetLastName());
		std::cout<<'|';
		if (arr[i].GetNickName().length() > 10)
			std::cout<<std::setw(9)<<(arr[i].GetNickName()).substr(0, 9)<<'.';
		else
			std::cout<<std::setw(10)<<(arr[i].GetNickName());
		std::cout<<'|'<<std::endl;
	}
	DisplayPerson(index);
}

void	PhoneBook::DisplayPerson(int index)
{
	std::string opt;
	bool valid = false;
	int	i;

	if (index == 0)
	{
		std::cerr<<"PhoneBook is empty !"<<std::endl;
		return ;
	}
	while (valid == false)
	{
		std::cout<<"Please select the index you would like to display : ";
		getline(std::cin, opt);
		if (std::cin.eof())
			exit(1);
		try
		{
			i = std::stoi(opt) - 1;
			if (i < 0 || i > index - 1)
				std::cerr<<"Invalid index ! Try again."<<std::endl;
			else
				valid = true;
		}
		catch(...)
		{
			std::cerr<< "Invalid Argument ! Try again."<<std::endl;
		}
	}
	DisplayPersonInformations(i);
}

void	PhoneBook::DisplayPersonInformations(int i)
{
	std::cout<<"First Name : "<<arr[i].GetFirstName()<<std::endl;
	std::cout<<"Last Name : "<<arr[i].GetLastName()<<std::endl;
	std::cout<<"Nick Name : "<<arr[i].GetNickName()<<std::endl;
	std::cout<<"Phone Number : "<<arr[i].GetPhoneNumber()<<std::endl;
	std::cout<<"Darkest Secret : "<<arr[i].GetDarkestSecret()<<std::endl;
}
