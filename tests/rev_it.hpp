/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:03:02 by stan              #+#    #+#             */
/*   Updated: 2023/02/27 15:19:01 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

template <typename Ite_1, typename Ite_2>
void ft_eq_ope2(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

void test_rev_it()
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator begin(vct.rbegin());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator end(vct.rend());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator middle;

	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cbegin = vct.rbegin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cend;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cmiddle;

	for (int i = size; begin != end; --i)
		*begin++ = i;
	printSize(vct, 1);
	begin = vct.rbegin();
	cend = vct.rend();
	middle = begin + 3;
	cmiddle = begin + 3; cmiddle = cbegin + 3; cmiddle = middle;

	std::cout << std::boolalpha;
	std::cout << ((begin + 3 == cbegin + 3) && (cbegin + 3 == middle)) << std::endl;

	std::cout << "\t\tft_eq_ope:" << std::endl;
	// regular it
	ft_eq_ope2(begin + 3, middle);
	ft_eq_ope2(begin, end);
	ft_eq_ope2(end - 3, middle);
	// const it
	ft_eq_ope2(cbegin + 3, cmiddle);
	ft_eq_ope2(cbegin, cend);
	ft_eq_ope2(cend - 3, cmiddle);
	// // both it
	ft_eq_ope2(begin + 3, cmiddle);
	ft_eq_ope2(middle, cbegin + 3);
	ft_eq_ope2(begin, cend);
	ft_eq_ope2(end, cbegin);
	ft_eq_ope2(end - 3, cmiddle);
	ft_eq_ope2(middle, cend - 3);

}