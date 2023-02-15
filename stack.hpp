/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:12:13 by sdesseau          #+#    #+#             */
/*   Updated: 2023/02/15 12:44:38 by sdesseau         ###   ########.fr       */
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

                typedef Container   container_type;
                typedef T           value_type;
                typedef T&          reference;
                typedef T const &   const_reference;
                typedef size_t      size_type;

                /* Member fucntions */
                
                explicit stack( const container_type& cont = container_type() ) : c(container_type) {}

                ~stack() {}

                stack& operator=( const stack& other )
                {
                    if (this.c != other.c)
                        this.c = other.c;
                    return (*this);
                }
                
                /* Element access */
                
                reference top() { return (c.back()); }
                
                const_reference top() const { return (c.back()); }

                /* Capacity */
                
                bool empty() const { return (c.empty()); }

                size_type size() const { return (c.size()); }

                /* Modifiers */

                void push( const value_type& value ) { return (c.push_back()); }

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