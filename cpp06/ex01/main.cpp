/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:54:08 by sutku             #+#    #+#             */
/*   Updated: 2023/11/28 15:02:03 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	t_data *data = new t_data;
	
	data->str = "blablabla";
	std::cout <<"Data Content:\t"<< data->str << std::endl;
	std::cout <<"Data Address:\t"<< data << std::endl;
	
	uintptr_t raw = Serializer::serialize(data);
	std::cout <<"Raw Address:\t"<< raw << std::endl;
	
	t_data *data2 = Serializer::deserialize(raw);
	std::cout <<"Data2 Content:\t"<< data2->str << std::endl;
	std::cout <<"Data2 Address:\t"<< data2 << std::endl;
	
	delete data;
	return (0);
}
