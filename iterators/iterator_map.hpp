/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:58:15 by stan              #+#    #+#             */
/*   Updated: 2023/03/03 19:21:31 by sdesseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_utils.hpp"

namespace ft
{
	template <class T, class Node>
	class reviterator_map;

    template <class T, class Node>
        class iterator_map : public iterator<bidirectional_iterator_tag, T>
        {

			friend class reviterator_map<T, Node>;
			
        	public:

				/* Typedefs */

        		typedef T                                                 value_type;
        		typedef Node*                                             node;
        		typedef iterator<bidirectional_iterator_tag, value_type>  iterator_type;
        		typedef typename iterator_type::iterator_category         iterator_category;
        		typedef typename iterator_type::difference_type           difference_type;
        		typedef typename iterator_type::pointer                   pointer;
        		typedef typename iterator_type::reference                 reference;
        
        		iterator_map(void) : _begin(NULL), _end(NULL), _ptr(NULL) {}
        
        		iterator_map(node const& begin, node const& end, node const& ptr) :
        			_begin(begin), _end(end), _ptr(ptr)
        		{}
        
        		iterator_map(iterator_map const& other) { *this = other; }
        
        		iterator_map&		operator=(const iterator_map& other)
        		{
        			if (this == &other)
        				return (*this);
        			_begin = other._begin;
        			_end = other._end;
        			_ptr = other._ptr;
        			return (*this);
        		}
        
        		~iterator_map() {}
        
        		node		getPtr() const { return (_ptr); }

				iterator_map base() const { return (this); }
        
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
        
        		// const_iterator
        		operator			iterator_map<const value_type, Node> ()
				{ return (iterator_map<const value_type, Node>(_begin, _end, _ptr)); }
        
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
            { return (x.getPtr() == y.getPtr()); }
        
        template <class IteratorL, class IteratorR, class _Node>
            bool	operator!=(iterator_map<IteratorL, _Node> const& x, iterator_map<IteratorR, _Node> const& y)
            { return (x.getPtr() != y.getPtr()); }


		template <class T, class Node>
        class reviterator_map : public iterator<bidirectional_iterator_tag, T>
        {
        	public:
        		typedef T                                                 value_type;
        		typedef Node*                                             node;
        		typedef iterator<bidirectional_iterator_tag, value_type>  iterator_type;
        		typedef typename iterator_type::iterator_category         iterator_category;
        		typedef typename iterator_type::difference_type           difference_type;
        		typedef typename iterator_type::pointer                   pointer;
        		typedef typename iterator_type::reference                 reference;
        
        		reviterator_map(void) : _begin(NULL), _end(NULL), _ptr(NULL) {}
        
        		reviterator_map(node const& begin, node const& end, node const& ptr) :
        			_begin(begin), _end(end), _ptr(ptr)
        		{}

				reviterator_map(iterator_map<T, Node> const &ite)
				{
					_begin = ite._begin;
					_end = ite._end;
					_ptr = ite._ptr;
				}
        
        		reviterator_map(reviterator_map const& other) { *this = other; }
        
        		reviterator_map&		operator=(const reviterator_map& other)
        		{
        			if (this == &other)
        				return (*this);
        			_begin = other._begin;
        			_end = other._end;
        			_ptr = other._ptr;
        			return (*this);
        		}
        
        		~reviterator_map() {}
        
        		node		getPtr(void) const { return (_ptr); }

				reviterator_map base() const { return (this); }
        
        		reference			operator*() const { return (_ptr->data); }
        
        		pointer				operator->() const { return (&(operator*())); }
        
        		reviterator_map&		operator--()
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
        
        		reviterator_map		operator--(int)
        		{
        			reviterator_map	tmp(*this);
        			operator--();
        			return (tmp);
        		}
        
        		reviterator_map&		operator++()
        		{
					if (_ptr == min(_begin))
        			{
        				_ptr = _end;
        				return (*this);
        			}
        			if (_ptr == _end)
        			{
        				_ptr = min(_begin);
        				return (*this);
        			}
        			_ptr = predecessor(_ptr);
        			return (*this);
        		}
        
        		reviterator_map		operator++(int)
        		{
        			reviterator_map	tmp(*this);
        			operator++();
        			return (tmp);
        		}
        
        		// needed for conversion to a const_iterator
        		operator			reviterator_map<const value_type, Node> ()
				{ return (reviterator_map<const value_type, Node>(_begin, _end, _ptr)); }
        
        	protected:
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
            bool	operator==(reviterator_map<IteratorL, _Node> const& x, reviterator_map<IteratorR, _Node> const& y)
            { return (x.getPtr() == y.getPtr()); }
        
        template <class IteratorL, class IteratorR, class _Node>
            bool	operator!=(reviterator_map<IteratorL, _Node> const& x, reviterator_map<IteratorR, _Node> const& y)
            { return (x.getPtr() != y.getPtr()); }


}