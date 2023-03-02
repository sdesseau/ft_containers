/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:06:27 by stan              #+#    #+#             */
/*   Updated: 2023/03/02 20:18:21 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterators/iterator.hpp"
#include "../iterators/iterator_map.hpp"
#include <memory>
#include "../utils/RandBTree.hpp"
#include "../utils/enable_if.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
        class map
        {
            public:

                /* Typedefs */

                typedef Key                                          key_type;
        		typedef T                                            mapped_type;
        		typedef ft::pair<const key_type, mapped_type>        value_type;
        		typedef Compare                                      key_compare;
        		typedef Alloc                                        allocator_type;
        		typedef typename allocator_type::reference           reference;
        		typedef typename allocator_type::const_reference     const_reference;
        		typedef typename allocator_type::pointer             pointer;
        		typedef typename allocator_type::const_pointer       const_pointer;
        		typedef typename allocator_type::size_type           size_type;
        		typedef typename allocator_type::difference_type     difference_type;

                class value_compare
		    	{
		    		friend class map;
                    
		    		protected:

		    			key_compare comp;
		    			value_compare (key_compare c) : comp(c) {}
                        
		    		public:
                    
		    			typedef bool		result_type;
		    			typedef value_type	first_arg_type;
		    			typedef value_type	second_arg_type;
                        
		    			bool operator() (const value_type& x, const value_type& y) const
                        { return (comp(x.first, y.first)); }
		        };
                
                typedef Tree<value_type, value_compare>                             tree;
        
        		typedef ft::iterator_map<value_type, ft::Node<value_type> >          iterator;
        		typedef ft::iterator_map<const value_type, ft::Node<value_type> >    const_iterator;
        		typedef ft::reviterator_map<value_type, ft::Node<value_type> >        reverse_iterator;
        		typedef ft::reviterator_map<const value_type, ft::Node<value_type> > const_reverse_iterator;

                /* Member functions */
                
                explicit map(const key_compare& comp = key_compare()
                        , __unused const allocator_type& alloc = allocator_type()) :
                            _tree(value_compare(comp)) {}

                template< class InputIterator >
                    map(InputIterator first, InputIterator last,
                        const key_compare& comp = key_compare(), __unused const allocator_type& alloc = allocator_type(),
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
                            : _tree(value_compare(comp))
                    { insert(first, last); }

                map( const map& other ) : _tree(value_compare(key_compare()))
                { insert(other.begin(), other.end()); }
                            
                ~map()
                {
                    clear();
                    _tree.destroy_last();
                }

                map& operator=(const map& other)
                {
                    clear();
                    insert(other.begin(), other.end());
                    return (*this);
                }

                allocator_type get_allocator() const { return (allocator_type()); }

                /* Element Access */

                // mapped_type& at(const key_type& key)
                // {
                //     iterator at = find(key);
                //     if (!at)
                //         throw std::out_of_range("map::at");
                //     return ();
                // }

                // const mapped_type& at(const key_type& key) const;

                T& operator[](const key_type& key)
                {
                    insert(ft::make_pair(key, T()));
                    return (find(key)->second);
                }

                /* Iterators */

                iterator begin() { return (iterator(_tree.getRoot(), _tree.getLast(), _tree.min())); }
		        const_iterator begin() const { return (const_iterator(_tree.getRoot(), _tree.getLast(), _tree.min())); }
		        iterator end() { return (iterator(_tree.getRoot(), _tree.getLast(), _tree.getLast())); }
		        const_iterator end() const { return (const_iterator(_tree.getRoot(), _tree.getLast(), _tree.getLast())); }
        
		        reverse_iterator rbegin() { return (reverse_iterator(_tree.getRoot(), _tree.getLast(), _tree.max())); }
		        const_reverse_iterator rbegin() const { return (const_reverse_iterator(_tree.getRoot(), _tree.getLast(), _tree.max())); }
		        reverse_iterator rend() { return (reverse_iterator(_tree.getRoot(), _tree.getLast(), _tree.getLast())); }
		        const_reverse_iterator rend() const { return (const_reverse_iterator(_tree.getRoot(), _tree.getLast(), _tree.getLast())); }

                /* Capacity */

                bool empty() const
                {
                    if (size() == 0)
						return (true);
					else
						return (false);
                }

                size_type size() const { return (_tree.size()); }

                size_type max_size() const { return (_tree.max_size()); }

                /* Modifiers */

                void clear() { return (_tree.destroy()); }

                ft::pair<iterator, bool> insert(const value_type& value)
                {
                    const bool ret= _tree.insert(value);
                    return (ft::make_pair(find(value.first), ret));
                }

                iterator insert(__unused const iterator pos, const value_type& value)
                {
                    insert(value);
                    return (find(value.first));
                }

                template< class InputIt >
                    void insert(InputIt first, InputIt last)
                    {
                        for ( ; first != last; ++first)
                            insert(*first);
                    }

                iterator erase(iterator pos)
                {
                    erase(pos->first);
                    return (pos);
                }

                iterator erase(iterator first, iterator last)
                {
                    while (first != last)
                    {
                        first = find(first->first);
                        erase(first++);
                    }
                    return (first);
                }

                size_type erase( const key_type& key ) { return (_tree.delete_node(ft::make_pair(key, mapped_type()))); }

                void swap(map& other) { _tree.swap(other._tree); }

                /* Lookup */

                size_type count(const key_type& key) const { return (find(key) != end()); }

                iterator find(const key_type& key)
                { return (iterator(_tree.getRoot(), _tree.getLast(), _tree.search(ft::make_pair(key, mapped_type())))); }

                const_iterator find(const key_type& key) const
                { return (const_iterator(_tree.getRoot(), _tree.getLast(), _tree.search(ft::make_pair(key, mapped_type())))); }

                pair<iterator,iterator> equal_range(const key_type& key)
                { return (ft::make_pair(lower_bound(key), upper_bound(key))); }

                pair<const_iterator,const_iterator> equal_range(const key_type& key) const
                { return (ft::make_pair(lower_bound(key), upper_bound(key))); }

                iterator lower_bound(const key_type& key)
                { return (iterator(_tree.getRoot(), _tree.getLast(), _tree.lower_bound(ft::make_pair(key, mapped_type())))); }

                const_iterator lower_bound(const key_type& key) const
                { return (const_iterator(_tree.getRoot(), _tree.getLast(), _tree.lower_bound(ft::make_pair(key, mapped_type())))); }

                iterator upper_bound(const key_type& key)
                { return (iterator(_tree.getRoot(), _tree.getLast(), _tree.upper_bound(ft::make_pair(key, mapped_type())))); }
                
                const_iterator upper_bound(const key_type& key) const
                { return (const_iterator(_tree.getRoot(), _tree.getLast(), _tree.upper_bound(ft::make_pair(key, mapped_type())))); }

                /* Observers */

                key_compare key_comp() const { return (key_compare()); }

                value_compare value_comp() const { return (value_compare(key_comp())); }
                
            private:
                tree _tree;
            
        };

        /* Non-member functions */

        template< class key_type, class mapped_type, class key_compare, class allocator_type >
            bool operator==( const map<key_type, mapped_type, key_compare, allocator_type>& lhs, const map<key_type, mapped_type, key_compare, allocator_type>& rhs )
            { return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

        template< class key_type, class mapped_type, class key_compare, class allocator_type >
            bool operator!=( const map<key_type, mapped_type, key_compare, allocator_type>& lhs, const map<key_type, mapped_type, key_compare, allocator_type>& rhs )
            { return (!(lhs == rhs)); }

        template< class key_type, class mapped_type, class key_compare, class allocator_type >
            bool operator<( const map<key_type, mapped_type, key_compare, allocator_type>& lhs,const map<key_type, mapped_type, key_compare, allocator_type>& rhs )
            { return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

        template< class key_type, class mapped_type, class key_compare, class allocator_type >
            bool operator<=( const map<key_type, mapped_type, key_compare, allocator_type>& lhs, const map<key_type, mapped_type, key_compare, allocator_type>& rhs )
            { return (!(rhs < lhs)); }

        template< class key_type, class mapped_type, class key_compare, class allocator_type >
            bool operator>( const map<key_type, mapped_type, key_compare, allocator_type>& lhs,const map<key_type, mapped_type, key_compare, allocator_type>& rhs )
            { return (rhs < lhs); }

        template< class key_type, class mapped_type, class key_compare, class allocator_type >
            bool operator>=( const map<key_type, mapped_type, key_compare, allocator_type>& lhs, const map<key_type, mapped_type, key_compare, allocator_type>& rhs )
            { return (!(lhs < rhs)); }

        template <class Key, class T, class Compare, class Allocator>
            void swap(map<Key,T,Compare,Allocator>& lhs,
            			 map<Key,T,Compare,Allocator>& rhs)
            { lhs.swap(rhs); }
}