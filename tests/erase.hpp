/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:02:43 by stan              #+#    #+#             */
/*   Updated: 2023/02/27 14:15:59 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

void test_erase()
{
    TESTED_NAMESPACE::vector<int> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = int(vct.size());
	printSize(vct);

	checkErase(vct, vct.erase(vct.begin() + 2));

	checkErase(vct, vct.erase(vct.begin()));
	checkErase(vct, vct.erase(vct.end() - 1));

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

	vct.push_back(42);
	vct.push_back(32);
	printSize(vct);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	vct.push_back(111);
	vct.push_back(222);
	vct.push_back(333);
	vct.push_back(444);
	printSize(vct);
	checkErase(vct, vct.erase(vct.begin(), vct.end()));
}