/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:10:30 by stan              #+#    #+#             */
/*   Updated: 2023/02/18 18:21:58 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <class T, class U>
    class pair
    {
        public:
            typedef T first_type;
            typedef U second_type;
            pair() : first(), second() {}
            pair(const T &first, const U &second) : first(first), second(second) {}
            pair(const pair &other) : first(other.first), second(other.second) {}
            pair &operator=(const pair &other)
            {
                first = other.first;
                second = other.second;
                return (*this);
            }
            template<class V, class W>
            pair(const pair<V, W> &other) : first(other.first), second(other.second) {}

            bool operator==(const pair &other) const { return (first == other.first && second == other.second); }
            bool operator!=(const pair &other) const { return !(*this == other); }
            bool operator<(const pair &other) const { return (first < other.first || (first == other.first && second < other.second)); }
            bool operator>(const pair &other) const { return (first > other.first || (first == other.first && second > other.second)); }
            bool operator<=(const pair &other) const { return !(*this > other); }
            bool operator>=(const pair &other) const { return !(*this < other); }
        
            first_type first;
            second_type second;
    };

    template <class T1, class T2>
        ft::pair<T1, T2> make_pair(T1 x, T2 y) { return (ft::pair<T1, T2>(x, y)); }

}