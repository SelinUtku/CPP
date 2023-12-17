/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:03:02 by sutku             #+#    #+#             */
/*   Updated: 2023/12/15 19:56:54 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Bitcoin::Bitcoin(const Bitcoin &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Bitcoin::~Bitcoin()
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Bitcoin &Bitcoin::operator=(const Bitcoin &copy)
{
	// std::cout << "Copy Assignment operator called" << std::endl;
	if (this != &copy)
	{
		_dataBase.clear();
		_dataBase.insert(copy._dataBase.begin(), copy._dataBase.end());
	}
	return (*this);
}

void Bitcoin::addData(std::string date, float price)
{
	_dataBase[date] = price;
}


void Bitcoin::calculatePrice(std::string date, float price)
{
	std::map<std::string, float>::iterator it;
	it = _dataBase.lower_bound(date);
	if (it->first == date)
	{
		std::cout << date << " => " << price << " = " << (it->second * price) << std::endl; 
		return ;
	}
	if (it != _dataBase.begin())
	{
		it--;
		std::cout << date << " => " << price << " = " << (it->second * price) << std::endl; 
	}
	else
		std::cout <<"This date is out of range" << std::endl;

}


void Bitcoin::isValidDate(std::string date)
{
	if (date.length() != 10)
		throw InvalidDateException();
	if (date[4] != '-' || date[7] != '-')
		throw InvalidDateException();

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	
	if (std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
		throw InvalidDateException();
	if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31)
		throw InvalidDateException();
}

float Bitcoin::isValidPrice(std::string price)
{
	char *end;
	float value;

	errno = 0;
	if (price.find('.') != std::string::npos && price.find('f') == price.length() - 1)
		price.erase(price.size() - 1);
	value = std::strtof(price.c_str(), &end);
	if (end != price.c_str() + price.length() || errno != 0)
		throw InvalidPriceException();
	if (value < 0.0f || value > 1000.0f || errno != 0)
		throw OutOfRangeException();
	return (value);
}

void Bitcoin::readInput(char **argv)
{
	std::ifstream file(argv[1]);
	std::string line;
	std::string date;
	std::string price;
	float value;

	if (file.is_open())
	{
		getline(file, line);
		if (line != "date | value")
		{
			std::cout << "Invalid file format" << std::endl;
			exit(1);
		}
		while (getline(file, line))
		{
			if (line.empty())
			{
				std::cout << "Line is empty" << std::endl;
				continue;
			}
			date = line.substr(0, line.find('|'));
			while (!date.empty() && date[date.size() - 1] == ' ')
    			date.erase(date.size() - 1);
			price = line.substr(line.find('|') + 1);
			while (!price.empty() && price[price.size() - 1] == ' ')
    			price.erase(price.size() - 1);
			try
			{
				isValidDate(date);
				value = isValidPrice(price);
				calculatePrice(date, value);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Unable to open "<<argv[1]<< std::endl;
		exit(1);
	}
}

void Bitcoin::readDataBase()
{
	std::ifstream file("data.csv");
	std::string line;
	std::string date;
	std::string price;

	if (file.is_open())
	{
		getline(file, line);
		if (line != "date,exchange_rate")
		{
			std::cout << "Invalid database file format" << std::endl;
			exit(1);
		}
		while (getline(file, line))
		{
			date = line.substr(0, line.find(','));
			price = line.substr(line.find(',') + 1);
			addData(date, std::strtof(price.c_str(), NULL));
		}
		file.close();
	}
	else
	{
		std::cout << "Unable to open data.csv" << std::endl;
		exit(1);
	}
}

const char *Bitcoin::InvalidDateException::what() const throw()
{
	return ("Invalid date format");
}

const char *Bitcoin::InvalidPriceException::what() const throw()
{
	return ("Invalid price format");
}

const char *Bitcoin::OutOfRangeException::what() const throw()
{
	return ("Price out of range");
}
