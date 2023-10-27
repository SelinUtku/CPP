/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:24:49 by sutku             #+#    #+#             */
/*   Updated: 2023/10/27 14:40:03 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{

    try
	{
        Bureaucrat bureaucrat("selin",6);
        Form form("blablabla", 10, 5);
        bureaucrat.signForm(form);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
	catch (std::exception &e) 
	{
        std::cout << e.what() << std::endl;
    }
    return (0);
}