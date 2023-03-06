/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:10:05 by stan              #+#    #+#             */
/*   Updated: 2023/03/06 14:04:03 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{	
	template< bool Condition, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T> { typedef T type; };


	template <class T>
		struct is_integral { static const bool value = false; };
	
	template <>
		struct is_integral<bool> { static const bool value = true; };
	template <>
		struct is_integral<char> { static const bool value = true; };
	template <>
		struct is_integral<wchar_t> { static const bool value = true; };
	template <>
		struct is_integral<signed char> { static const bool value = true; };
	template <>
		struct is_integral<short int> { static const bool value = true; };
	template <>
		struct is_integral<int> { static const bool value = true; };
	template <>
		struct is_integral<long int> { static const bool value = true; };
	template <>
		struct is_integral<long long int> { static const bool value = true; };
	template <>
		struct is_integral<unsigned char> { static const bool value = true; };
	template <>
		struct is_integral<unsigned short int> { static const bool value = true; };
	template <>
		struct is_integral<unsigned int> { static const bool value = true; };
	template <>
		struct is_integral<unsigned long int> { static const bool value = true; };
	template <>
		struct is_integral<unsigned long long int> { static const bool value = true; };
}