/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:19:24 by sutku             #+#    #+#             */
/*   Updated: 2023/09/26 19:48:32 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
	private:
		std::string		fileName;
		std::string		s1;
		std::string		s2;
	public:
		Sed(std::string fileName, std::string s1, std::string s2);
		~Sed();
		void	replace();
}


#endif