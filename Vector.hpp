/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:22:27 by stan              #+#    #+#             */
/*   Updated: 2022/12/11 15:07:41 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <class T, class Alloc = std::allocator<T>>
    class vector
    {
        public:
            /* Typedefs */
            
                typedef T                                                          value_type;
                typedef Alloc                                                      allocator_type;
                typedef typename allocator_type::reference                         reference;
                typedef typename allocator_type::const_reference                   const_reference;
                typedef typename allocator_type::pointer                           pointer;
                typedef typename allocator_type::const_pointer                     const_pointer;
                // typedef ft::random_access_iterator<value_type>                     iterator;
                // typedef ft::random_access_iterator<const value_type>               const_iterator;
                // typedef ft::reverse_iterator<iterator>                             reverse_iterator;        
                // typedef ft::reverse_iterator<const_iterator>                       const_reverse_iterator;
                // typedef typename ft::iterator_traits<iterator>::difference_type    difference_type; 
                typedef typename allocator_type::size_type                         size_type;
                
            /* Member functions */
            
                explicit vector (const allocator_type& alloc = allocator_type())
                {
                    
                }
                
                explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
                
                template <class InputIterator>
                vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

                vector (const vector& x);

                ~vector();

                vector& operator= (const vector& x);
                
            /* Iterators */

                iterator begin();const_iterator begin() const;

                iterator end();const_iterator end() const;

                reverse_iterator rbegin();
                
                const_reverse_iterator rbegin() const;

                reverse_iterator rend();
                
                const_reverse_iterator rend() const;

                const_iterator cbegin() const noexcept;

                const_iterator cend() const noexcept;

                const_reverse_iterator crbegin() const noexcept;

                const_reverse_iterator crend() const noexcept;

            /* Capacity */

                size_type size() const;

                size_type max_size() const;

                void resize (size_type n, value_type val = value_type());

                size_type capacity() const;

                bool empty() const;

                void reserve (size_type n);

                void shrink_to_fit();

            /* Element access */
            
                reference operator[] (size_type n);
                
                const_reference operator[] (size_type n) const;

                reference at (size_type n);
                
                const_reference at (size_type n) const;

                reference front();
                
                const_reference front() const;

                reference back();
                
                const_reference back() const;

                value_type* data() noexcept;
                
                const value_type* data() const noexcept;
            
            /* Modifiers */
                
                template <class InputIterator>
                void assign (InputIterator first, InputIterator last);

                void assign (size_type n, const value_type& val);

                void push_back (const value_type& val);

                void pop_back();

                iterator insert (iterator position, const value_type& val);

                void insert (iterator position, size_type n, const value_type& val);

                template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last);

                iterator erase (iterator position);
                
                iterator erase (iterator first, iterator last);

                void swap (vector& x);

                void clear();

                template <class... Args>
                iterator emplace (const_iterator position, Args&&... args);

                template <class... Args>
                void emplace_back (Args&&... args);
            
            /* Allocator */

                allocator_type get_allocator() const;

            /* Non-member function overloads */

                template <class T, class Alloc>
                bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
                
                template <class T, class Alloc>
                bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
                
                template <class T, class Alloc>
                bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
                
                template <class T, class Alloc>
                bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
                
                template <class T, class Alloc>
                bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
                
                template <class T, class Alloc>
                bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

                template <class T, class Alloc>
                void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
            
        private:
            allocator_type _alloc;
            size_type      _capacity;
            size_type      _size;
            pointer        _begin;
    }
}