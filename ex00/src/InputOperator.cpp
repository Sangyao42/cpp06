/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:07:38 by sawang            #+#    #+#             */
/*   Updated: 2023/11/16 16:07:38 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

Input::operator char() const
{
	switch (_inputType)
	{
		case (CHAR):
			if ( _inputStr[0] < -128 || _inputStr[0] > 127)
				std::cerr << "impossible" << std::endl;
			else if (_inputStr[0] < 32 && _inputStr[0] >= -128)
				std::cerr << "Non displayable" << std::endl;
			else
				std::cout << _inputStr[0] << std::endl;
			break;
		case (INT):
			int i = atoi(_inputStr.c_str());
			if (i < -128 || i > 127)
				std::cerr << "impossible" << std::endl;
			else if (i < 32 && i >= -128)
				std::cerr << "Non displayable" << std::endl;
			else
				std::cout << static_cast<char>(i) << std::endl;
			break;
		case (FLOAT):
			float f = strtof(_inputStr.c_str(), NULL);
			if (f < -128 || f > 127)
				std::cerr << "impossible" << std::endl;
			else if (f < 32 && f >= -128)
				std::cerr << "Non displayable" << std::endl;
			else
				std::cout << static_cast<char>(f) << std::endl;
			break;
		case (DOUBLE):
			double d = strtod(_inputStr.c_str(), NULL);
			if (d < -128 || d > 127)
				std::cerr << "impossible" << std::endl;
			else if (d < 32 && d >= -128)
				std::cerr << "Non displayable" << std::endl;
			else
				std::cout << static_cast<char>(d) << std::endl;
			break;
		default:
			throw InputInvalidException();
			break;
	}
}

Input::operator int() const
{
	switch (_inputType)
	{
		case (CHAR):
			std::cout << static_cast<int>(_inputStr[0]) << std::endl;
			break;
		case (INT):
			std::cout << atoi(_inputStr.c_str()) << std::endl;
			break;
		case (FLOAT):
			float f = strtof(_inputStr.c_str(), NULL);
			if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
				std::cerr << "impossible" << std::endl;
			else
				std::cout << static_cast<int>(f) << std::endl;
			break;
		case (DOUBLE):
			double d = strtod(_inputStr.c_str(), NULL);
			if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
				std::cerr << "impossible" << std::endl;
			else
				std::cout << static_cast<int>(d) << std::endl;
			std::cout << static_cast<int>(strtod(_inputStr.c_str(), NULL)) << std::endl;
			break;
		default:
			throw InputInvalidException();
			break;
	}
}

Input::operator float() const
{
	switch (_inputType)
	{
		case (CHAR):
			std::cout << static_cast<float>(_inputStr[0]) << 'f' << std::endl;
			break;
		case (INT):
			std::cout << static_cast<float>(atoi(_inputStr.c_str())) << 'f' << std::endl;
			break;
		case (FLOAT):
			std::cout << strtof(_inputStr.c_str(), NULL) << 'f' << std::endl;
			break;
		case (DOUBLE):
			if (strtod(_inputStr.c_str(), NULL) < std::numeric_limits<float>::min() || strtod(_inputStr.c_str(), NULL) > std::numeric_limits<float>::max())
				std::cerr << "impossible" << std::endl;
			else
				std::cout << static_cast<float>(strtod(_inputStr.c_str(), NULL)) << 'f' << std::endl;
			break;
		default:
			throw InputInvalidException();
			break;
	}
}

Input::operator double() const
{
	switch (_inputType)
	{
		case (CHAR):
			std::cout << static_cast<double>(_inputStr[0]) << std::endl;
			break;
		case (INT):
			std::cout << static_cast<double>(atoi(_inputStr.c_str())) << std::endl;
			break;
		case (FLOAT):
			std::cout << static_cast<double>(strtof(_inputStr.c_str(), NULL)) << std::endl;
			break;
		case (DOUBLE):
			std::cout << strtod(_inputStr.c_str(), NULL) << std::endl;
			break;
		default:
			throw InputInvalidException();
			break;
	}
}
