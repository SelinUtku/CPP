/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:09:05 by sutku             #+#    #+#             */
/*   Updated: 2023/12/04 15:08:38 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Span
{
	private:
		unsigned int		_N;
		std::multiset<int> 	_set;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		~Span();
		Span &operator=(const Span &copy);
		
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		const std::multiset<int> & getSet() const;
		int getSize() const;
		template <typename T>
		void addRange(T begin, T end)
		{
			if (_set.size() + std::distance(begin, end) > (_N - _set.size()))
				throw (Span::spanIsFullException());
			_set.insert(begin, end);
		}
		
		class	spanIsFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();

		};
		class	spanIsNotEnoughException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &o, Span &rhs);

#endif