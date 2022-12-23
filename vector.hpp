/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:22:27 by stan              #+#    #+#             */
/*   Updated: 2022/12/23 16:08:33 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include <iostream>
# include "iterator.hpp"

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
				typedef Iterator_vec<random_access_iterator_tag, T>                iterator;
				typedef Iterator_vec<random_access_iterator_tag, T>                const_iterator;
				typedef RevIterator_vec<random_access_iterator_tag, T>             reverse_iterator;        
				typedef RevIterator_vec<random_access_iterator_tag, T>             const_reverse_iterator;
				typedef typename std::ptrdiff_t								       difference_type; 

				/* Member functions */

				explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _begin(NULL)
			    {}

				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n),  _size(n)
			    {
				    _begin = _alloc.allocate(n);
				    for (size_type i = 0; i < n; i++)
				    	_alloc.construct(&_begin[i], val);
			    }

				// template <class InputIterator>
				// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc)
                // {
                //     if (first > last)
                //         throw (std::invalid_argument("vector::vector"));
                //     size_type n = 0;
				// 	for (InputIterator it = first; it != last; it++)
				// 		n++;
				// 	_capacity = n;
				// 	_size = n;
				// 	_begin = _alloc.allocate(n);
				// 	for (size_type i = 0; i < n; i++)
				// 		_alloc.construct(&_begin[i], first++);
                // }

				vector (const vector& x) : _alloc(x._alloc), _capacity(x._size), _size(x._size)
			    {
				_begin = _alloc.allocate(x._size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_begin[i], x._begin[i]);
			    }

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

				/* Iterators */

				iterator begin() { return (iterator(this->_begin)); }

				const_iterator begin() const { return (const_iterator(this->_begin)); }

				iterator end() { return (iterator(this->_begin) + _size); }

				const_iterator end() const { return (const_iterator(this->_begin) + _size); }

				reverse_iterator rbegin() { return (iterator(this->_begin) +  _size - 1); }

				const_reverse_iterator rbegin() const { return (const_iterator(this->_begin) + _size - 1); }

				reverse_iterator rend() { return (iterator(this->_begin) - 1); }

				const_reverse_iterator rend() const { return (const_iterator(this->_begin) - 1); }

				/* Capacity */

				size_type size() const { return (_size); }

				size_type max_size() const { return (std::min((size_type)std::numeric_limits<std::ptrdiff_t>::max(), std::numeric_limits<size_type>::max() / sizeof(value_type))); }

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
					if (n > this->max_size())
						throw (std::invalid_argument("vector::reserve"));
					if (n > _capacity)
						_capacity = n;
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

				/* Modifiers */

				template <class InputIterator>
				void assign (InputIterator first, InputIterator last)
				{
                    if (first > last)
                        throw (std::invalid_argument("vector::assign"));
					this->clear();
					for (; first != last; first++)
                		push_back(*first);
				}

				void assign (size_type n, const value_type& val)
				{
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
					return;
				}

				void pop_back()
				{
					if (_size == 0)
						throw (std::out_of_range("vector::pop_back"));
					_alloc.destroy(&_begin[_size - 1]);
					_size--;
				}

				// iterator insert (iterator position, const value_type& val);

				// void insert (iterator position, size_type n, const value_type& val);

				// template <class InputIterator>
				// void insert (iterator position, InputIterator first, InputIterator last);

				// iterator erase (iterator position);

				// iterator erase (iterator first, iterator last);

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
				{
					resize(0);
				}

				// template <class... Args>
				// iterator emplace (const_iterator position, Args&&... args);

				// template <class... Args>
				// void emplace_back (Args&&... args);

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
            return false;
        for (size_t i = 0; i < lhs.size(); i++)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    }

	// template <class T, class Alloc>
    // bool operator != (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs == rhs); }
    
    // // template <class T, class Alloc>
    // // bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) 
    // // { return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }
    
    // template <class T, class Alloc>
    // bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return rhs < lhs; }
    
    // template <class T, class Alloc>
    // bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs > rhs); }
    
    // template <class T, class Alloc>
    // bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs < rhs); }
}