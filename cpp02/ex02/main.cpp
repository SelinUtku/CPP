/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:49:17 by sutku             #+#    #+#             */
/*   Updated: 2023/10/07 19:44:08 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed b(Fixed(5.05f) * Fixed(2));
	std::cout<< a <<std::endl;
	std::cout<< ++a <<std::endl;
	std::cout<< a <<std::endl;
	std::cout<< a++ <<std::endl;
	std::cout<< a <<std::endl;
	std::cout << b <<std::endl;
	std::cout<< Fixed::max( a, b ) << std::endl;
	return (0);
}