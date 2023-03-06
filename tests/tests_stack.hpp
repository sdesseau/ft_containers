/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_stack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:53:35 by stan              #+#    #+#             */
/*   Updated: 2023/03/06 16:07:41 by sdesseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"
#include <cstdio>

void tests_stack()
{
	TESTED_NAMESPACE::stack<int> mystack;

	for (int i = 0; i < 5; ++i)
		mystack.push(i);
	
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';

	mystack.push(42);
	mystack.push(21);
	mystack.push(84);
	mystack.push(42);
	mystack.push(21);
	mystack.push(84);
	printf("size: %lu\n", mystack.size());
	printf("top: %d\n", mystack.top());
	mystack.pop();
	printf("top: %d\n", mystack.top());
	mystack.pop();
	printf("top: %d\n", mystack.top());
	mystack.pop();
	printf("top: %d\n", mystack.top());
	printf("empty: %d\n", mystack.empty());

	
	TESTED_NAMESPACE::stack<int> mystack2;
	mystack2.push(42);
	mystack2.push(21);
	mystack2.push(84);
	mystack2.push(42);
	mystack2.push(21);
	// test operator ==
	printf("operator ==: %d\n", mystack == mystack2);
	// test operator !=
	printf("operator !=: %d\n", mystack != mystack2);
	// test operator <
	printf("operator <: %d\n", mystack < mystack2);
	// test operator <=
    printf("operator <=: %d\n", mystack <= mystack2);
	// test operator >
	printf("operator >: %d\n", mystack > mystack2);
	// test operator >=
	printf("operator >=: %d\n", mystack >= mystack2);
	// test operator =
	TESTED_NAMESPACE::stack<int> mystack3;
	mystack3 = mystack;
	printf("size: %lu\n", mystack3.size());
	printf("top: %d\n", mystack3.top());
	mystack3.pop();
}