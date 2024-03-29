/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:28:49 by stan              #+#    #+#             */
/*   Updated: 2023/03/06 13:58:14 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_utils.hpp"
#include "iterator_map.hpp"
#include <cstddef>

namespace ft
{
    template <class T>
        class Iterator : public iterator<ft::random_access_iterator_tag, T>
        {
            public:
                /* Typedefs */
                
                typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category 	iterator_category;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		    value_type;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			    pointer;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			    reference;


                /* Constructors */
                
                Iterator() : _ptr(NULL) {}
    
                Iterator(T *ptr) : _ptr(ptr) {}
    
                Iterator(const Iterator& other) : _ptr(other.getPtr()) {}
    
                ~Iterator() {}

                pointer getPtr() const { return (_ptr); }

				Iterator base() const { return (this); }
    
                Iterator& operator=(const Iterator& other)
                {
        			if (this == &other)
        				return (*this);
                    _ptr = other.getPtr();
                    return (*this);
                }


                /* Operators */

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

                Iterator operator[](int i)
                {
                    Iterator tmp(*this);
                    tmp._ptr += i;
                    return (tmp);
                }
                
                friend Iterator operator+(int lhs, const Iterator& rhs)
	            { return Iterator(rhs._ptr + lhs); }

                friend difference_type operator+(const Iterator& a, const Iterator& b)
                { return (a._ptr + b._ptr); }
                
                friend Iterator	operator-(difference_type n, const Iterator& it) 
                { return (Iterator(it._ptr - n)); }

                friend difference_type operator-(const Iterator& a, const Iterator& b)
                { return (a._ptr - b._ptr); }
    
                reference operator*() const {return (*_ptr);}
                pointer operator->() const {return (&(operator*)());}


                /* Const Iterator */

	        	operator				Iterator<const T>(void)
	        	{ return Iterator<const T>(_ptr); }
                
            private:
                T *_ptr;
        };

    template <class IteratorL, class IteratorR>
        bool operator==(const Iterator<IteratorL> &otherL, const Iterator<IteratorR> &otherR)
        { return (otherL.getPtr() == otherR.getPtr()); }

    template <class IteratorL, class IteratorR>
        bool operator!=(const Iterator<IteratorL> &otherL, const Iterator<IteratorR> &otherR)
        { return (otherL.getPtr() != otherR.getPtr()); }
        
    template <class IteratorL, class IteratorR>
        bool operator>=(const Iterator<IteratorL> &otherL, const Iterator<IteratorR> &otherR)
        { return (otherL.getPtr() >= otherR.getPtr()); }

    template <class IteratorL, class IteratorR>
        bool operator<=(const Iterator<IteratorL> &otherL, const Iterator<IteratorR> &otherR)
        { return (otherL.getPtr() <= otherR.getPtr()); }

    template <class IteratorL, class IteratorR>
        bool operator>(const Iterator<IteratorL> &otherL, const Iterator<IteratorR> &otherR)
        { return (otherL.getPtr() > otherR.getPtr()); }
        
    template <class IteratorL, class IteratorR>
        bool operator<(const Iterator<IteratorL> &otherL, const Iterator<IteratorR> &otherR)
        { return (otherL.getPtr() < otherR.getPtr()); }








    template <class T >
        class RevIterator : public ft::iterator<ft::random_access_iterator_tag, T>
        {
            public:
                /* Typedefs */

                typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category 	iterator_category;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		    value_type;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			    pointer;	
	    	    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			    reference;


                /* Constructors */
                
                RevIterator() : _ptr(NULL) {}
    
                RevIterator(T *ptr) : _ptr(ptr) {}

                RevIterator(const Iterator<T> &other) : _ptr(other.getPtr()) {}
    
                RevIterator(const RevIterator &other) : _ptr(other.getPtr()) {}

                pointer getPtr() const { return (_ptr); }

				RevIterator base() const { return (this); }
    
    
                /* Operators */
                
                RevIterator &operator=(const RevIterator& other)
                {
                    _ptr = other.getPtr();
                    return (*this);
                }

                RevIterator &operator=(const T& other)
                {
                    *_ptr = other;
                    return (*this);
                }
                
                RevIterator &operator++()
                {
                    --_ptr;
                    return (*this);
                }
    
                RevIterator &operator--()
                {
                    ++_ptr;
                    return (*this);
                }
    
                RevIterator operator++(int)
                {
                    RevIterator tmp(*this);
                    --_ptr;
                    return (tmp);
                }
                RevIterator operator--(int)
                {
                    RevIterator tmp(*this);
                    ++_ptr;
                    return (tmp);
                }
    
                RevIterator operator+(int i)
                {
                    RevIterator tmp(*this);
                    tmp._ptr -= i;
                    return (tmp);
                }

                RevIterator &operator+=(int i)
                {
                    _ptr -= i;
                    return (*this);
                }
    
                RevIterator operator-(int i)
                {
                    RevIterator tmp(*this);
                    tmp._ptr += i;
                    return (tmp);
                }
                
                RevIterator &operator-=(int i)
                {
                    _ptr += i;
                    return (*this);
                }
    
                RevIterator operator[](int i)
                {
                    RevIterator tmp(*this);
                    tmp._ptr -= i;
                    return (tmp);
                }

                friend RevIterator operator+(int lhs, const RevIterator& rhs)
	            {
	            	return (RevIterator(rhs._ptr - lhs));
	            }
                
                friend RevIterator	operator-(difference_type n, const RevIterator& it) 
                {
                    return (RevIterator(it._ptr + n));
                }
    
                friend difference_type operator-(const RevIterator& a, const RevIterator& b)
                {
                    return (-1 * (a._ptr - b._ptr));
                }

                reference operator*() const {return (*_ptr);}
                pointer operator->() const {return (&(operator*()));}


                /* Const Iterator*/
                
	        	operator				RevIterator<const T>(void)
	        	{
	        		return (RevIterator<const T>(_ptr));
	        	}

            protected:
                T *_ptr;
        };

        template <class IteratorL, class IteratorR>
            bool operator==(const RevIterator<IteratorL> &otherL, const RevIterator<IteratorR> &otherR)
            { return (otherL.getPtr() == otherR.getPtr()); }

        template <class IteratorL, class IteratorR>
            bool operator!=(const RevIterator<IteratorL> &otherL, const RevIterator<IteratorR> &otherR)
            { return (otherL.getPtr() != otherR.getPtr()); }

        template <class IteratorL, class IteratorR>
            bool operator>=(const RevIterator<IteratorL> &otherL, const RevIterator<IteratorR> &otherR)
            { return (otherL.getPtr() <= otherR.getPtr()); }

        template <class IteratorL, class IteratorR>
            bool operator<=(const RevIterator<IteratorL> &otherL, const RevIterator<IteratorR> &otherR)
            { return (otherL.getPtr() >= otherR.getPtr()); }

        template <class IteratorL, class IteratorR>
            bool operator>(const RevIterator<IteratorL> &otherL, const RevIterator<IteratorR> &otherR)
            { return (otherL.getPtr() < otherR.getPtr()); }
            
        template <class IteratorL, class IteratorR>
            bool operator<(const RevIterator<IteratorL> &otherL, const RevIterator<IteratorR> &otherR)
            { return (otherL.getPtr() > otherR.getPtr()); }
}

