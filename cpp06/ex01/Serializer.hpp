/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:47:25 by sutku             #+#    #+#             */
/*   Updated: 2023/11/28 14:53:18 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
#include <stdint.h>

typedef struct s_data
{
	std::string str;
}t_data;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &copy);
		Serializer &operator=(Serializer const &copy);
		~Serializer();

	public:
		static uintptr_t serialize(t_data* ptr);
		static t_data* deserialize(uintptr_t raw);
};

#endif