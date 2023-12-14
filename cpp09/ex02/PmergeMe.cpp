/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:21:22 by sutku             #+#    #+#             */
/*   Updated: 2023/12/14 19:31:16 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &		PmergeMe::operator=(PmergeMe const &copy)
{
	(void)copy;
	return (*this);
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
			if (errno != 0 || num > UINT32_MAX)
				throw InvalidInputException();
			_numbers.push_back(static_cast<unsigned int>(num));
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
}

void PmergeMe::makePairs()
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

void PmergeMe::merge(unsigned int left, unsigned int mid, unsigned int right)
{
    // Temporary vectors to hold the two halves
    std::vector<std::pair<unsigned int, unsigned int> > tempLeft(_pairs.begin() + left, _pairs.begin() + mid + 1);
    std::vector<std::pair<unsigned int, unsigned int> > tempRight(_pairs.begin() + mid + 1, _pairs.begin() + right + 1);

    unsigned int i = 0, j = 0, k = left;

    // Merge the temp arrays back into _pairs[left..right]
    while (i < tempLeft.size() && j < tempRight.size())
    {
        if (tempLeft[i].first <= tempRight[j].first)
            _pairs[k++] = tempLeft[i++];
        else
            _pairs[k++] = tempRight[j++];
    }

    // Copy the remaining elements of tempLeft[], if there are any
    while (i < tempLeft.size())
        _pairs[k++] = tempLeft[i++];

    // Copy the remaining elements of tempRight[], if there are any
    while (j < tempRight.size())
        _pairs[k++] = tempRight[j++];
}

void PmergeMe::mergeSort(unsigned int left, unsigned int right)
{
    if (left < right)
    {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        unsigned int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }
}

void PmergeMe::mergePairs()
{
    mergeSort(0, _pairs.size() - 1);
}


void PmergeMe::createChains()
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
			binarySearch(chain1, chain2[j], j + count);
			count++;
			j--;
		}
		k++;
	}
}

void PmergeMe::binarySearch(std::vector<unsigned int> &chain1, unsigned int num, unsigned int right)
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
