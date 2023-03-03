/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_map.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:36:12 by stan              #+#    #+#             */
/*   Updated: 2023/03/02 19:40:33 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

#define t1 int
#define t2 std::string
typedef _pair<const t1, t2> t3;

static int iter_erase = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter_erase++ << "] --" << std::endl;
	mp.erase(param);
	printSizeMap(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter_erase++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSizeMap(mp);
}

template <typename MAP, typename U>
void	ft_erase2(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter_erase++ << "] --" << std::endl;
	std::cout << "ret: " << mp.erase(param) << std::endl;
	printSizeMap(mp);
}

void erase2()
{
	std::list<t3> lst;
	unsigned int lst_size = 6;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(t3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::map<t1, t2> mp(lst.begin(), lst.end());
	printSizeMap(mp);

	for (int i = 2; i < 4; ++i)
		ft_erase2(mp, i);

	ft_erase2(mp, mp.begin()->first);
	ft_erase2(mp, (--mp.end())->first);

	mp[-1] = "Hello";
	mp[10] = "Hi there";
	mp[10] = "Hi there";
	printSizeMap(mp);

	ft_erase2(mp, 0);
	ft_erase2(mp, 1);
}

void test_erase_map()
{
	std::list<t3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(t3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::map<t1, t2> mp(lst.begin(), lst.end());
	printSizeMap(mp);

	ft_erase(mp, ++mp.begin());

	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp[10] = "Hello";
	mp[11] = "Hi there";
	printSizeMap(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";
	printSizeMap(mp);
	ft_erase(mp, mp.begin(), mp.end());
    erase2();
}
