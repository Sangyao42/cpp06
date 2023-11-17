/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputConverter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:07:38 by sawang            #+#    #+#             */
/*   Updated: 2023/11/17 17:32:43 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

void	Input::_convertPseudo(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (_inputStr == "-inff" || _inputStr == "+inff" || _inputStr == "nanf")
	{
		std::cout << "float: " << _inputStr << std::endl;
		std::cout << "double: " << _inputStr.substr(0, _inputStr.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << _inputStr << 'f' << std::endl;
		std::cout << "double: " << _inputStr << std::endl;
	}

}

void	Input::_toChar(void)
{
	switch (_inputType)
	{
		case (CHAR):
			if ( _inputStr[0] < std::numeric_limits<char>::min() || _inputStr[0] > std::numeric_limits<char>::max())
				std::cerr << "impossible" << std::endl;
			else if (_inputStr[0] < 32 && _inputStr[0] >= std::numeric_limits<char>::min())
				std::cerr << "Non displayable" << std::endl;
			else
				std::cout << _inputStr[0] << std::endl;
			break;
		case (INT): {
			int i = atoi(_inputStr.c_str());
			if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
				std::cerr << "impossible" << std::endl;
			else if (i < 32 && i >= std::numeric_limits<char>::min())
				std::cerr << "Non displayable" << std::endl;
			else
				std::cout << static_cast<char>(i) << std::endl;
			break;
		}
		case (FLOAT): {
			float f = strtof(_inputStr.c_str(), NULL);
			if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
				std::cerr << "impossible" << std::endl;
			else if (f < 32 && f >= std::numeric_limits<char>::min())
				std::cerr << "Non displayable" << std::endl;
			else
				std::cout << static_cast<char>(f) << std::endl;
			break;
		}
		case (DOUBLE): {
			double d = strtod(_inputStr.c_str(), NULL);
			if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
				std::cerr << "impossible" << std::endl;
			else if (d < 32 && d >= std::numeric_limits<char>::min())
				std::cerr << "Non displayable" << std::endl;
			else
				std::cout << static_cast<char>(d) << std::endl;
			break;
		}
		default:
			throw InputInvalidException();
			break;
	}
}

void	Input::_toInt(void)
{
	switch (_inputType)
	{
		case (CHAR):
			std::cout << static_cast<int>(_inputStr[0]) << std::endl;
			break;
		case (INT):
			std::cout << atoi(_inputStr.c_str()) << std::endl;
			break;
		case (FLOAT): {
			float f = strtof(_inputStr.c_str(), NULL);
			if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
				std::cerr << "impossible" << std::endl;
			else
				std::cout << static_cast<int>(f) << std::endl;
			break;
		}
		case (DOUBLE): {
			double d = strtod(_inputStr.c_str(), NULL);
			if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
				std::cerr << "impossible" << std::endl;
			else
				std::cout << static_cast<int>(d) << std::endl;
			break;
		}
		default:
			throw InputInvalidException();
			break;
	}
}

void	Input::_toFloat(void)
{
	switch (_inputType)
	{
		case (CHAR):
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(_inputStr[0]) << "f" << std::endl;
			break;
		case (INT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(atoi(_inputStr.c_str())) << "f" << std::endl;
			break;
		case (FLOAT):
			std::cout << std::fixed << std::setprecision(1) << strtof(_inputStr.c_str(), NULL) << 'f' << std::endl;
			break;
		case (DOUBLE):
			if (strtod(_inputStr.c_str(), NULL) < -std::numeric_limits<float>::max() || strtod(_inputStr.c_str(), NULL) > std::numeric_limits<float>::max())
				std::cerr << "impossible" << std::endl;
			else
				std::cout << std::fixed << std::setprecision(1) << static_cast<float>(strtod(_inputStr.c_str(), NULL)) << 'f' << std::endl;
			break;
		default:
			throw InputInvalidException();
			break;
	}
}

void	Input::_toDouble(void)
{
	switch (_inputType)
	{
		case (CHAR):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(_inputStr[0]) << std::endl;
			break;
		case (INT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(atoi(_inputStr.c_str())) << std::endl;
			break;
		case (FLOAT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(strtof(_inputStr.c_str(), NULL)) << std::endl;
			break;
		case (DOUBLE):
			std::cout << std::fixed << std::setprecision(1) << strtod(_inputStr.c_str(), NULL) << std::endl;
			break;
		default:
			throw InputInvalidException();
			break;
	}
}
