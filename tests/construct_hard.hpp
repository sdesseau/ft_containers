/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_hard.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:55:15 by stan              #+#    #+#             */
/*   Updated: 2023/02/27 14:58:59 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

#define T11 int
#define T22 std::string
typedef TESTED_NAMESPACE::map<T11, T22>::value_type T33;

void test_construct_hard()
{
	std::list<T33> lst;
	std::list<T33>::iterator itlst;

	lst.push_back(T33(42, "lol"));
	lst.push_back(T33(50, "mdr"));
	lst.push_back(T33(35, "funny"));
	lst.push_back(T33(45, "bunny"));
	lst.push_back(T33(21, "fizz"));
	lst.push_back(T33(35, "this key is already inside"));
	lst.push_back(T33(55, "fuzzy"));
	lst.push_back(T33(38, "buzz"));
	lst.push_back(T33(55, "inside too"));

	std::cout << "List contains: " << lst.size() << " elements." << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);
	std::cout << "---------------------------------------------" << std::endl;

	TESTED_NAMESPACE::map<T11, T22> mp(lst.begin(), lst.end());
	lst.clear();

	printSizeMap(mp);
}