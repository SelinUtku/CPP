/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:28:51 by sutku             #+#    #+#             */
/*   Updated: 2023/09/22 16:06:20 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact arr[8];
	public:
		void AddNewContact(int index);
		void DisplayPhoneBook(int counter);
		void DisplayPerson(int counter);
		std::string GetValidInput(const std::string &str);
};

#endif