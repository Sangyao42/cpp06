/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputParser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:51:43 by sawang            #+#    #+#             */
/*   Updated: 2023/11/16 18:51:43 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

//utils
void	Input::_trimWhiteSpace(std::string &str)
{
	size_t start = str.find_first_not_of(WHITE_SPACE);
	size_t end = str.find_last_not_of(WHITE_SPACE);
	if (start == std::string::npos)
		str = "";
	else
		str = str.substr(start, end - start + 1);
}
//parser
eType	Input::_parseInput(std::string str)
{
	eType type;

	if (str.length() == 0)
		throw InputInvalidException();
	_trimWhiteSpace(str);
	if (str.length() == 0)
		str = " ";
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

