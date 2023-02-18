/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandBTree.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:13:40 by stan              #+#    #+#             */
/*   Updated: 2023/02/16 17:13:55 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "pair.hpp"
#include <algorithm>

namespace ft
{
    template <class T, class Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T>>
        class Tree
        {
            typedef Alloc                       allocator_type;
            typedef T                           value_type;
            typedef typename T::first_type      key_type;
            typedef typename T::second_type     mapped_type;
            typedef Compare                     key_compare;
            typedef ptrdiff_t                   difference_type;
            typedef size_t                      size_type;
            typedef T                           &reference;
            typedef T                           *pointer;

            struct Node
            {
                value_type  pair;                       // -> containing the key and the value
                Node        *parent;                    // pointer on the parent node (nullptr if root)
                Node        *left;                      // pointer to left child
                Node        *right;                     // pointer to right child
                int         height;                     // height of the node (used for balancing)

                Node *min()                             // return the minimum node of the subtree
                {
                    Node *cur = this;
                    while (cur->left != nullptr)
                        cur = cur->left;
                    return cur;
                }

                Node *max()                             // return the maximum node of the subtree
                {
                    Node *cur = this;
                    while (cur->right != nullptr)
                        cur = cur->right;
                    return cur;
                }
            };
        };
}