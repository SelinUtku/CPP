/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:45:37 by sutku             #+#    #+#             */
/*   Updated: 2023/11/27 18:57:35 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);
	public:
		static void convert(std::string str);
	class ImpossibleException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};


#endif