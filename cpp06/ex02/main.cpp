/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:10:17 by sutku             #+#    #+#             */
/*   Updated: 2023/12/02 12:40:41 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate()
{
	int i = rand() % 3;

	if (i == 0)
	{
		std::cout << "\033[35mA is generated\033[0m" << std::endl;
		return (new A);
	}
	else if (i == 1)
	{
		std::cout << "\033[35mB is generated\033[0m"<< std::endl;
		return (new B);
	}
	else
	{
		std::cout << "\033[35mC is generated\033[0m" << std::endl;
		return (new C);
	}
}

void identifyFromPointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer is type of A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer is type of B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer is type of C" << std::endl;
	else
		std::cout << "Pointer is not type of A, B or C" << std::endl;
}

void identifyFromObject(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Object is type of A" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Object is type of B" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Object is type of C" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}

}

int main()
{
	srand(time(NULL));

	Base *base = generate();
	identifyFromPointer(base);
	identifyFromObject(*base);

	delete base;
	return (0);
}