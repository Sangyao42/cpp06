/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalerConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:08 by sawang            #+#    #+#             */
/*   Updated: 2023/11/16 14:52:08 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalerConverter.hpp"

ScalerConverter::ScalerConverter()
{
}

ScalerConverter::ScalerConverter(ScalerConverter const &cpy)
{
	void (cpy);
}

ScalerConverter &ScalerConverter::operator=(ScalerConverter const &rhs)
{
	if (this != &rhs)
	{
		void (rhs);
	}
	return (*this);
}

ScalerConverter::~ScalerConverter()
{
}

// convert
void	ScalerConverter::convert(std::string str)
{
	Input input(str);
	if (Input::_inputType == PSEUDO)
		Input::_convertPseudo();
	else
	{
		std::cout << "char: " << char(input) << std::endl;
		std::cout << "int: " << int(input) << std::endl;
		std::cout << "float: " << float(input) << std::endl;
		std::cout << "double: " << double(input) << std::endl;
	}
}
