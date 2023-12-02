/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:37:04 by sutku             #+#    #+#             */
/*   Updated: 2023/12/02 18:52:39 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main ()
{
	try
	{
		Array<int> arr1(2);
		arr1[0] = 15;
		arr1[1] = 16;
		// arr1[2] = 17;
		Array<int> arr2;
		arr2 = arr1;
		Array<int> arr3(arr2);

		std::cout << arr2[0] << std::endl;
		std::cout << arr2[1] << std::endl;
		std::cout << arr2.size() << std::endl;
		
		std::cout << arr3[0] << std::endl;
		std::cout << arr3[1] << std::endl;
		std::cout << arr3.size() << std::endl;

		
		Array<std::string> arr4(3);
		arr4[0] = "Hello";
		arr4[1] = "World";
		arr4[2] = "!";
		unsigned int i = -1;
		while (++i < arr4.size())
			std::cout << arr4[i] << std::endl;	
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
}