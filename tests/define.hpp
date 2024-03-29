/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:58:20 by stan              #+#    #+#             */
/*   Updated: 2023/03/06 16:12:18 by sdesseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define TESTED_TYPE int
#define TESTED_TYPE2 int
#define TESTED_NAMESPACE ft
#define T1 int
#define T2 int
typedef TESTED_NAMESPACE::pair<const T1, T2> T3;

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type
#define _pair TESTED_NAMESPACE::pair