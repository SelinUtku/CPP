/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:47:22 by sutku             #+#    #+#             */
/*   Updated: 2023/12/12 18:17:09 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<double> _stack;
	public:
		RPN();
		RPN(RPN const & src);
		~RPN();

		RPN & operator=(RPN const & src);
		void calculate(std::string input);
		void plus();
		void minus();
		void multiply();
		void divide();

		
};

#endif
