/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:50:23 by sutku             #+#    #+#             */
/*   Updated: 2023/09/22 14:59:26 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact 
{
	private:
		std::string firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		// Contact ();
		void	SetFirstName(const std::string &str);
		void	SetLastName(const std::string &str);
		void	SetNickName(const std::string &str);
		void	SetPhoneNumber(const std::string &str);
		void	SetDarkestSecret(const std::string &str);
		std::string	GetFirstName();
		std::string	GetLastName();
		std::string	GetNickName();
		std::string	GetPhoneNumber();
		std::string	GetDarkestSecret();
		// ~Contact ();
};

#endif