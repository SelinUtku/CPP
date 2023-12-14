/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:17:08 by sutku             #+#    #+#             */
/*   Updated: 2023/12/14 19:32:31 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <climits>

class PmergeMe
{
	private:
	public:
		std::vector<unsigned int> _numbers;
		std::vector<std::pair <unsigned int, unsigned int> > _pairs;
		std::vector<unsigned int> _jacop;
		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		~PmergeMe();

		PmergeMe &		operator=(PmergeMe const &copy);

		void readInput(char **argv);
		void makePairs();
		void merge(unsigned int left, unsigned int mid, unsigned int right);
		void mergeSort(unsigned int left, unsigned int right);
		void mergePairs();
		void createChains();
		void createJacopsNumber(unsigned int size);
		void binarySearch(std::vector<unsigned int> &chain1, unsigned int num, unsigned int right);
		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};


};

#endif