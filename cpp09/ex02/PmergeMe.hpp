/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:17:08 by sutku             #+#    #+#             */
/*   Updated: 2023/12/15 19:00:04 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <ctime>
#include <cerrno>
#include <cstdlib>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<unsigned int> _numbers;
		std::vector<std::pair <unsigned int, unsigned int> > _pairs;
	
		std::deque<unsigned int> _numbers2;
		std::deque<std::pair <unsigned int, unsigned int> > _pairs2;
	
		std::vector<unsigned int> _jacop;
	public:
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe();

		PmergeMe &		operator=(PmergeMe const &copy);

		void readInput(char **argv);
		//VECTOR OPERATIONS
		// Making pairs of vector
		void makePairsofVector();
		//Using merge sort to sort the pairs of vector
		void mergeBackVector(unsigned int left, unsigned int mid, unsigned int right);
		void mergeSortVector(unsigned int left, unsigned int right);
		void mergeSortPairsofVector();
		// Creating chains and using binary search to insert the numbers
		void createChainswithVector();
		void binarySearchforVector(std::vector<unsigned int> &chain1, unsigned int num, unsigned int right);
		// print the numbers in vector
		void printNumbersVector();
		
		// DEQUE OPERATIONS
		// Making pairs of deque
		void makePairsofDeque();
		//Using merge sort to sort the pairs of deque
		void mergeSortPairsOfDeque();
		void mergeSortDeque(unsigned int left, unsigned int right);
		void mergeBackDeque(unsigned int left, unsigned int mid, unsigned int right);
		//Creating chains and using binary search to insert the numbers
		void createChainswithDeque();
		void binarySearchforDeque(std::deque<unsigned int> &chain1, unsigned int num, unsigned int right);

		// JACOP'S NUMBER
		void createJacopsNumber(unsigned int size);
		
		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

#endif