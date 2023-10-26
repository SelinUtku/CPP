/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:24:49 by sutku             #+#    #+#             */
/*   Updated: 2023/10/26 16:08:05 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
    try 
	{
        Bureaucrat bureaucrat("selin", 10);

        std::cout << bureaucrat << std::endl;
        // bureaucrat.incrementGrade();
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;
    } 
	catch (Bureaucrat::GradeTooHighException &e) 
	{
        std::cout << e.what() << std::endl;
    } 
	catch (Bureaucrat::GradeTooLowException &e) 
	{
        std::cout << e.what() << std::endl;
    }
    return (0);
}