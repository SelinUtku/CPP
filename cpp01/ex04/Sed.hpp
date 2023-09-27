/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:19:24 by sutku             #+#    #+#             */
/*   Updated: 2023/09/27 14:29:28 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
	private:
		std::string		inputFile;
		std::string		outFile;
	public:
		Sed(std::string fileName);
		~Sed();
		void	replace(std::string s1, std::string s2);
};


#endif