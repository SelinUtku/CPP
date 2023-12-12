/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:01:08 by sutku             #+#    #+#             */
/*   Updated: 2023/12/09 16:04:53 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
void easyfind(T &container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		std::cout << "Found '" << n << "'" <<std::endl;
	else
		throw std::exception();
}


#endif