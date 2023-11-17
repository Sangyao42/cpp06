/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalerConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:32:20 by sawang            #+#    #+#             */
/*   Updated: 2023/11/17 19:24:42 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Input.hpp"
#include <iostream>
#include <string>
#include <limits>

class ScalerConverter
{
	public:
		static void	convert(std::string str);

	private:
		ScalerConverter();
		ScalerConverter(ScalerConverter const &cpy);
		ScalerConverter &operator=(ScalerConverter const &rhs);
		~ScalerConverter();
};
