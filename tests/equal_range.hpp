/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:57:43 by sdesseau          #+#    #+#             */
/*   Updated: 2023/03/05 19:02:22 by sdesseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test_include.hpp"
#include "utils_test.cpp"

void test_equalrange()
{
    TESTED_NAMESPACE::map<int, std::string> m;

        m.insert(TESTED_NAMESPACE::make_pair(34, "kljd9834iuhwet"));
        m.insert(TESTED_NAMESPACE::make_pair(3468, "dfghe45sywu4hsr"));
        m.insert(TESTED_NAMESPACE::make_pair(96533, "sdfghthrdfg5456ik"));
        m.insert(TESTED_NAMESPACE::make_pair(1954894589, "jtt5454wujtjse"));
        m.insert(TESTED_NAMESPACE::make_pair(7754322, "w4wt5u4wjhstrhj"));
        m.insert(TESTED_NAMESPACE::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        m.insert(TESTED_NAMESPACE::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        m.insert(TESTED_NAMESPACE::make_pair(4, "asdfhfjgh54w3ag"));
        m.insert(TESTED_NAMESPACE::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        m.insert(TESTED_NAMESPACE::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        m.insert(TESTED_NAMESPACE::make_pair(453834782, "juytje54yaerdrj"));
        m.insert(TESTED_NAMESPACE::make_pair(19458942, "j567uysdts56y6uj5r"));
        m.insert(TESTED_NAMESPACE::make_pair(1245689793, "jr67e5674574668679789ruyerdtadh"));

        TESTED_NAMESPACE::pair<TESTED_NAMESPACE::map<int, std::string>::iterator, TESTED_NAMESPACE::map<int, std::string>::iterator> eq = m.equal_range(98583944);


    std::cout << "1er Iterateur : " << eq.first->first << "  ,  " << eq.first->second << std::endl;

    std::cout << "2eme Iterateur : " << eq.second->first << "  ,  " << eq.second->second << std::endl << std::endl;

        eq = m.equal_range(209485948);


    std::cout << "1er Iterateur : " << eq.first->first << "  ,  " << eq.first->second << std::endl;

    std::cout << "2eme Iterateur : " << eq.second->first << "  ,  " << eq.second->second << std::endl << std::endl;

        eq = m.equal_range(19458942);


    std::cout << "1er Iterateur : " << eq.first->first << "  ,  " << eq.first->second << std::endl;

    std::cout << "2eme Iterateur : " << eq.second->first << "  ,  " << eq.second->second << std::endl << std::endl;

        eq = m.equal_range(19458941);


    std::cout << "1er Iterateur : " << eq.first->first << "  ,  " << eq.first->second << std::endl;

    std::cout << "2eme Iterateur : " << eq.second->first << "  ,  " << eq.second->second << std::endl << std::endl;

        eq = m.equal_range(19458943);


    std::cout << "1er Iterateur : " << eq.first->first << "  ,  " << eq.first->second << std::endl;

    std::cout << "2eme Iterateur : " << eq.second->first << "  ,  " << eq.second->second << std::endl << std::endl;

        eq = m.equal_range(-1);


    std::cout << "1er Iterateur : " << eq.first->first << "  ,  " << eq.first->second << std::endl;

    std::cout << "2eme Iterateur : " << eq.second->first << "  ,  " << eq.second->second << std::endl << std::endl;

        eq = m.equal_range(3);


    std::cout << "1er Iterateur : " << eq.first->first << "  ,  " << eq.first->second << std::endl;

    std::cout << "2eme Iterateur : " << eq.second->first << "  ,  " << eq.second->second << std::endl << std::endl;

        eq = m.equal_range(4);


    std::cout << "1er Iterateur : " << eq.first->first << "  ,  " << eq.first->second << std::endl;

    std::cout << "2eme Iterateur : " << eq.second->first << "  ,  " << eq.second->second << std::endl << std::endl;

        eq = m.equal_range(5);


    std::cout << "1er Iterateur : " << eq.first->first << "  ,  " << eq.first->second << std::endl;

    std::cout << "2eme Iterateur : " << eq.second->first << "  ,  " << eq.second->second << std::endl << std::endl;

        eq = m.equal_range(0);


    std::cout << "1er Iterateur : " << eq.first->first << "  ,  " << eq.first->second << std::endl;

    std::cout << "2eme Iterateur : " << eq.second->first << "  ,  " << eq.second->second << std::endl << std::endl;
}