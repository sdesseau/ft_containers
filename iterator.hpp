/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:28:49 by stan              #+#    #+#             */
/*   Updated: 2023/02/21 18:31:11 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

namespace ft
{

    struct input_iterator_tag {};

    struct output_iterator_tag {};

    struct forward_iterator_tag : public input_iterator_tag {};

    struct bidirectional_iterator_tag : public forward_iterator_tag {};

    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
        struct iterator_traits
        {
	    	typedef Category		iterator_category;	
	    	typedef T		        value_type;	
	    	typedef Distance		difference_type;	
	    	typedef Pointer		    pointer;	
	    	typedef Reference		reference;
        };
    
    template <class Category, class T, class Distance = ptrdiff_t, class Reference = T&, class Pointer = T*>
        class Iterator_vec : public ft::iterator_traits<ft::random_access_iterator_tag, T>
        {
            private:
                T *_ptr;
            public:
                typedef typename ft::iterator_traits<ft::random_access_iterator_tag, T>::iterator_category 	iterator_category;	
	    	    typedef typename ft::iterator_traits<ft::random_access_iterator_tag, T>::value_type		    value_type;	
	    	    typedef typename ft::iterator_traits<ft::random_access_iterator_tag, T>::difference_type		difference_type;	
	    	    typedef typename ft::iterator_traits<ft::random_access_iterator_tag, T>::pointer			    pointer;	
	    	    typedef typename ft::iterator_traits<ft::random_access_iterator_tag, T>::reference			    reference;

    
                Iterator_vec() : _ptr(NULL) {}
    
                Iterator_vec(T *ptr) : _ptr(ptr) {}
    
                Iterator_vec(const Iterator_vec &other) : _ptr(other._ptr) {}
    
                ~Iterator_vec() {}
    
                Iterator_vec &operator=(const Iterator_vec& other)
                {
                    _ptr = other._ptr;
                    return (*this);
                }

                Iterator_vec &operator=(const T& other)
                {
                    *_ptr = other;
                    return (*this);
                }
                
                Iterator_vec &operator++()
                {
                    _ptr++;
                    return (*this);
                }
    
                Iterator_vec &operator--()
                {
                    _ptr--;
                    return (*this);
                }
    
                Iterator_vec operator++(int)
                {
                    Iterator_vec tmp(*this);
                    _ptr++;
                    return (tmp);
                }
                Iterator_vec operator--(int)
                {
                    Iterator_vec tmp(*this);
                    _ptr--;
                    return (tmp);
                }
    
                Iterator_vec operator+(int i)
                {
                    Iterator_vec tmp(*this);
                    tmp._ptr += i;
                    return (tmp);
                }

                Iterator_vec &operator+=(int i)
                {
                    _ptr += i;
                    return (*this);
                }
    
                Iterator_vec operator-(int i)
                {
                    Iterator_vec tmp(*this);
                    tmp._ptr -= i;
                    return (tmp);
                }
                
                Iterator_vec &operator-=(int i)
                {
                    _ptr -= i;
                    return (*this);
                }
    
                reference operator*() const {return (*_ptr);}
                pointer operator->() const {return (&(operator*)());}

                friend Iterator_vec operator+(int lhs, const Iterator_vec& rhs)
	            {
	            	return Iterator_vec(rhs._ptr + lhs);
	            }

                friend difference_type operator+(const Iterator_vec& a, const Iterator_vec& b)
                {
                    return (a._ptr - b._ptr);
                }
                friend Iterator_vec	operator-(difference_type n, const Iterator_vec& it) 
                {
                    return (Iterator_vec(it._ptr - n));
                }
    
                friend difference_type operator-(const Iterator_vec& a, const Iterator_vec& b)
                {
                    return (a._ptr - b._ptr);
                }

                Iterator_vec operator[](int i)
                {
                    Iterator_vec tmp(*this);
                    tmp._ptr += i;
                    return (tmp);
                }
                
                bool operator==(const Iterator_vec &other) const { return (_ptr == other._ptr); }
                bool operator!=(const Iterator_vec &other) const { return (_ptr != other._ptr); }
                bool operator>=(const Iterator_vec &other) const { return (_ptr >= other._ptr); }
                bool operator<=(const Iterator_vec &other) const { return (_ptr <= other._ptr); }
                bool operator>(const Iterator_vec &other) const { return (_ptr > other._ptr); }
                bool operator<(const Iterator_vec &other) const { return (_ptr < other._ptr); }
        };
    
    template <class Category, class T, class Distance = ptrdiff_t, class Reference = T&, class Pointer = T*>
        class RevIterator_vec : public ft::iterator_traits<ft::random_access_iterator_tag, T>
        {
            private:
                T *_ptr;
            public:
                typedef typename ft::iterator_traits<ft::random_access_iterator_tag, T>::iterator_category 	iterator_category;	
	    	    typedef typename ft::iterator_traits<ft::random_access_iterator_tag, T>::value_type		    value_type;	
	    	    typedef typename ft::iterator_traits<ft::random_access_iterator_tag, T>::difference_type		difference_type;	
	    	    typedef typename ft::iterator_traits<ft::random_access_iterator_tag, T>::pointer			    pointer;	
	    	    typedef typename ft::iterator_traits<ft::random_access_iterator_tag, T>::reference			    reference;
    
    
                RevIterator_vec() : _ptr(NULL) {}
    
                RevIterator_vec(T *ptr) : _ptr(ptr) {}
    
                RevIterator_vec(const RevIterator_vec &other) : _ptr(other._ptr) {}
    
                ~RevIterator_vec() {}
    
                RevIterator_vec& operator=(const RevIterator_vec& other)
                {
                    _ptr = other._ptr;
                    return (*this);
                }
                
                RevIterator_vec &operator++()
                {
                    _ptr--;
                    return (*this);
                }
    
                RevIterator_vec &operator--()
                {
                    _ptr++;
                    return (*this);
                }
    
                RevIterator_vec operator++(int)
                {
                    RevIterator_vec tmp(*this);
                    _ptr--;
                    return tmp;
                }
                RevIterator_vec operator--(int)
                {
                    RevIterator_vec tmp(*this);
                    _ptr++;
                    return tmp;
                }
    
                RevIterator_vec &operator+(int i)
                {
                    _ptr += i;
                    return (*this);
                }
    
                RevIterator_vec &operator-(int i)
                {
                    _ptr -= i;
                    return (*this);
                }
    
                T &operator*() {return (*_ptr);}
                T *operator->() {return (&(operator*)());}
    
                friend RevIterator_vec	operator-(difference_type n, const RevIterator_vec& it) 
                {
                    return (RevIterator_vec(it._ptr - n));
                }
    
                friend difference_type	operator-(const RevIterator_vec& a, const RevIterator_vec& b)
                {
                    return (a._ptr - b._ptr);
                }
    
                bool operator==(const RevIterator_vec &other) const { return (_ptr == other._ptr); }
                bool operator!=(const RevIterator_vec &other) const { return (_ptr != other._ptr); }
                bool operator>=(const RevIterator_vec &other) const { return (_ptr >= other._ptr); }
                bool operator<=(const RevIterator_vec &other) const { return (_ptr <= other._ptr); }
                bool operator>(const RevIterator_vec &other) const { return (_ptr > other._ptr); }
                bool operator<(const RevIterator_vec &other) const { return (_ptr < other._ptr); }
        };
}

