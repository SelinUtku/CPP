/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:50:18 by sutku             #+#    #+#             */
/*   Updated: 2023/09/22 14:59:16 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::SetFirstName(const std::string &str)
{
	firstName = str;
}

void	Contact::SetLastName(const std::string &str)
{
	lastName = str;
}

void	Contact::SetNickName(const std::string &str)
{
	nickName = str;
}

void	Contact::SetPhoneNumber(const std::string &str)
{
	phoneNumber = str;
}

void	Contact::SetDarkestSecret(const std::string &str)
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
