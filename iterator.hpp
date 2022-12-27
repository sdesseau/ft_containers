/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:28:49 by stan              #+#    #+#             */
/*   Updated: 2022/12/27 14:51:42 by sdesseau         ###   ########.fr       */
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

    template<class Iterator>
    class iterator_traits
    {
	    public :
	    	typedef typename Iterator::iterator_category	iterator_category;
	    	typedef typename Iterator::value_type		    value_type;	
	    	typedef typename Iterator::difference_type	    difference_type;	
	    	typedef typename Iterator::pointer		        pointer;	
	    	typedef typename Iterator::reference		    reference;	
    };
    
    template <class Category, class T, class Distance = ptrdiff_t, class Reference = T&, class Pointer = T*>
    class Iterator_vec
    {
        private:
            T *_ptr;
        public:
            typedef T           value_type;
            typedef Category    iterator_category;
            typedef Reference   reference;
            typedef Distance    difference_type;


            Iterator_vec() : _ptr(NULL) {}

            Iterator_vec(T *ptr) : _ptr(ptr) {}

            Iterator_vec(const Iterator_vec &other) : _ptr(other._ptr) {}

            ~Iterator_vec() {}

            Iterator_vec& operator=(const Iterator_vec& other)
            {
                _ptr = other._ptr;
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
                return tmp;
            }
            Iterator_vec operator--(int)
            {
                Iterator_vec tmp(*this);
                _ptr--;
                return tmp;
            }

            Iterator_vec &operator+(int i)
            {
                _ptr += i;
                return (*this);
            }

            Iterator_vec &operator-(int i)
            {
                _ptr -= i;
                return (*this);
            }

            // friend Iterator_vec	operator-(difference_type n, const Iterator_vec& it) 
            // {
            //     return Iterator_vec(it._ptr - n); 
            // }
            // friend difference_type	operator-(const Iterator_vec& a, const Iterator_vec& b)
            // {
            //     return (a._ptr - b._ptr);
            // }

            T &operator*() {return (*_ptr);}
            T *operator->() {return (&(operator*)());}
            
            bool operator==(const Iterator_vec &other) const { return (_ptr == other._ptr); }
            bool operator!=(const Iterator_vec &other) const { return (_ptr != other._ptr); }
            bool operator>=(const Iterator_vec &other) const { return (_ptr >= other._ptr); }
            bool operator<=(const Iterator_vec &other) const { return (_ptr <= other._ptr); }
            bool operator>(const Iterator_vec &other) const { return (_ptr > other._ptr); }
            bool operator<(const Iterator_vec &other) const { return (_ptr < other._ptr); }

            static const bool iter = true;
    };

    template <class Category, class T, class Distance = ptrdiff_t, class Reference = T&, class Pointer = T*>
    class RevIterator_vec
    {
        private:
            T *_ptr;
        public:
            typedef T           value_type;
            typedef Category    iterator_category;
            typedef Reference   reference;
            typedef Distance    difference_type;


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
                _ptr++;
                return (*this);
            }

            RevIterator_vec &operator--()
            {
                _ptr--;
                return (*this);
            }

            RevIterator_vec operator++(int)
            {
                RevIterator_vec tmp(*this);
                _ptr++;
                return tmp;
            }
            RevIterator_vec operator--(int)
            {
                RevIterator_vec tmp(*this);
                _ptr--;
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

            bool &operator==(const RevIterator_vec &other) const { return (_ptr == other._ptr); }
            bool &operator!=(const RevIterator_vec &other) const { return (_ptr != other._ptr); }
            bool &operator>=(const RevIterator_vec &other) const { return (_ptr >= other._ptr); }
            bool &operator<=(const RevIterator_vec &other) const { return (_ptr <= other._ptr); }
            bool &operator>(const RevIterator_vec &other) const { return (_ptr > other._ptr); }
            bool &operator<(const RevIterator_vec &other) const { return (_ptr < other._ptr); }

            static const bool iter = true;
    };
}