/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:54:54 by sutku             #+#    #+#             */
/*   Updated: 2023/12/02 17:19:39 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	std::string str[3] = {"hello", "world", "!"};
	
	iter(arr, 5, increase);
	iter(str, 3, doCapital);
	// should work with any function ?

	return (0);
}