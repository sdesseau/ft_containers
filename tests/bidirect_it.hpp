/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirect_it.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:02:33 by stan              #+#    #+#             */
/*   Updated: 2023/02/27 15:12:44 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

void test_bidirect_it()
{
    TESTED_NAMESPACE::vector<TESTED_TYPE> lst;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);

	vct.insert(vct.end(), lst.begin(), lst.end());
	printSize(vct);
}
