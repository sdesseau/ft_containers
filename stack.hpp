/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:12:13 by sdesseau          #+#    #+#             */
/*   Updated: 2023/02/16 15:22:08 by stan             ###   ########.fr       */
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

                typedef T           value_type;
                typedef T&          reference;
                typedef T const &   const_reference;
                typedef Container   container_type;
                typedef size_t      size_type;

                /* Member fucntions */
                
                explicit stack( const container_type& c = container_type() ) : c(c) {}

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

            protected:
                container_type c;
        };
    
    /* Non-member functions */

    template< class T, class Container >
        bool operator==( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) { return (lhs == rhs); }

    template< class T, class Container >
        bool operator!=( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) { return (lhs != rhs); }

    template< class T, class Container >
        bool operator< ( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) { return (lhs < rhs); }

    template< class T, class Container >
        bool operator<=( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) { return (lhs <= rhs); }

    template< class T, class Container >
        bool operator> ( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) { return (lhs > rhs); }

    template< class T, class Container >
        bool operator>=( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) { return (lhs >= rhs); }
}