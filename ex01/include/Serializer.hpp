/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:03:38 by sawang            #+#    #+#             */
/*   Updated: 2023/11/17 21:14:43 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

struct Data
{
	char		c;
	int			i;
	std::string	s;
	float		f;
	double		d;
};

class Serializer
{
	public:
		Serializer();
		Serializer(Serializer const &cpy);
		Serializer &operator=(Serializer const &rhs);
		~Serializer();

		//uintptr_t is an unsigned integer type such that
		//any valid (void *) value can be converted to this type and then converted back.
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};