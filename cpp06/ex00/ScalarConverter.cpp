/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:47:25 by sutku             #+#    #+#             */
/*   Updated: 2023/11/28 16:33:37 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter Copy constructor called" << std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

bool isChar(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (true);
	return (false);
}

bool isInt(std::string str)
{
	unsigned int i = 0;
	while (i < str.length())
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool isFloat(std::string str)
{
	unsigned int i = 0;
	int dot = 0;
	if (str.find_first_of("0123456789") == std::string::npos)
		return (false);
	if (str[str.length() - 1] == 'f')
	{
		while (i < str.length() - 1)
		{
			if (i == 0 && (str[i] == '-' || str[i] == '+'))
				i++;
			if (!isdigit(str[i]))
			{
				if (dot == 0 && str[i] == '.')
					dot = 1;
				else
					return (false);
			}
			i++;
		}
		if (dot == 1)
			return (true);
	}
	return (false);
}

bool isDouble(std::string str)
{
	unsigned int i = 0;
	int dot = 0;
	if (str.find_first_of("0123456789") == std::string::npos)
		return (false);
	while (i < str.length())
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!isdigit(str[i]))
		{
			if (dot == 0 && str[i] == '.')
				dot = 1;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

int defineType(std::string str)
{
	if(isChar(str))
		return (0);
	else if (isInt(str))
		return (1);
	else if (isFloat(str))
		return (2);
	else if (isDouble(str))
		return (3);
	else
		return (-1);
}

int convertToInteger(std::string str)
{
	unsigned int i = 0;
	int sign = 1;
	int num = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (i < str.length())
	{
		if (num > std::numeric_limits<int>::max() / 10)
			throw (ScalarConverter::ImpossibleException());
		num = num * 10;
		if (num > std::numeric_limits<int>::max() - (str[i] - '0'))
			throw (ScalarConverter::ImpossibleException());
		num += (str[i] - '0');
		i++;
	}
	if ((num * sign) > std::numeric_limits<int>::max() || (num * sign) < INT_MIN)
		throw (ScalarConverter::ImpossibleException());
	return (num * sign);
	
}

float convertToFloat(std::string str)
{
	char *end;
	float f = strtof(str.c_str(), &end);
	errno = 0;
	if (errno != 0 || f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
		throw (ScalarConverter::ImpossibleException());
	return (f);
}

double convertToDouble(std::string str)
{
	char *end;
	double d = strtod(str.c_str(), &end);
	errno = 0;
	if (errno != 0 || d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
		throw (ScalarConverter::ImpossibleException());
	return (d);
}

void ScalarConverter::convert(std::string str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout <<"char:\t"<< "impossible" << std::endl;
		std::cout <<"int:\t"<< "impossible" << std::endl;
		if (str == "nanf" || str == "+inff" || str == "-inff")
		{
			std::cout <<"float:\t"<< str << std::endl;
			std::cout <<"double:\t"<< str.substr(0, str.length() - 1) << std::endl;
		}
		else
		{
			std::cout <<"float:\t"<< str << 'f' << std::endl;
			std::cout <<"double:\t"<< str << std::endl;
		}
		return ;
	}
	int type = defineType(str);
	try
	{
		if (type == 0)
		{
			std::cout <<"char:\t'"<< str[0] <<"'" <<std::endl;
			std::cout <<"int:\t"<< static_cast<int>(str[0]) << std::endl;
			std::cout <<"float:\t"<<std::setprecision(2)<< static_cast<float>(str[0]) << "f" << std::endl;
			std::cout <<"double:\t"<<std::setprecision(2)<< static_cast<double>(str[0]) << std::endl;
		}
		else if (type == 1)
		{
			int num = convertToInteger(str);
			if (num < 0 || num > CHAR_MAX)
				std::cout <<"char:\t"<< "impossible" << std::endl;
			else if(num < 32 || num > 126)
				std::cout <<"char:\t"<< "Non-displayable" << std::endl;
			else
				std::cout <<"char:\t'"<< static_cast<char>(num)<< "'" << std::endl;
			std::cout <<"int:\t"<< num << std::endl;
			std::cout <<"float:\t"<<std::setprecision(2)<< static_cast<float>(num) << "f" << std::endl;
			std::cout <<"double:\t"<<std::setprecision(2)<< static_cast<double>(num) << std::endl;
		}
		else if (type == 2)
		{
			float numf = convertToFloat(str);
			if (numf < 0 || numf > CHAR_MAX)
				std::cout <<"char:\t"<< "impossible" << std::endl;
			else if(numf < 32 || numf > 126)
				std::cout <<"char:\t"<< "Non-displayable" << std::endl;
			else
				std::cout <<"char:\t'"<< static_cast<char>(numf) << "'" << std::endl;
			if (numf > std::numeric_limits<int>::max() || numf < std::numeric_limits<int>::min())
				std::cout <<"int:\t"<< "impossible" << std::endl;
			else
				std::cout <<"int:\t"<< static_cast<int>(numf) << std::endl;
			std::cout <<"float:\t"<<std::setprecision(2)<< numf << "f" << std::endl;
			std::cout <<"double:\t"<<std::setprecision(2)<< static_cast<double>(numf) << std::endl;
		}
		else if (type == 3)
		{
			double numd = convertToDouble(str);
			if (numd < 0 || numd > CHAR_MAX)
				std::cout <<"char:\t"<< "impossible" << std::endl;
			else if(numd < 32 || numd > 126)
				std::cout <<"char:\t"<< "Non-displayable" << std::endl;
			else
				std::cout <<"char:\t'"<< static_cast<char>(numd) << "'" << std::endl;
			if (numd > std::numeric_limits<int>::max() || numd < std::numeric_limits<int>::min())
				std::cout <<"int:\t"<< "impossible" << std::endl;
			else
				std::cout <<"int:\t"<< static_cast<int>(numd) << std::endl;
			if (numd > std::numeric_limits<float>::max() || numd < -std::numeric_limits<float>::max())
				std::cout <<"float:\t"<< "impossible" << std::endl;
			else
				std::cout <<"float:\t"<<std::setprecision(2)<< static_cast<float>(numd) << "f" << std::endl;
			std::cout <<"double:\t"<<std::setprecision(2)<< numd << std::endl;
		}
		else
		{
			std::cerr<<"Error: "<<str<<" is not a valid type"<<std::endl;
			return ;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("char: impossible\ninteger: impossible\nfloat: impossible\ndouble: impossible");
}
