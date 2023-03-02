/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cpyconstruct.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:02:59 by stan              #+#    #+#             */
/*   Updated: 2023/02/27 14:03:44 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

void test_map_copyconstruct()
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

	TESTED_NAMESPACE::map<T1, T2> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	TESTED_NAMESPACE::map<T1, T2> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
	printSizeMap(mp);
	printSizeMap(mp_range);
	printSizeMap(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSizeMap(mp);
	printSizeMap(mp_range);
	printSizeMap(mp_copy);
}