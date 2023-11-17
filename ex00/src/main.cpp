/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:30:08 by sawang            #+#    #+#             */
/*   Updated: 2023/11/17 16:29:39 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"
#include "ScalerConverter.hpp"

#include <iostream>

int main(int argv, char **argc)
{
	if (argv != 2)
	{
		std::cerr << "Error: wrong number of arguments." << std::endl;
		return (1);
	}
	try
	{
		std::string str(argc[1]);
		ScalerConverter::convert(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}