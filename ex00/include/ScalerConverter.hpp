/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalerConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:32:20 by sawang            #+#    #+#             */
/*   Updated: 2023/11/17 16:32:55 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Input.hpp"
#include <iostream>
#include <string>
#include <limits>

// #define WHITE_SPACE " \t\n\v\f\r"

// enum	eType
// {
// 	PSEUDO,
// 	CHAR,
// 	INT,
// 	FLOAT,
// 	DOUBLE,
// 	UNKNOWN
// };

class ScalerConverter
{
	public:
		static void	convert(std::string str);

	private:
		ScalerConverter();
		ScalerConverter(ScalerConverter const &cpy);
		ScalerConverter &operator=(ScalerConverter const &rhs);
		~ScalerConverter();

		// ScalerConverter(std::string str);

		// //parser
		// static eType	_parseInput(std::string str);
		// static void	_trimWhiteSpace(std::string &str);
		// static bool	_parsePseudo(std::string str);
		// static bool	_parseChar(std::string str);
		// static bool	_parseInt(std::string str);
		// static bool	_parseFloat(std::string str);
		// static bool	_parseDouble(std::string str);

		// //convert and print
		// static void	_convertPseudo(void);
		// //operator overload
		// operator char() const;
		// operator int() const;
		// operator float() const;
		// operator double() const;

		// //exception: in private or public?
		// class InputInvalidException : public std::exception
		// {
		// 	virtual const char* what() const throw();
		// };

		// //member variables;
		// static  std::string	_input;
		// static eType	 	_inputType;
		// static Input _input;
};
