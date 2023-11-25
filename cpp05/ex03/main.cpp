/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:22:24 by sutku             #+#    #+#             */
/*   Updated: 2023/11/25 16:39:17 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{

    try
	{
        Bureaucrat bureaucrat1("Bur1",5);
        Bureaucrat bureaucrat2("Bur2",150);
		Intern intern;
		AForm *form1 = intern.makeForm("ShrubberyCreation", "target1");
		AForm *form2 = intern.makeForm("RobotomyRequest", "target2");
		AForm *form3 = intern.makeForm("PresidentialPardon", "target3");
		// AForm *form4 = intern.makeForm("invalid", "target4");
		
		std::cout<<std::endl;
		std::cout<<"\033[32m** Successfull Operations **\033[0m"<<std::endl;
		std::cout<<"\033[34m** Signing Forms **\033[0m"<<std::endl;
		bureaucrat1.signForm(*form1);
		bureaucrat1.signForm(*form2);
		bureaucrat1.signForm(*form3);
		std::cout<<"\033[34m** Executing Forms **\033[0m"<<std::endl;
		bureaucrat1.executeForm(*form1);
		bureaucrat1.executeForm(*form2);
		bureaucrat1.executeForm(*form3);
		std::cout<<std::endl;
	
		std::cout<<"\033[31m** Failed Operations **\033[0m"<<std::endl;
		std::cout<<"\033[34m** Signing Forms **\033[0m"<<std::endl;
		bureaucrat2.signForm(*form1);
		bureaucrat2.signForm(*form2);
		bureaucrat2.signForm(*form3);
		std::cout<<"\033[34m** Executing Forms **\033[0m"<<std::endl;
		bureaucrat2.executeForm(*form1);
		bureaucrat2.executeForm(*form2);
		bureaucrat2.executeForm(*form3);
		std::cout<<std::endl;
		
		std::cout<<"\033[34m** FORM INFORMATIONS **\033[0m"<<std::endl;
		std::cout<<*(form1)<<std::endl;
		std::cout<<*(form2)<<std::endl;
		std::cout<<*(form3)<<std::endl;
		std::cout<<std::endl;
		delete form1;
		delete form2;
		delete form3;
		// delete form4;
		
    }
	catch (std::exception &e) 
	{
        std::cout << e.what() << std::endl;
    }
    return (0);
}