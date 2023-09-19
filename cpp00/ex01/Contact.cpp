/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:50:18 by sutku             #+#    #+#             */
/*   Updated: 2023/09/19 23:21:23 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::SetFirstName(std::string str)
{
	firstName = str;
	std::cout<<firstName;
}

void	Contact::SetLastName(std::string str)
{
	lastName = str;
	std::cout<<lastName;

}

void	Contact::SetNickName(std::string str)
{
	nickName = str;
	std::cout<<nickName;
}

void	Contact::SetPhoneNumber(std::string str)
{
	phoneNumber = str;
	std::cout<<phoneNumber;
}

void	Contact::SetDarkestSecret(std::string str)
{
	darkestSecret = str;
	std::cout<<darkestSecret;
}
