/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:06:27 by stan              #+#    #+#             */
/*   Updated: 2023/02/18 18:20:25 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"
#include <memory>
#include "RandBTree.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<Key, T>> >
        class map
        {
            public:

                /* Typedefs */

                typedef Key                                                 key_type;
                typedef T                                                   mapped_type;
                typedef ft::pair<key_type, mapped_type>                     value_type;
                typedef Alloc                                               allocator_type;
                typedef size_t                                              size_type;
                typedef Compare                                             key_compare;
                typedef typename allocator_type::reference                  reference;
				typedef typename allocator_type::const_reference            const_reference;
				typedef typename allocator_type::pointer                    pointer;
				typedef typename allocator_type::const_pointer              const_pointer;
                typedef Tree<value_type, Compare, Alloc>                    tree;
                typedef Tree<const value_type, Compare, Alloc>              const_tree;
                typedef typename Tree::node                                 Node;
                typedef typename Tree::value_compare                        value_compare;
                typedef Iterator_map<bidirectional_iterator_tag, tree>         iterator;
				typedef Iterator_map<bidirectional_iterator_tag, const_tree, tree>         const_iterator;
				typedef RevIterator_map<bidirectional_iterator_tag, T, tree>      reverse_iterator;        
				typedef RevIterator_map<bidirectional_iterator_tag, T, const tree, tree>      const_reverse_iterator;

                /* Member functions */
                
                explicit map(const Compare& comp, const Allocator& alloc = Allocator());

                template< class InputIterator >
                    map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator());
            
                ~map();

                map& operator=(const map& other);

                allocator_type get_allocator() const;

                /* Element Access */

                T& at(const Key& key);

                const T& at(const Key& key) const;

                T& operator[](const Key& key);

                /* Iterators */

                iterator begin();

                const_iterator begin() const;

                iterator end();

                const_iterator end() const;

                reverse_iterator rbegin();

                const_reverse_iterator rbegin() const;

                reverse_iterator rend();

                const_reverse_iterator rend() const;

                /* Capacity */

                bool empty() const;

                size_type size() const;

                size_type max_size() const;

                /* Modifiers */

                void clear();

                pair<iterator, bool> insert(const value_type& value);

                iterator insert(iterator pos, const value_type& value);

                iterator erase(iterator pos);

                iterator erase(iterator first, iterator last);

                void swap(map& other);

                /* Lookup */

                size_type count(const Key& key) const;

                iterator find(const Key& key);

                const_iterator find(const Key& key) const;

                pair<iterator,iterator> equal_range(const Key& key);

                pair<const_iterator,const_iterator> equal_range(const Key& key) const;

                iterator lower_bound(const Key& key);

                const_iterator lower_bound(const Key& key) const;

                iterator upper_bound(const Key& key);
                
                const_iterator upper_bound(const Key& key) const;

                /* Observers */

                key_compare key_comp() const;

                value_compare value_comp() const;
                
            private:
            
        };

        /* Non-member functions */

        template< class Key, class T, class Compare, class Alloc >
            bool operator==( const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs );

        template< class Key, class T, class Compare, class Alloc >
            bool operator!=( const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs );

        template< class Key, class T, class Compare, class Alloc >
            bool operator<( const map<Key, T, Compare, Alloc>& lhs,const map<Key, T, Compare, Alloc>& rhs );

        template< class Key, class T, class Compare, class Alloc >
            bool operator<=( const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs );

        template< class Key, class T, class Compare, class Alloc >
            bool operator>( const map<Key, T, Compare, Alloc>& lhs,const map<Key, T, Compare, Alloc>& rhs );

        template< class Key, class T, class Compare, class Alloc >
            bool operator>=( const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs );
}