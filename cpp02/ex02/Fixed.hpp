/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:31:13 by sutku             #+#    #+#             */
/*   Updated: 2023/10/07 19:15:20 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int value;
		static const int fractional = 8;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed();
	// 6 comparison operators
		bool operator>(const Fixed &x) const;
		bool operator<(const Fixed &x) const;
		bool operator>=(const Fixed &x) const;
		bool operator<=(const Fixed &x) const;
		bool operator==(const Fixed &x) const;
		bool operator!=(const Fixed &x) const;
	
	// 4 arithmetic operators
		Fixed operator+(const Fixed &x);
		Fixed operator-(const Fixed &x);
		Fixed operator*(const Fixed &x);
		Fixed operator/(const Fixed &x);
		
	// 2 prefix increment/decrement operators
	// to distinguish between prefix and postfix, we use dummy int parameter.
		Fixed& operator++(void);
		Fixed& operator--(void);
	// 2 postfix increment/decrement operators
		Fixed operator++(int);
		Fixed operator--(int);

	// min and max functions
		static Fixed& min(Fixed &x, Fixed &y);
		static const Fixed& min(const Fixed &x, const Fixed &y);
		static Fixed& max(Fixed &x, Fixed &y);
		static const Fixed& max(const Fixed &x, const Fixed &y);

	// getter and setter and conversion functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif