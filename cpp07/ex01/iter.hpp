/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:45:06 by sutku             #+#    #+#             */
/*   Updated: 2023/12/02 17:51:06 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cctype>

template <typename T>
void increase(T const &x)
{
	std::cout << x + 1 << std::endl;
}

template <typename T>
void doCapital(T const &x)
{
	std::string str = x;
	int i = -1;
	while (str[++i])
		std::cout << (char)std::toupper(str[i]);
	std::cout << std::endl;
}

template <typename T>
void iter(T *array, int length, void (*f)(T const &))
{
	int i = -1;

	while (++i < length)
		f(array[i]);
}


#endif