/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:12:13 by sdesseau          #+#    #+#             */
/*   Updated: 2023/03/06 02:20:21 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "vector.hpp"

namespace ft
{
    template < class T, class Container = vector<T> >
        class stack
        {
            public:

                /* Typedefs */
                
                typedef T           value_type;
                typedef T&          reference;
                typedef T const &   const_reference;
                typedef Container   container_type;
                typedef size_t      size_type;

                /* Member fucntions */
                
                explicit stack( const container_type& ctnr = container_type() ) : c(ctnr) {}

                ~stack() {}

                stack& operator=( const stack& other )
                {
                    this->c = other->c;
                    return (*this);
                }
                
                /* Element access */
                
                reference top() { return (c.back()); }
                
                const_reference top() const { return (c.back()); }

                /* Capacity */
                
                bool empty() const { return (c.empty()); }

                size_type size() const { return (c.size()); }

                /* Modifiers */

                void push( const value_type& value ) { return (c.push_back(value)); }

                void pop() { return (c.pop_back()); }

                friend bool operator==(stack const & l, stack const & r) { return (l.c == r.c); };
			    friend bool operator!=(stack const & l, stack const & r) { return (l.c != r.c); };
			    friend bool operator<(stack const & l, stack const & r) { return (l.c < r.c); };
			    friend bool operator<=(stack const & l, stack const & r) { return (l.c <= r.c); };
			    friend bool operator>(stack const & l, stack const & r) { return (l.c > r.c); };
			    friend bool operator>=(stack const & l, stack const & r) { return (l.c >= r.c); };
    
            protected:
                container_type c;
        };
}