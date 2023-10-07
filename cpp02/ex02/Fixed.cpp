/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:31:10 by sutku             #+#    #+#             */
/*   Updated: 2023/10/07 19:42:56 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	value = n << fractional;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(n * (1 << fractional));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = copy.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// 6 comparison operators

bool Fixed::operator>(const Fixed &x) const
{
	if (this->getRawBits() > x.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &x) const
{
	if (this->getRawBits() < x.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &x) const
{
	if (this->getRawBits() >= x.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &x) const
{
	if (this->getRawBits() <= x.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &x) const
{
	if (this->getRawBits() == x.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &x) const
{
	if (this->getRawBits() != x.getRawBits())
		return (true);
	return (false);
}


// 4 arithmetic operators

Fixed Fixed::operator+(const Fixed &x)
{
	Fixed temp(this->value += x.getRawBits());
	
	return (temp);
}

Fixed Fixed::operator-(const Fixed &x)
{
	Fixed temp(this->value -= x.getRawBits());
	
	return (temp);
}

Fixed Fixed::operator*(const Fixed &x)
{
	Fixed temp((this->toFloat() * x.toFloat()));
	
	return (temp);
}

Fixed Fixed::operator/(const Fixed &x)
{
	Fixed temp((this->toFloat() / x.toFloat()));
	
	return (temp);
}

// 2 prefix increment/decrement operators

Fixed & Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed & Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

// 2 postfix increment/decrement operators

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->value++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->value--;
	return (tmp);
}

// min and max functions

Fixed& Fixed::min(Fixed &x, Fixed &y)
{
	if (x.getRawBits() < y.getRawBits())
		return (x);
	return (y);
}

const Fixed& Fixed::min(const Fixed &x, const Fixed &y)
{
	if (x.getRawBits() < y.getRawBits())
		return (x);
	return (y);
}

Fixed& Fixed::max(Fixed &x, Fixed &y)
{
	if (x.getRawBits() > y.getRawBits())
		return (x);
	return (y);
}

const Fixed& Fixed::max(const Fixed &x, const Fixed &y)
{
	if (x.getRawBits() > y.getRawBits())
		return (x);
	return (y);
}


// Getters and setters and conversion functions

float Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << this->fractional));
}

int Fixed::toInt(void) const
{
	return (this->value >> this->fractional);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

