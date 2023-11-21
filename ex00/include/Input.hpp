/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:01:48 by sawang            #+#    #+#             */
/*   Updated: 2023/11/21 15:12:04 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

#define WHITE_SPACE " \t\n\v\f\r"

enum	eType
{
	PSEUDO,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class Input
{
	private:
		Input();
		Input &operator=(Input const &rhs);
		Input(Input const &cpy);
		~Input();
		//parser

		static void	_trimWhiteSpace(std::string &str);
		static bool	_parsePseudo(std::string str);
		static bool	_parseChar(std::string str);
		static bool	_parseInt(std::string str);
		static bool	_parseFloat(std::string str);
		static bool	_parseDouble(std::string str);

	public:
		static std::string	_inputStr;
		static eType		_inputType;

		static eType	_parseInput(std::string &str);
		//convert and print
		static void	_convertPseudo(void);
		static void	_toChar(void);
		static void	_toInt(void);
		static void	_toFloat(void);
		static void	_toDouble(void);

		//operator overload is not possible if I need to print "impossible" and "non-displayable"
		// operator char() const;
		// operator int() const;
		// operator float() const;
		// operator double() const;


		class InputInvalidException : public std::exception
		{
			virtual const char *what() const throw();
		};
};
