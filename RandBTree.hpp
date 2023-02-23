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
    template < class T >
    struct Node
    {
        public:
		typedef T              value_type;
		typedef size_t         size_type;

		Node(void) :
			val(),
			color(black),
			parent(NULL),
			left(NULL),
			right(NULL)
		{}

		Node(value_type const& val,
			 int color = black,
			 Node* parent = NULL,
			 Node* left = NULL,
			 Node* right = NULL) :
				val(val),
				color(color),
				parent(parent),
				left(left),
				right(right)
		{}

		Node(Node const& src) :
			 val(src.val),
			 color(src.color),
			 parent(src.parent),
			 left(src.left),
			 right(src.right)
		{}

		~Node() {}

		Node&	operator=(Node const& rhs)
		{
			if (this == &rhs)
				return (*this);

			val = rhs.val;
			color = rhs.color;
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			return (*this);
		}

		bool	operator==(Node const& rhs) { return (val == rhs.val); }
	
	public:
		value_type	data;
		int	        color;
		Node		*parent;
		Node		*left;
		Node		*right;
    };

    template < class T, class Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T> >
        class Tree
        {

            public:
                typedef Alloc                       allocator_type;
                typedef T                           value_type;
                typedef typename T::first_type      key_type;
                typedef typename T::second_type     mapped_type;
                typedef Compare                     key_compare;
                typedef ptrdiff_t                   difference_type;
                typedef size_t                      size_type;
                typedef T                           &reference;
                typedef T                           *pointer;


               


                private:
                    Node *newNode(value_type pair, Node* parent) // allocate the new node containing the key & value
                    {
                        Node* node = _allocNode.allocate(1);
                        _allocValue.construct(&node->pair, pair);
                        node->left = NULL;
                        node->right = NULL;
                        node->parent = parent;
                        node->color = red;
                        return (node);
                    }

                    Node*                   _root;
                    Node*                   _end_node;
                    key_compare             _comp;
        };
}