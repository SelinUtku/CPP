/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:23:12 by sutku             #+#    #+#             */
/*   Updated: 2023/09/26 15:40:13 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


void	HumanA::attack()
{
	std::cout<<this->name<<" attacks with their "<<this->a.getType()<<std::endl;
}
