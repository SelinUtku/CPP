/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:54:54 by sutku             #+#    #+#             */
/*   Updated: 2023/12/05 16:57:14 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	std::string str[3] = {"hello", "world", "!"};
	
	iter(arr, 5, increase);
	iter(str, 3, doCapital);
	iter(arr, 5, print);
	iter(str, 3, print);

	return (0);
}
