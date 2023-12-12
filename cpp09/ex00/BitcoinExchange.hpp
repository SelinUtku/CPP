/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:03:05 by sutku             #+#    #+#             */
/*   Updated: 2023/12/12 14:48:28 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <stdlib.h>
#include <fstream>

class Bitcoin
{
	private:
		std::map<std::string, float> _dataBase;
	public:
		Bitcoin();
		Bitcoin(const Bitcoin &copy);
		~Bitcoin();
		Bitcoin &operator=(const Bitcoin &copy);

		void addData(std::string date, float price);
		void readInput(char **argv);
		void isValidDate(std::string date);
		float isValidPrice(std::string price);
		void calculatePrice(std::string date, float price);
		void readDataBase();
		class InvalidDateException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class InvalidPriceException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif