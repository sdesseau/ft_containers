/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:21:14 by stan              #+#    #+#             */
/*   Updated: 2023/03/05 18:08:13 by sdesseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

#define t1 int
#define t2 std::string
typedef TESTED_NAMESPACE::map<t1, t2>::value_type t3;
typedef TESTED_NAMESPACE::map<t1, t2>::iterator iterator;

static int iter_insert = 0;

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	_pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter_insert++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSizeMap(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert1(MAP &mp, U param, V param2)
{
	iterator tmp;

	std::cout << "\t-- [" << iter_insert++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSizeMap(mp);
}

template <typename MAP, typename U>
void	ft_insert2(MAP &mp, U param, U param2)
{
	std::cout << "\t-- [" << iter_insert++ << "] --" << std::endl;
	mp.insert(param, param2);
	printSizeMap(mp);
}

void insert2()
{
    std::list<t3> lst;
	std::list<t3>::iterator itlst;

	lst.push_back(t3(42, "lol"));

	lst.push_back(t3(50, "mdr"));
	lst.push_back(t3(35, "funny"));

	lst.push_back(t3(45, "bunny"));
	lst.push_back(t3(21, "fizz"));
	lst.push_back(t3(38, "buzz"));
	lst.push_back(t3(55, "fuzzy"));

	std::cout << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);

	TESTED_NAMESPACE::map<t1, t2> mp;
	ft_insert2(mp, lst.begin(), lst.end());

	mp.at(42);

	lst.clear();

	lst.push_back(t3(87, "hey"));
	lst.push_back(t3(47, "eqweqweq"));
	lst.push_back(t3(35, "this key is already inside"));
	lst.push_back(t3(23, "but not that one"));
	lst.push_back(t3(1, "surprising isnt it?"));
	lst.push_back(t3(100, "is it enough??"));
	lst.push_back(t3(55, "inside map too"));

	std::cout << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);

	ft_insert2(mp, lst.begin(), lst.begin());
	ft_insert2(mp, lst.begin(), lst.end());
}

void test_insert()
{
    TESTED_NAMESPACE::map<t1, t2> mp, mp2;

	ft_insert(mp, t3(42, "lol"));
	ft_insert(mp, t3(42, "mdr"));

	ft_insert(mp, t3(50, "mdr"));
	ft_insert(mp, t3(35, "funny"));

	ft_insert(mp, t3(45, "bunny"));
	ft_insert(mp, t3(21, "fizz"));
	ft_insert(mp, t3(38, "buzz"));

	ft_insert1(mp, mp.begin(), t3(55, "fuzzy"));

	ft_insert1(mp2, mp2.begin(), t3(1337, "beauty"));
	ft_insert1(mp2, mp2.end(), t3(1000, "Hello"));
	ft_insert1(mp2, mp2.end(), t3(1500, "World"));

    insert2();
}