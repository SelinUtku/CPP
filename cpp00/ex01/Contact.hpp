/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:50:23 by sutku             #+#    #+#             */
/*   Updated: 2023/09/19 19:02:51 by sutku            ###   ########.fr       */
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
		void	SetFirstName(std::string str);
		void	SetLasttName(std::string str);
		void	SetNickName(std::string str);
		void	SetPhoneNumber(std::string str);
		void	SetDarkestSecret(std::string str);
		// ~Contact ();
};

#endif