/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:50:18 by sutku             #+#    #+#             */
/*   Updated: 2023/09/21 18:29:10 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::SetFirstName(std::string str)
{
	firstName = str;
}

void	Contact::SetLastName(std::string str)
{
	lastName = str;
}

void	Contact::SetNickName(std::string str)
{
	nickName = str;
}

void	Contact::SetPhoneNumber(std::string str)
{
	phoneNumber = str;
}

void	Contact::SetDarkestSecret(std::string str)
{
	darkestSecret = str;
}


//GETTER

std::string	Contact::GetFirstName()
{
	return(firstName);
}

std::string	Contact::GetLastName()
{
	return(lastName);
}

std::string	Contact::GetNickName()
{
	return(nickName);
}

std::string	Contact::GetPhoneNumber()
{
	return(phoneNumber);
}

std::string	Contact::GetDarkestSecret()
{
	return(darkestSecret);
}
