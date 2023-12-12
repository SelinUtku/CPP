/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:14:37 by sutku             #+#    #+#             */
/*   Updated: 2023/12/11 09:36:20 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
	std::cout << "Span parameter constructor called" << std::endl;
}

Span::Span(const Span &copy)
{
	*this = copy;
	std::cout << "Span copy constructor called" << std::endl;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		this->_set.clear();
		this->_set.insert(copy._set.begin(), copy._set.end());
		this->_N = copy._N;
	}
	std::cout << "Span copy assignment operator called" << std::endl;
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

const char *Span::spanIsFullException::what() const throw()
{
	return ("Span is full !");
}

const char *Span::spanIsNotEnoughException::what() const throw()
{
	return ("Span is not enough !");
}

void Span::addNumber(int n)
{
	if (_set.size() < _N)
		_set.insert(n);
	else
		throw (Span::spanIsFullException());
}

int Span::longestSpan()
{
	if (_set.size() < 2)
		throw (Span::spanIsNotEnoughException());
	return (*(_set.rbegin()) - *(_set.begin()));
}

int Span::shortestSpan()
{
	if (_set.size() < 2)
		throw (Span::spanIsNotEnoughException());
	std::multiset<int>::iterator it = _set.begin();
	std::multiset<int>::iterator it2 = _set.begin();
	it2++;
	int min = *it2 - *it;
	while (it2 != _set.end())
	{
		if (*it2 - *it < min)
			min = *it2 - *it;
		it++;
		it2++;
	}
	return (min);
}

int Span::getSize() const
{
	return (_set.size());
}

const std::multiset<int>& Span::getSet() const
{
	return (_set);
}


std::ostream &operator<<(std::ostream &out, Span &rhs)
{
	std::multiset<int>::iterator it = rhs.getSet().begin();
	while (it != rhs.getSet().end())
	{
		out << *it << std::endl;
		it++;
	}
	return (out);
}
