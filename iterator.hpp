/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:28:49 by stan              #+#    #+#             */
/*   Updated: 2023/02/23 19:33:06 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_utils.hpp"
#include <cstddef>

namespace ft
{
    template <class Category, class T >
        class Iterator : public ft::iterator<ft::random_access_iterator_tag, T>
        {
            private:
                T *_ptr;
            public:
                typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category 	iterator_category;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		    value_type;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			    pointer;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			    reference;

    
                Iterator() : _ptr(NULL) {}
    
                Iterator(T *ptr) : _ptr(ptr) {}
    
                Iterator(const Iterator &other) : _ptr(other._ptr) {}
    
                ~Iterator() {}
    
                Iterator &operator=(const Iterator& other)
                {
                    _ptr = other._ptr;
                    return (*this);
                }

                Iterator &operator=(const T& other)
                {
                    *_ptr = other;
                    return (*this);
                }
                
                Iterator &operator++()
                {
                    _ptr++;
                    return (*this);
                }
    
                Iterator &operator--()
                {
                    _ptr--;
                    return (*this);
                }
    
                Iterator operator++(int)
                {
                    Iterator tmp(*this);
                    _ptr++;
                    return (tmp);
                }
                Iterator operator--(int)
                {
                    Iterator tmp(*this);
                    _ptr--;
                    return (tmp);
                }
    
                Iterator operator+(int i)
                {
                    Iterator tmp(*this);
                    tmp._ptr += i;
                    return (tmp);
                }

                Iterator &operator+=(int i)
                {
                    _ptr += i;
                    return (*this);
                }
    
                Iterator operator-(int i)
                {
                    Iterator tmp(*this);
                    tmp._ptr -= i;
                    return (tmp);
                }
                
                Iterator &operator-=(int i)
                {
                    _ptr -= i;
                    return (*this);
                }
    
                reference operator*() const {return (*_ptr);}
                pointer operator->() const {return (&(operator*)());}

                friend Iterator operator+(int lhs, const Iterator& rhs)
	            {
	            	return Iterator(rhs._ptr + lhs);
	            }

                friend difference_type operator+(const Iterator& a, const Iterator& b)
                {
                    return (a._ptr - b._ptr);
                }
                friend Iterator	operator-(difference_type n, const Iterator& it) 
                {
                    return (Iterator(it._ptr - n));
                }
    
                friend difference_type operator-(const Iterator& a, const Iterator& b)
                {
                    return (a._ptr - b._ptr);
                }

                Iterator operator[](int i)
                {
                    Iterator tmp(*this);
                    tmp._ptr += i;
                    return (tmp);
                }
                
                bool operator==(const Iterator &other) const { return (_ptr == other._ptr); }
                bool operator!=(const Iterator &other) const { return (_ptr != other._ptr); }
                bool operator>=(const Iterator &other) const { return (_ptr >= other._ptr); }
                bool operator<=(const Iterator &other) const { return (_ptr <= other._ptr); }
                bool operator>(const Iterator &other) const { return (_ptr > other._ptr); }
                bool operator<(const Iterator &other) const { return (_ptr < other._ptr); }
        };
    
    template <class Category, class T >
        class RevIterator : public ft::iterator<ft::random_access_iterator_tag, T>
        {
            private:
                T *_ptr;
            public:
                typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category 	iterator_category;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		    value_type;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			    pointer;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			    reference;
    
    
                RevIterator() : _ptr(NULL) {}
    
                RevIterator(T *ptr) : _ptr(ptr) {}
    
                RevIterator(const RevIterator &other) : _ptr(other._ptr) {}
    
                ~RevIterator() {}
    
                RevIterator& operator=(const RevIterator& other)
                {
                    _ptr = other._ptr;
                    return (*this);
                }
                
                RevIterator &operator++()
                {
                    _ptr--;
                    return (*this);
                }
    
                RevIterator &operator--()
                {
                    _ptr++;
                    return (*this);
                }
    
                RevIterator operator++(int)
                {
                    RevIterator tmp(*this);
                    _ptr--;
                    return tmp;
                }
                RevIterator operator--(int)
                {
                    RevIterator tmp(*this);
                    _ptr++;
                    return tmp;
                }
    
                RevIterator &operator+(int i)
                {
                    _ptr += i;
                    return (*this);
                }
    
                RevIterator &operator-(int i)
                {
                    _ptr -= i;
                    return (*this);
                }
    
                T &operator*() {return (*_ptr);}
                T *operator->() {return (&(operator*)());}

                // needed for conversion to a const_iterator
		        operator			RevIterator<random_access_iterator_tag, const T>(void)
		        {
		        	return (RevIterator<random_access_iterator_tag, const T>(_ptr));
		        }
    
                friend RevIterator	operator-(difference_type n, const RevIterator& it) 
                {
                    return (RevIterator(it._ptr - n));
                }
    
                friend difference_type	operator-(const RevIterator& a, const RevIterator& b)
                {
                    return (a._ptr - b._ptr);
                }
    
                bool operator==(const RevIterator &other) const { return (_ptr == other._ptr); }
                bool operator!=(const RevIterator &other) const { return (_ptr != other._ptr); }
                bool operator>=(const RevIterator &other) const { return (_ptr >= other._ptr); }
                bool operator<=(const RevIterator &other) const { return (_ptr <= other._ptr); }
                bool operator>(const RevIterator &other) const { return (_ptr > other._ptr); }
                bool operator<(const RevIterator &other) const { return (_ptr < other._ptr); }
        };
}

