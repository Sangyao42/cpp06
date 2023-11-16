/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:01:48 by sawang            #+#    #+#             */
/*   Updated: 2023/11/16 16:01:48 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>

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
	//parser
		static eType	_parseInput(std::string str);
		static void	_trimWhiteSpace(std::string &str);
		static bool	_parsePseudo(std::string str);
		static bool	_parseChar(std::string str);
		static bool	_parseInt(std::string str);
		static bool	_parseFloat(std::string str);
		static bool	_parseDouble(std::string str);


public:
	~Input();
	Input(std::string str);
	//exception: in private or public?

	//convert and print
	static void	_convertPseudo(void);
	//operator overload
	operator char() const;
	operator int() const;
	operator float() const;
	operator double() const;

	class InputInvalidException : public std::exception
	{
		virtual const char* what() const throw();
	};

	static std::string _inputStr;
	static eType		_inputType;
};
