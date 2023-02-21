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
#define red 1
#define black 0

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

            stuct Node
            {
                    value_type  data;                       // -> containing the key and the value
                    Node        *parent;                    // pointer on the parent node (nullptr if root)
                    Node        *left;                      // pointer to left child
                    Node        *right;                     // pointer to right child
                    int         height;                    // height of the node (used for balancing)
                    int         color;                      // color of the node (red or black)

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

            public:

               


                private:
                    Node *newNode(value_type pair, Node* parent) // allocate the new node containing the key & value
                    {
                        Node* node = _allocNode.allocate(1);
                        _allocValue.construct(&node->pair, pair);
                        node->left = NULL;
                        node->right = NULL;
                        node->height = 1;
                        node->parent = parent;
                        node->color = red;
                        return (node);
                    }

                    Node*                   _root;
                    Node*                   _end_node;
                    allocator_type          _allocValue;
                    std::allocator<Node>    _allocNode;
                    size_type               _size;
                    key_compare             _comp;
        };
}