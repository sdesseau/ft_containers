/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:22:27 by stan              #+#    #+#             */
/*   Updated: 2023/03/06 17:03:29 by sdesseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include <iostream>
# include "../iterators/iterator.hpp"
# include "../utils/enable_if.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
		class vector
		{
			public:
				/* Typedefs */

				typedef T                                                          value_type;
				typedef Alloc                                                      allocator_type;
				typedef size_t                       							   size_type;
				typedef typename allocator_type::reference                         reference;
				typedef typename allocator_type::const_reference                   const_reference;
				typedef typename allocator_type::pointer                           pointer;
				typedef typename allocator_type::const_pointer                     const_pointer;
				typedef Iterator<T>                iterator;
				typedef Iterator<const T>                const_iterator;
				typedef RevIterator<T>             reverse_iterator;        
				typedef RevIterator<const T>             const_reverse_iterator;
				typedef typename std::ptrdiff_t								       difference_type; 


				/* Member functions */
			

				explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _begin(NULL) {}

				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n),  _size(n)
			    {
				    _begin = _alloc.allocate(n);
					pointer ptr = _begin;
				    for (size_type i = 0; i < n; i++)
					{
				    	_alloc.construct(ptr, val);
			    		ptr++;
					}
				}

				template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) : _alloc(alloc)
                {
					size_type n = 0;
					for (InputIterator it = first; it != last; it++)
						n++;
					_begin = _alloc.allocate(n);
					_size = n;
					_capacity = n;
					pointer ptr = _begin;
					while (n--)
					{
						_alloc.construct(_begin, *first);
						first++;
						_begin++;
					}
					_begin = ptr;
                }

				vector (const vector& x) : _alloc(x._alloc), _capacity(0), _size(0), _begin(NULL)
				{ insert(begin(), x.begin(), x.end()); }

				~vector()
				{
					this->clear();
					_alloc.deallocate(_begin, this->capacity());
				}

				vector& operator= (const vector& x)
                {
                    _alloc = x._alloc;
                    _begin = _alloc.allocate(x._size);
                    _capacity = x._size;
                    _size = x._size;
                    for (size_type i = 0; i < x._size; i++)
                        this->_begin[i] = x._begin[i];
                    return (*this);
                }
				

				/* Element access */

				reference operator[] (size_type n) { return (_begin[n]); }

				const_reference operator[] (size_type n) const { return (_begin[n]); }

				reference at(size_type n)
				{
					if (n >= _size)
						throw std::out_of_range("vector::at");
					return (_begin[n]);
				}

				const_reference at(size_type n) const
				{
					if (n >= _size)
						throw std::out_of_range("vector::at");
					return (_begin[n]);
				}

				reference front() { return (_begin[0]); }

				const_reference front() const { return (_begin[0]); }

				reference back() { return (_begin[_size - 1]); }

				const_reference back() const { return (_begin[_size - 1]); }

				T* data() { return (_begin); }
				

				/* Iterators */
				
				iterator begin() { return (iterator(this->_begin)); }

				const_iterator begin() const { return (const_iterator(this->_begin)); }
				iterator end() { return (iterator(this->_begin) + _size); }

				const_iterator end() const { return (const_iterator(this->_begin + _size)); }

				reverse_iterator rbegin() { return (reverse_iterator(iterator(this->_begin) + _size) + 1); }

				const_reverse_iterator rbegin() const { return (const_reverse_iterator(const_iterator(this->_begin) + _size) + 1); }

				reverse_iterator rend() { return (reverse_iterator(iterator(this->_begin) - 1)); }

				const_reverse_iterator rend() const { return (const_reverse_iterator(const_iterator(this->_begin) - 1)); }
				

				/* Capacity */

				size_type size() const { return (_size); }

				size_type max_size() const { return (allocator_type().max_size()); }

				void resize (size_type n, value_type val = value_type())
				{
					while (_size > n)
						pop_back();
					if (n > _capacity * 2)
						reserve(n);
					while (_size < n)
						push_back(val);
				}

				size_type capacity() const { return (_capacity); }

				bool empty() const
				{
					if (_size == 0)
						return (true);
					else
						return (false);
				}

				void reserve (size_type n)
				{
					if (n > max_size())
						throw (std::invalid_argument("vector::reserve"));	
					else if (n <= _capacity)
						return ;
						
					pointer	start = _begin;
					pointer	prev_begin = _begin;
					pointer	newptr;
					size_type prev_capa = _capacity;
					
					_begin = _alloc.allocate(n);
					newptr = _begin;
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(newptr++, *prev_begin++);
					_capacity = n;
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(start + i);
					_alloc.deallocate(start, prev_capa);
				}


				/* Modifiers */

				template <class InputIterator>
				void assign (InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
				{
                    if (first > last)
                        throw (std::invalid_argument("vector::assign"));
					this->clear();
					for (; first != last; first++)
                		push_back(*first);
				}

				void assign (size_type n, const value_type& val)
				{
					while (this->size())
						pop_back();
					while (n != 0)
					{
						push_back(val);
						n--;
					}
				}

				void push_back (const value_type& val)
				{
					if (_capacity == 0)
					{
						_capacity++;
						_begin = _alloc.allocate(_capacity);
					}
					if (_capacity > _size)
					{
						_alloc.construct(&_begin[_size], val);
						_size++;
						return ;
					}
					_capacity *= 2;
					pointer tmp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(&tmp[i], _begin[i]);
						_alloc.destroy(&_begin[i]);
					}
					_alloc.deallocate(_begin, _capacity);
					_begin = tmp;
					_alloc.construct(&_begin[_size], val);
					_size++;
				}

				void pop_back()
				{
					if (_size == 0)
						throw (std::out_of_range("vector::pop_back"));
					_alloc.destroy(&_begin[_size - 1]);
					_size--;
				}

				iterator insert (iterator position, const value_type& val)
				{
					difference_type n = position - begin();
					
					insert(position, 1, val);
					return (begin() + n);
				}

				void insert (iterator position, size_type n, const value_type& val)
				{
					iterator	it = end();
					vector		tmp(position, it);

            		if (n + _size > _capacity * 2)
            		    reserve(n + _size);
					while (it != position)
					{
						pop_back();
						it--;
					}
					while (n)
					{
						push_back(val);
						n--;
					}
					it = tmp.begin();
					while (it != tmp.end())
					{
						push_back(*it);
						it++;
					}
				}
	
				template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
				{
					iterator	it = end();
					vector		tmp(position, it);
					
            		if ((last - first) > (difference_type)(_capacity * 2))
            		    reserve((last - first) + _size);
					while (it != position)
					{
						pop_back();
						it--;
					}
					while (first != last)
					{
						push_back(*first);
						first++;;
					}
					it = tmp.begin();
					while (it != tmp.end())
					{
						push_back(*it);
						it++;
					}
				}

				iterator erase (iterator position)
				{
					iterator it = end();
					vector tmp(position, it);
					iterator ret = position;

					while (it != position)
					{
						pop_back();
						it--;
					}
					it = tmp.begin() + 1;
					while (it != tmp.end())
					{
						push_back(*it);
						it++;
					}
					return (ret);
				}

				iterator erase (iterator first, iterator last)
				{
					iterator it = end();
					vector tmp(last, end());
					iterator ret = first;
					
					while (it != first)
					{
						pop_back();
						it--;
					}
					it = tmp.begin();
					while (it != tmp.end())
					{
						push_back(*it);
						it++;
					}
					return (ret);
				}

				void swap (vector& x)
				{
					pointer tmp_begin = _begin;
					size_type tmp_size = _size;
					size_type tmp_capacity = _capacity;
					allocator_type tmp_alloc = _alloc;

					_begin = x._begin;
					_alloc = x._alloc;
					_size = x._size;
					_capacity = x._capacity;

					x._begin = tmp_begin;
					x._alloc = tmp_alloc;
					x._size = tmp_size;
					x._capacity = tmp_capacity;
				}

				void clear()
				{ resize(0); }

				/* Allocator */

				allocator_type get_allocator() const { return (_alloc); }

			private:
				allocator_type _alloc;
				size_type      _capacity;
				size_type      _size;
				pointer        _begin;
		};


	/* Non-member function overloads */

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        for (size_t i = 0; i < lhs.size(); i++)
            if (lhs[i] != rhs[i])
                return (false);
        return (true);
    }

	template <class T, class Alloc>
    bool operator != (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return !(lhs == rhs); }
    
    template <class T, class Alloc>
    bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) 
    { return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
    
    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (rhs < lhs); }
    
    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (!(rhs < lhs)); }
    
    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (!(lhs < rhs)); }
}