/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_utils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:36:04 by stan              #+#    #+#             */
/*   Updated: 2023/03/02 20:17:47 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

namespace ft
{
    struct input_iterator_tag {};

    struct output_iterator_tag {};

    struct forward_iterator_tag : public input_iterator_tag {};

    struct bidirectional_iterator_tag : public forward_iterator_tag {};

    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    /* Iterator Traits */
    template <class Iterator>
        struct iterator_traits
        {
        	typedef typename Iterator::difference_type     difference_type;
        	typedef typename Iterator::value_type          value_type;
        	typedef typename Iterator::pointer             pointer;
        	typedef typename Iterator::reference           reference;
        	typedef typename Iterator::iterator_category   iterator_category;
        };
    
    template <class T>
        struct iterator_traits<T*>
        {
        	typedef ptrdiff_t                              difference_type;
        	typedef T                                      value_type;
        	typedef T*                                     pointer;
        	typedef T&                                     reference;
        	typedef random_access_iterator_tag	           iterator_category;
        };
    
    template <class T>
        struct iterator_traits<const T*>
        {
        	typedef ptrdiff_t                              difference_type;
        	typedef T                                      value_type;
        	typedef T*                                     pointer;
        	typedef T&                                     reference;
        	typedef random_access_iterator_tag	           iterator_category;
        };


    template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
        struct iterator
        {
	    	typedef Category		iterator_category;	
	    	typedef T		        value_type;	
	    	typedef Distance		difference_type;	
	    	typedef Pointer		    pointer;	
	    	typedef Reference		reference;
        };



    template<class InputIt1, class InputIt2>
    	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2)
    	{
    	    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
    	    {
    	        if (*first1 < *first2)
    	            return (true);
    	        if (*first1 > *first2)
    	            return (false);
    	    }
    	    return ((first1 == last1) && (first2 != last2));
    	}

    template <class InputIt1, class InputIt2>
        bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
        {
        	for ( ; first1 != last1; ++first1, ++first2)
        	{
        		if (!(*first1 == *first2))
        			return (false);
        	}
        	return (true);
        }
}