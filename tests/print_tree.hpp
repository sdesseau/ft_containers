/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:48:48 by stan              #+#    #+#             */
/*   Updated: 2023/03/06 12:51:02 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

void print_tree()
{
    TESTED_NAMESPACE::map<int, int> mymap;

	// insert 1000000 random numbers:
	for (int i = 0; i < 50; ++i)
	{
		if (i % 2 == 0)
		{
			// std::cout << "i -> " << i << std::endl;
			mymap.insert(TESTED_NAMESPACE::make_pair(i * -2, i + 12 - i * i));
		}
		else
		{
			// std::cout << "i -> " << -i << std::endl;
			mymap.insert(TESTED_NAMESPACE::make_pair(i , i * 3));
		}
	}
	mymap.print();
}