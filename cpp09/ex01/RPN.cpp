/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:48:53 by sutku             #+#    #+#             */
/*   Updated: 2023/12/13 12:31:44 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	return;
}

RPN::RPN(RPN const &copy)
{
	*this = copy;
	return;
}

RPN::~RPN()
{
	return;
}

RPN & RPN::operator=(RPN const &copy)
{
	if (this != &copy)
	{
		_stack = copy._stack;	
	}
	return *this;
}

void RPN::plus()
{
	double a;
	double b;

	if (_stack.size() < 2)
	{
		std::cout << "Not enough values in stack" << std::endl;
		return ;
	}
	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();
	_stack.push(a + b);
}

void RPN::minus()
{
	double a;
	double b;

	if (_stack.size() < 2)
	{
		std::cout << "Not enough values in stack" << std::endl;
		return ;
	}
	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();
	_stack.push(b - a);
}

void RPN::multiply()
{
	double a;
	double b;

	if (_stack.size() < 2)
	{
		std::cout << "Not enough values in stack" << std::endl;
		return ;
	}
	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();
	_stack.push(a * b);
}

void RPN::divide()
{
	double a;
	double b;

	if (_stack.size() < 2)
	{
		std::cout << "Not enough values in stack" << std::endl;
		return ;
	}
	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();
	_stack.push(b / a);
}

void RPN::calculate(std::string input)
{
	for(size_t i = 0; i < input.length(); i++)
	{

		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			if (input[i] == '+')
				plus();
			else if (input[i] == '-')
				minus();
			else if (input[i] == '*')
				multiply();
			else if (input[i] == '/')
				divide();
		}
		else if (isdigit(input[i]))
			_stack.push(input[i] - '0');
		else if (input[i] != ' ')
		{
			std::cout << "Invalid character" << std::endl;
			return ;
		}

	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else if (_stack.size() > 1)
		std::cout << "Too many values in stack" << std::endl;
	else
		std::cout << "Not enough values in stack" << std::endl;
}

