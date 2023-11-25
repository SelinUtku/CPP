/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:22:24 by sutku             #+#    #+#             */
/*   Updated: 2023/11/25 15:56:18 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{

    try
	{
        Bureaucrat bureaucrat1("Bur1",5);
        Bureaucrat bureaucrat2("Bur2",150);
		
		ShrubberyCreationForm form1("target1");
        RobotomyRequestForm form2("target2");
		PresidentialPardonForm form3("target3");
		std::cout<<std::endl;
		std::cout<<"\033[32m**Successfully Operations**\033[0m"<<std::endl;
		std::cout<<"\033[34m**Signing Forms**\033[0m"<<std::endl;
		bureaucrat1.signForm(form1);
		bureaucrat1.signForm(form2);
		bureaucrat1.signForm(form3);
		std::cout<<"\033[34m**Executing Forms**\033[0m"<<std::endl;
		bureaucrat1.executeForm(form1);
		bureaucrat1.executeForm(form2);
		bureaucrat1.executeForm(form3);
		std::cout<<std::endl;
	
		std::cout<<"\033[31m**Failed Operations**\033[0m"<<std::endl;
		std::cout<<"\033[34m**Signing Forms**\033[0m"<<std::endl;
		bureaucrat2.signForm(form1);
		bureaucrat2.signForm(form2);
		bureaucrat2.signForm(form3);
		std::cout<<"\033[34m**Executing Forms**\033[0m"<<std::endl;
		bureaucrat2.executeForm(form1);
		bureaucrat2.executeForm(form2);
		bureaucrat2.executeForm(form3);
		std::cout<<std::endl;
		std::cout<<form1<<std::endl;
		std::cout<<form2<<std::endl;
		std::cout<<form3<<std::endl;
    }
	catch (std::exception &e) 
	{
        std::cout << e.what() << std::endl;
    }
    return (0);
}