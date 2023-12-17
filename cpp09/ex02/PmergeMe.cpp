/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:21:22 by sutku             #+#    #+#             */
/*   Updated: 2023/12/15 19:11:33 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

PmergeMe::PmergeMe(char **argv)
{
	// std::cout << "Parameter constructor called" << std::endl;
	readInput(argv);
	if (_numbers.size() == 1)
	{
		std::cout << _numbers[0] << "\nOne number nothing to sort :)"<<std::endl;
		return;
	}
	std::cout <<"Before: ";
	printNumbersVector();
	clock_t start = std::clock();
	makePairsofVector();
	mergeSortPairsofVector();
	std::cout <<"After: ";
	createChainswithVector();
	std::cout<<std::fixed;
	double time = (std::clock() - start) / (double)CLOCKS_PER_SEC * 1000000;
	std::cout <<"Time to process a range of " << _numbers.size() << " numbers with vector: " <<std::setprecision(5)<< time << " us" << std::endl;
	//deque
	start = std::clock();
	makePairsofDeque();
	mergeSortPairsOfDeque();
	createChainswithDeque();
	time = (std::clock() - start) / (double)CLOCKS_PER_SEC * 1000000;
	std::cout <<"Time to process a range of " << _numbers2.size() << " numbers with deque: " <<std::setprecision(5)<< time << " us" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}

PmergeMe::~PmergeMe()
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

PmergeMe &		PmergeMe::operator=(PmergeMe const &copy)
{
	// std::cout << "Copy Assignment operator called" << std::endl;
	if (this != &copy)
	{
		_numbers = copy._numbers;
		_numbers2 = copy._numbers2;
		_pairs = copy._pairs;
		_pairs2 = copy._pairs2;
		_jacop = copy._jacop;
	}
	return (*this);
}

void PmergeMe::printNumbersVector()
{
	std::vector<unsigned int>::iterator it = _numbers.begin();

	while (it != _numbers.end())
	{
		std::cout << *it <<" ";
		it++;
	}
	std::cout << std::endl;
}

void isPositiveInteger(char *str)
{
	int i = 0;
	int plus = 0;

	if (str[0] == '+')
		plus = 1;
	while (str[i + plus])
	{
		if (isdigit(str[i + plus]) == 0)
			throw PmergeMe::InvalidInputException();
		i++;
	}
	if (i == 0)
		throw PmergeMe::InvalidInputException();
}

void PmergeMe::readInput(char **argv)
{
	int i = 0;
	unsigned long num;

	try
	{
		while (argv[++i])
		{
			errno = 0;
			isPositiveInteger(argv[i]);
			num = std::strtoul(argv[i], NULL, 10);
			if (errno != 0 || num > UINT_MAX)
				throw InvalidInputException();
			_numbers.push_back(static_cast<unsigned int>(num));
			_numbers2.push_back(static_cast<unsigned int>(num));
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
}

// VECTOR OPERATIONS

// Create pairs of vector

void PmergeMe::makePairsofVector()
{
	size_t i = 0;
	size_t len = _numbers.size();

	if (len % 2 != 0)
	{
		if (len != 1)
			len--;
	}
	while (i < len - 1)
	{
		if (_numbers[i] > _numbers[i + 1])
			_pairs.push_back(std::make_pair(_numbers[i], _numbers[i + 1]));
		else
			_pairs.push_back(std::make_pair(_numbers[i + 1], _numbers[i]));
		i += 2;
	}

}

// Using merge sort to sort pairs of vector

void PmergeMe::mergeSortPairsofVector()
{
    mergeSortVector(0, _pairs.size() - 1);
}

void PmergeMe::mergeSortVector(unsigned int left, unsigned int right)
{
    if (left < right)
    {
        unsigned int mid = left + (right - left) / 2;

        mergeSortVector(left, mid);
        mergeSortVector(mid + 1, right);

        mergeBackVector(left, mid, right);
    }
}

void PmergeMe::mergeBackVector(unsigned int left, unsigned int mid, unsigned int right)
{

    std::vector<std::pair<unsigned int, unsigned int> > tempLeft(_pairs.begin() + left, _pairs.begin() + mid + 1);
    std::vector<std::pair<unsigned int, unsigned int> > tempRight(_pairs.begin() + mid + 1, _pairs.begin() + right + 1);

    unsigned int i = 0, j = 0, k = left;

    while (i < tempLeft.size() && j < tempRight.size())
    {
        if (tempLeft[i].first <= tempRight[j].first)
            _pairs[k++] = tempLeft[i++];
        else
            _pairs[k++] = tempRight[j++];
    }

    while (i < tempLeft.size())
        _pairs[k++] = tempLeft[i++];

    while (j < tempRight.size())
        _pairs[k++] = tempRight[j++];
}

// Create Chains and using binary search to insert numbers into chains1

void printchain1Vector(std::vector<unsigned int> &chain1)
{
	std::vector<unsigned int>::iterator it = chain1.begin();

	while (it != chain1.end())
	{
		std::cout << *it <<" ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::createChainswithVector()
{
	std::vector<unsigned int> chain1;
	std::vector<unsigned int> chain2;
	std::vector<std::pair<unsigned int, unsigned int> >::iterator it = _pairs.begin();


	while (it != _pairs.end())
	{
		chain1.push_back(it->first);
		chain2.push_back(it->second);
		it++;
	}
	if (_numbers.size() % 2 != 0)
		chain2.push_back(_numbers[_numbers.size() - 1]);
	createJacopsNumber(chain2.size());

	unsigned int count = 0;
	unsigned int k = 2;
	int done = 1;
	while (done)
	{
		unsigned int j = _jacop[k];
		if (j == 0)
		{
			chain1.insert(chain1.begin(), chain2[j]);
			count++;
		}
		if (j >= chain2.size())
		{
			j = chain2.size() - 1;
			done = 0;
		}
		while (j > _jacop[k - 1])
		{
			binarySearchforVector(chain1, chain2[j], j + count);
			count++;
			j--;
		}
		k++;
	}
	printchain1Vector(chain1);
}

void PmergeMe::binarySearchforVector(std::vector<unsigned int> &chain1, unsigned int num, unsigned int right)
{
    unsigned int left = 0;

    while (left <= right)
    {
        unsigned int mid = left + (right - left) / 2;

        if (chain1[mid] == num)
        {
            chain1.insert(chain1.begin() + mid, num);
            return;
        }
        else if (chain1[mid] < num)
        {
            if (mid == chain1.size() - 1 || chain1[mid + 1] > num)
            {
                chain1.insert(chain1.begin() + mid + 1, num);
                return;
            }
            left = mid + 1;
        }
        else
        {
            if (mid == 0 || chain1[mid - 1] < num)
            {
                chain1.insert(chain1.begin() + mid, num);
                return;
            }
            right = mid - 1;
        }
    }
}



// DEQUE OPERATIONS

// Create pairs of deque
void PmergeMe::makePairsofDeque()
{
	size_t i = 0;
	size_t len = _numbers2.size();

	if (len % 2 != 0)
	{
		if (len != 1)
			len--;
	}
	while (i < len - 1)
	{
		if (_numbers2[i] > _numbers2[i + 1])
			_pairs2.push_back(std::make_pair(_numbers2[i], _numbers2[i + 1]));
		else
			_pairs2.push_back(std::make_pair(_numbers2[i + 1], _numbers2[i]));
		i += 2;
	}
}

// Using merge sort to sort pairs of deque

void PmergeMe::mergeSortPairsOfDeque()
{
	mergeSortDeque(0, _pairs2.size() - 1);
}

void PmergeMe::mergeSortDeque(unsigned int left, unsigned int right)
{
    if (left < right)
    {
        unsigned int mid = left + (right - left) / 2;

        mergeSortDeque(left, mid);
        mergeSortDeque(mid + 1, right);

        mergeBackDeque(left, mid, right);
    }
}

void PmergeMe::mergeBackDeque(unsigned int left, unsigned int mid, unsigned int right)
{

    std::deque<std::pair<unsigned int, unsigned int> > tempLeft(_pairs2.begin() + left, _pairs2.begin() + mid + 1);
    std::deque<std::pair<unsigned int, unsigned int> > tempRight(_pairs2.begin() + mid + 1, _pairs2.begin() + right + 1);

    unsigned int i = 0, j = 0, k = left;

    while (i < tempLeft.size() && j < tempRight.size())
    {
        if (tempLeft[i].first <= tempRight[j].first)
            _pairs2[k++] = tempLeft[i++];
        else
            _pairs2[k++] = tempRight[j++];
    }

    while (i < tempLeft.size())
        _pairs2[k++] = tempLeft[i++];

    while (j < tempRight.size())
        _pairs2[k++] = tempRight[j++];
}


void PmergeMe::createChainswithDeque()
{
	std::deque<unsigned int> chain1;
	std::deque<unsigned int> chain2;
	std::deque<std::pair<unsigned int, unsigned int> >::iterator it = _pairs2.begin();


	while (it != _pairs2.end())
	{
		chain1.push_back(it->first);
		chain2.push_back(it->second);
		it++;
	}
	if (_numbers2.size() % 2 != 0)
		chain2.push_back(_numbers2[_numbers2.size() - 1]);

	unsigned int count = 0;
	unsigned int k = 2;
	int done = 1;
	while (done)
	{
		unsigned int j = _jacop[k];
		if (j == 0)
		{
			chain1.insert(chain1.begin(), chain2[j]);
			count++;
		}
		if (j >= chain2.size())
		{
			j = chain2.size() - 1;
			done = 0;
		}
		while (j > _jacop[k - 1])
		{
			binarySearchforDeque(chain1, chain2[j], j + count);
			count++;
			j--;
		}
		k++;
	}
	
}


void PmergeMe::binarySearchforDeque(std::deque<unsigned int> &chain1, unsigned int num, unsigned int right)
{
    unsigned int left = 0;

    while (left <= right)
    {
        unsigned int mid = left + (right - left) / 2;

        if (chain1[mid] == num)
        {
            chain1.insert(chain1.begin() + mid, num);
            return;
        }
        else if (chain1[mid] < num)
        {
            if (mid == chain1.size() - 1 || chain1[mid + 1] > num)
            {
                chain1.insert(chain1.begin() + mid + 1, num);
                return;
            }
            left = mid + 1;
        }
        else
        {
            if (mid == 0 || chain1[mid - 1] < num)
            {
                chain1.insert(chain1.begin() + mid, num);
                return;
            }
            right = mid - 1;
        }
    }
}


// Create jacops number
void PmergeMe::createJacopsNumber(unsigned int size)
{
	unsigned int i;
	unsigned int num;

	_jacop.push_back(0);
	_jacop.push_back(1);

	i = 2;
	while (true)
	{
		num = _jacop[i - 1] + (2 * _jacop[i - 2]);
		_jacop.push_back(num);
		if (num > size)
			break;
		i++;
	}
	i = 0;
	while (i < _jacop.size())
	{
		if (_jacop[i] > 0)
			_jacop[i] -= 1;
		i++;
	}
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
	return ("Invalid input");
}
