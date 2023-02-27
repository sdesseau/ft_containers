/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:58:15 by stan              #+#    #+#             */
/*   Updated: 2023/02/27 13:30:12 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_utils.hpp"

namespace ft
{
    template <class T, class Node>
        class iterator_map : public iterator<bidirectional_iterator_tag, T>
        {
        
        	public:
        		typedef T                                                 value_type;
        		typedef Node*                                             node;
        		typedef iterator<bidirectional_iterator_tag, value_type>  iterator_type;
        		typedef typename iterator_type::iterator_category         iterator_category;
        		typedef typename iterator_type::difference_type           difference_type;
        		typedef typename iterator_type::pointer                   pointer;
        		typedef typename iterator_type::reference                 reference;
        
        		iterator_map(void) : _begin(NULL), _end(NULL), _ptr(NULL) {}
        
        		iterator_map(node const& begin, node const& end, node const& current) :
        			_begin(begin),
        			_end(end),
        			_ptr(current)
        		{}
        
        		iterator_map(iterator_map const& u) { *this = u; }
        
        		iterator_map&		operator=(const iterator_map& u)
        		{
        			if (this == &u)
        				return (*this);
        
        			_begin = u._begin;
        			_end = u._end;
        			_ptr = u._ptr;
        			return (*this);
        		}
        
        		~iterator_map() {}
        
        		node		get_ptr(void) const { return (_ptr); }
        
        		reference			operator*() const { return (_ptr->data); }
        
        		pointer				operator->() const { return (&(operator*())); }
        
        		iterator_map&		operator++()
        		{
        			if (_ptr == max(_begin))
        			{
        				_ptr = _end;
        				return (*this);
        			}
        			else if (_ptr == _end)
        			{
        				_ptr = NULL;
        				return (*this);
        			}
        			_ptr = successor(_ptr);
        			return (*this);
        		}
        
        		iterator_map		operator++(int)
        		{
        			iterator_map	tmp(*this);
        			operator++();
        			return (tmp);
        		}
        
        		iterator_map&		operator--()
        		{
        			if (_ptr == _end)
        			{
        				_ptr = max(_begin);
        				return (*this);
        			}
        			_ptr = predecessor(_ptr);
        			return (*this);
        		}
        
        		iterator_map		operator--(int)
        		{
        			iterator_map	tmp(*this);
        			operator--();
        			return (tmp);
        		}
        
        		// needed for conversion to a const_iterator
        		operator			iterator_map<const T, Node> (void) { return (iterator_map<const T, Node>(_begin, _end, _ptr)); }
        
        	private:
        		node	_begin;
        		node	_end;
        		node	_ptr;

                node	min(node s)
        		{
        			for ( ; s->left != _end; s = s->left);
        			return (s);
        		}
        
        		node	max(node s)
        		{
        			for ( ; s->right != _end; s = s->right);
        			return (s);
        		}
        
        		node	successor(node s)
        		{
        			if (s->right != _end)
        				return (min(s->right));
        
        			node	tmp = s->parent;
        			while (tmp != _end && s == tmp->right)
        			{
        				s = tmp;
        				tmp = tmp->parent;
        			}
        			return (tmp);
        		}
        
        		node	predecessor(node s)
        		{
        			if (s->left != _end)
        				return (max(s->left));
        
        			node	tmp = s->parent;
        			while (tmp != _end && s == tmp->left)
        			{
        				s = tmp;
        				tmp = tmp->parent;
        			}
        			return (tmp);
        		}
        };

        template <class IteratorL, class IteratorR, class _Node>
            bool	operator==(iterator_map<IteratorL, _Node> const& x, iterator_map<IteratorR, _Node> const& y)
            { return (x.get_ptr() == y.get_ptr()); }
        
        template <class IteratorL, class IteratorR, class _Node>
            bool	operator!=(iterator_map<IteratorL, _Node> const& x, iterator_map<IteratorR, _Node> const& y)
            { return (x.get_ptr() != y.get_ptr()); }

}