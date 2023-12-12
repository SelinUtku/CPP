/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:12:00 by sutku             #+#    #+#             */
/*   Updated: 2023/12/11 10:52:51 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
// #include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	const MutantStack<int> mstack2(mstack);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "stack: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	while (!s.empty())
	{
		std::cout << "s.top(): " << s.top() << std::endl;
		s.pop();
	}
	// std::list<int> mstack;
	// mstack.push_back(5);
	// mstack.push_back(17);
	// std::cout << "top: " << mstack.back() << std::endl;
	// mstack.pop_back();
	// std::cout << "size: " << mstack.size() << std::endl;
	// mstack.push_back(3);
	// mstack.push_back(5);
	// mstack.push_back(737);
	// mstack.push_back(0);
	// const std::list<int> mstack2(mstack);
	// std::list<int>::iterator it = mstack.begin();
	// std::list<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// std::cout << "list: ";
	// while (it != ite)
	// {
	// 	std::cout << *it << " ";
	// 	++it;
	// }
	// std::cout << std::endl;
	// std::list<int> s(mstack);
	// while (!s.empty())
	// {
	// 	std::cout << "top(): " << s.back() << std::endl;
	// 	s.pop_back();
	// }
	return 0;
}
