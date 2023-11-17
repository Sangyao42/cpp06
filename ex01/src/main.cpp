/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:23:35 by sawang            #+#    #+#             */
/*   Updated: 2023/11/17 21:14:29 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.c = 'c';
	data.i = 42;
	data.s = "string";
	data.f = 42.42f;
	data.d = 42.42;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);
	std::cout << ptr->c << std::endl;
	std::cout << ptr->i << std::endl;
	std::cout << ptr->s << std::endl;
	std::cout << ptr->f << std::endl;
	std::cout << ptr->d << std::endl;

	return (0);
}