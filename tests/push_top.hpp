/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:31:39 by sdesseau          #+#    #+#             */
/*   Updated: 2023/03/05 19:47:38 by sdesseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

void test_push()
{
    std::cout << "INT CONSTRUCTOR:"    << std::endl;

    TESTED_NAMESPACE::stack<int> s1;
    s1.push(1);
    std::cout << "top: " << s1.top() << std::endl;
    s1.push(2);
    std::cout << "top: " << s1.top() << std::endl;
    s1.push(212121);
    std::cout << "top: " << s1.top() << std::endl;

    std::cout << "CHAR CONSTRUCTOR:"    << std::endl;

    TESTED_NAMESPACE::stack<char> s2;
    s2.push('a');
    std::cout << "top: " << s2.top() << std::endl;
    s2.push('b');
    std::cout << "top: " << s2.top() << std::endl;
    s2.push('c');
    std::cout << "top: " << s2.top() << std::endl;

    std::cout << "FLOAT CONSTRUCTOR:"    << std::endl;


    TESTED_NAMESPACE::stack<float> s3;
    s3.push(1.1);
    std::cout << "top: " << s3.top() << std::endl;
    s3.push(2.2);
    std::cout << "top: " << s3.top() << std::endl;
    s3.push(3.3);
    std::cout << "top: " << s3.top() << std::endl;

    TESTED_NAMESPACE::stack<int>s4;

    std::cout << (s1 == s4) << std::endl;
	std::cout << (s1 != s4) << std::endl;
	std::cout << (s1 < s4) << std::endl;
	std::cout << (s1 <= s4) << std::endl;
	std::cout << (s1 > s4) << std::endl;
	std::cout << (s1 >= s4) << std::endl;

}