/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:27:52 by sawang            #+#    #+#             */
/*   Updated: 2023/11/17 22:04:53 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

Base *generate(void)
{
	int i = rand() % 3;
	if (i == 0)
	{
		std::cout << "A is generated." << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "B is generated." << std::endl;
		return new B;
	}
	else
	{
		std::cout << "C is generated." << std::endl;
		return new C;
	}
}

void	identify(Base *p)
{
	std::cout << "Identify by pointer: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	std::cout << "Identify by reference: ";
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(std::bad_cast &e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			return ;
		}
		catch(const std::bad_cast &e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				return ;
			}
			catch(const std::bad_cast &e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cerr << e.what() << '\n';
		}
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);

	delete base;
	return (0);
}