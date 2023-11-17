/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:48:40 by sawang            #+#    #+#             */
/*   Updated: 2023/11/17 17:25:06 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

//Orthodox Canonical
Input::Input()
{
}

Input::Input(Input const &cpy)
{
	(void)cpy;
}

Input &Input::operator=(Input const &rhs)
{
	if (this != &rhs)
	{
		(void)rhs;
	}
	return (*this);
}

Input::~Input()
{
}

std::string Input::_inputStr = "";
eType		Input::_inputType = UNKNOWN;

//user-defined constructor
Input::Input(std::string str)
{
	_inputStr= str;
	_inputType = _parseInput(_inputStr);
}

const char *Input::InputInvalidException::what() const throw()
{
	return ("InputInvalidException: input is not valid.");
}

