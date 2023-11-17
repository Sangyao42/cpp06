/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputParser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:51:43 by sawang            #+#    #+#             */
/*   Updated: 2023/11/17 19:20:33 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

//utils
void	Input::_trimWhiteSpace(std::string &str)
{
	size_t start = str.find_first_not_of(WHITE_SPACE);
	size_t end = str.find_last_not_of(WHITE_SPACE);
	if (start == std::string::npos)
		str = " ";
	else
		str = str.substr(start, end - start + 1);
}
//parser
eType	Input::_parseInput(std::string &str)
{
	eType type;

	if (str.length() == 0)
		throw InputInvalidException();
	_trimWhiteSpace(str);
	if (_parsePseudo(str))
		type = PSEUDO;
	else if (_parseChar(str))
		type = CHAR;
	else if (_parseInt(str))
		type = INT;
	else if (_parseFloat(str))
		type = FLOAT;
	else if (_parseDouble(str))
		type = DOUBLE;
	else
		throw InputInvalidException();
	return (type);
}

bool	Input::_parsePseudo(std::string str)
{
	return (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan");
}

bool	Input::_parseChar(std::string str)
{
	return (str.length() == 1 && !isdigit(str[0]));
}

bool	Input::_parseInt(std::string str)
{
	size_t i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i])
		return (false);
	long checker = atol(str.c_str());
	if (checker < std::numeric_limits<int>::min() || checker > std::numeric_limits<int>::max())
		return (false);
	else
		return (true);
}

bool	Input::_parseFloat(std::string str)
{
	size_t i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i] != '.')
		return (false);
	else
		i++;
	if (!isdigit(str[i]))
		return (false);
	while (isdigit(str[i]))
		i++;
	if (str[i] != 'f')
		return (false);
	else
		i++;
	if (str[i])
		return (false);
	long double checker = strtold(str.c_str(), NULL);
	if (checker < -std::numeric_limits<float>::max() || checker > std::numeric_limits<float>::max())
		return (false);
	else
		return (true);
}

bool Input::_parseDouble(std::string str)
{
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i] != '.')
		return (false);
	else
		i++;
	if (!isdigit(str[i]))
		return (false);
	while (isdigit(str[i]))
		i++;
	if (str[i])
		return (false);
	long double checker = strtold(str.c_str(), NULL);
	if (checker < -std::numeric_limits<double>::max() || checker > std::numeric_limits<double>::max())
		return (false);
	else
		return (true);
}