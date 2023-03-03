/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ite_map.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:42:28 by stan              #+#    #+#             */
/*   Updated: 2023/03/03 18:20:37 by sdesseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

#define t4 char
#define t5 int
typedef _pair<const t4, t5> t6;

template <typename T, typename U>
void	printReverse(TESTED_NAMESPACE::map<T, U> &mp)
{
	typename TESTED_NAMESPACE::map<T, U>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}


void rite()
{
    std::list<t6> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(t6('a' + i, (i + 1) * 7));

	TESTED_NAMESPACE::map<t4, t5> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<t4, t5>::iterator it_ = mp.begin();
	TESTED_NAMESPACE::map<t4, t5>::reverse_iterator it(it_), ite;
	printSizeMap(mp);

	std::cout << "TEST OFFSET" << std::endl;
	--it;
	printPair(it);

	it = mp.rbegin(); ite = mp.rend();
	while (it != ite)
		std::cout << "[rev] " << printPair(it++, false) << std::endl;
	printReverse(mp);
}

void test_ite_map()
{
	TESTED_NAMESPACE::map<t4, t5> mp;
	mp[1] = 2;

	TESTED_NAMESPACE::map<t4, t5>::const_iterator ite = mp.begin();
	// *ite = 42; // < -- error
	(void)ite;

    TESTED_NAMESPACE::map<t4, t5> const mp2;
	// TESTED_NAMESPACE::map<t4, t5>::iterator ite = mp2.begin(); // <-- error expected
	

    TESTED_NAMESPACE::map<char, int>::iterator it;
	TESTED_NAMESPACE::map<char, float>::const_iterator ite3;

	// std::cout << (it6 != ite3) << std::endl; // <--- error


    TESTED_NAMESPACE::map<t4, t5> mp3;
	TESTED_NAMESPACE::map<t4, t5>::iterator it4 = mp3.begin();
	TESTED_NAMESPACE::map<t4, t5>::const_iterator cit = mp3.begin();

	TESTED_NAMESPACE::map<t4, t5>::reverse_iterator rit(it4);

	TESTED_NAMESPACE::map<t4, t5>::const_reverse_iterator crit(rit);
	TESTED_NAMESPACE::map<t4, t5>::const_reverse_iterator crit_(it4);
	TESTED_NAMESPACE::map<t4, t5>::const_reverse_iterator crit_2(cit);

    rite();
}