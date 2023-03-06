/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:48:48 by stan              #+#    #+#             */
/*   Updated: 2023/03/06 16:09:51 by sdesseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

void print_tree()
{
    TESTED_NAMESPACE::map<int, int> mymap;

	// insert 1000000 random numbers:
	for (int i = 0; i < 1000000; ++i)
		{ mymap.insert(TESTED_NAMESPACE::pair<int, int>(i, i)); }
	
	// clear and insert 1000 random numbers:
	mymap.clear();
	for (int i = 0; i < 1000; ++i)
		{ mymap.insert(TESTED_NAMESPACE::pair<int, int>(i, i)); }
	// clear and insert 100 random numbers:
	mymap.clear();
	for (int i = 0; i < 100; ++i)
		{ mymap.insert(TESTED_NAMESPACE::pair<int, int>(i, i)); }
	
	// clear and insert 10 random numbers:
	mymap.clear();
	for (int i = 0; i < 10; ++i)
		{ mymap.insert(TESTED_NAMESPACE::pair<int, int>(i, i)); }
	mymap.print();
}