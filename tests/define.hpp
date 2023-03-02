/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:58:20 by stan              #+#    #+#             */
/*   Updated: 2023/03/02 01:50:57 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

#define T1 int
#define T2 int
typedef TESTED_NAMESPACE::pair<const T1, T2> T3;

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type
#define _pair TESTED_NAMESPACE::pair