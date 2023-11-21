/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalerConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:08 by sawang            #+#    #+#             */
/*   Updated: 2023/11/21 15:11:35 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalerConverter.hpp"

ScalerConverter::ScalerConverter()
{
}

ScalerConverter::ScalerConverter(ScalerConverter const &cpy)
{
	(void)cpy;
}

ScalerConverter &ScalerConverter::operator=(ScalerConverter const &rhs)
{
	if (this != &rhs)
	{
		(void)rhs;
	}
	return (*this);
}

ScalerConverter::~ScalerConverter()
{
}

// convert
void	ScalerConverter::convert(std::string str)
{
	Input::_inputStr = str;
	Input::_inputType = Input::_parseInput(Input::_inputStr);
	if (Input::_inputType == PSEUDO)
		Input::_convertPseudo();
	else
	{
		std::cout << "char: ";
		Input::_toChar();
		std::cout << "int: ";
		Input::_toInt();
		std::cout << "float: ";
		Input::_toFloat();
		std::cout << "double: ";
		Input::_toDouble();
	}
}
