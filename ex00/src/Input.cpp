/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:48:40 by sawang            #+#    #+#             */
/*   Updated: 2023/11/21 15:12:26 by sawang           ###   ########.fr       */
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

const char *Input::InputInvalidException::what() const throw()
{
	return ("InputInvalidException: input is not valid.");
}

