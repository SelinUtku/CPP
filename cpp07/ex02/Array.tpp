/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:36:33 by sutku             #+#    #+#             */
/*   Updated: 2023/12/02 18:47:57 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0)
{
	_arr = new T[0];
	std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_arr = new T[n];
	std::cout << "Array parameter constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(Array const &copy)
{
	_arr = new T[copy._size];
	*this = copy;
	std::cout << "Array copy constructor called" << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &copy)
{
	if (this != &copy)
	{
		if (this->_arr)
			delete [] _arr;
		this->_arr = new T[copy._size];
		unsigned int i = 0;
		while (i < copy._size)
		{
			this->_arr[i] = copy._arr[i];
			i++;
		}
		this->_size = copy._size;
	}
	std::cout << "Array copy assignment operator called" << std::endl;
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->_arr)
		delete [] _arr;
	std::cout << "Array destructor called" << std::endl;
}


template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw Array::OutOfBoundsException();
	return (this->_arr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index out of bounds");
}