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

    struct t_red_black_node
    {
        enum { red, black } colour;
        void *item;
        struct t_red_black_node *left,
                         *right,
                         *parent;
    };

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

                public:

                    rb_insert( Tree T, node x )
                    {
                        /* Insert in the tree in the usual way */
                        tree_insert( T, x );
                        /* Now restore the red-black property */
                        x->colour = red;
                        while ( (x != T->root) && (x->parent->colour == red) ) {
                           if ( x->parent == x->parent->parent->left ) {
                               /* If x's parent is a left, y is x's right 'uncle' */
                               y = x->parent->parent->right;
                               if ( y->colour == red ) {
                                   /* case 1 - change the colours */
                                   x->parent->colour = black;
                                   y->colour = black;
                                   x->parent->parent->colour = red;
                                   /* Move x up the tree */
                                   x = x->parent->parent;
                                   }
                               else {
                                   /* y is a black node */
                                   if ( x == x->parent->right ) {
                                       /* and x is to the right */ 
                                       /* case 2 - move x up and rotate */
                                       x = x->parent;
                                       left_rotate( T, x );
                                       }
                                   /* case 3 */
                                   x->parent->colour = black;
                                   x->parent->parent->colour = red;
                                   right_rotate( T, x->parent->parent );
                                   }
                               }
                           else {
                               /* repeat the "if" part with right and left
                                  exchanged */
                               }
                           }
                        /* Colour the root black */
                        T->root->colour = black;
                    }

                    left_rotate( Tree T, node x )
                    {
                        Node y;
                        y = x->right;
                        /* Turn y's left sub-tree into x's right sub-tree */
                        x->right = y->left;
                        if ( y->left != NULL )
                            y->left->parent = x;
                        /* y's new parent was x's parent */
                        y->parent = x->parent;
                        /* Set the parent to point to y instead of x */
                        /* First see whether we're at the root */
                        if ( x->parent == NULL ) T->root = y;
                        else
                            if ( x == (x->parent)->left )
                                /* x was on the left of its parent */
                                x->parent->left = y;
                            else
                                /* x must have been on the right */
                                x->parent->right = y;
                        /* Finally, put x on y's left */
                        y->left = x;
                        x->parent = y;
                    }
            };
        };
}