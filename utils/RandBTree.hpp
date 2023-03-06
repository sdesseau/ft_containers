/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandBTree.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:13:40 by stan              #+#    #+#             */
/*   Updated: 2023/02/16 17:13:55 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "pair.hpp"
#include <algorithm>
#define red 1
#define black 0

namespace ft
{
    template <class T>
    struct Node
    {
        public:
		
            typedef T              value_type;
		    typedef size_t         size_type;

		    Node(void) :
		    	data(),
		    	color(black),
		    	parent(NULL),
		    	left(NULL),
		    	right(NULL)
		    {}

		    Node(value_type const& data,
		    	 int color = black, Node* parent = NULL, Node* left = NULL, Node* right = NULL) :
                    data(data), color(color), parent(parent), left(left), right(right)
		    {}

		    Node(Node const& src) :
                data(src.data), color(src.color), parent(src.parent), left(src.left), right(src.right)
		    {}

		    ~Node() {}

		    Node&	operator=(Node const& rhs)
		    {
		    	if (this == &rhs)
		    		return (*this);
		    	data = rhs.data;
		    	color = rhs.color;
		    	parent = rhs.parent;
		    	left = rhs.left;
		    	right = rhs.right;
		    	return (*this);
		    }

		    bool	operator==(Node const& rhs) { return (data == rhs.val); }

		    value_type	data;
		    int	        color;
		    Node		*parent;
		    Node		*left;
		    Node		*right;
    };

    template < class T, class Compare, class Node = Node<T>, class Allocator = std::allocator<Node> >
        class Tree
        {
            public:
                
                /* Typedefs */
                
                typedef T                                           value_type;
                typedef Compare                                     value_compare;
                typedef Allocator                                   allocator_type;
                typedef Node                                        node_type;
                typedef typename allocator_type::reference          reference;
                typedef typename allocator_type::const_reference    const_reference;
                typedef typename allocator_type::pointer            pointer;
                typedef typename allocator_type::const_pointer      const_pointer;
                typedef typename allocator_type::size_type          size_type;
                typedef typename allocator_type::difference_type    difference_type;

                /* Member functions */
               
                Tree(value_compare const &comp = value_compare()) : _comp(comp)
                {
                    _end = allocator_type().allocate(1);
                    allocator_type().construct(_end, node_type());
                    _root = _end;
                }

                ~Tree() {}

                /* Element Access */

                pointer getRoot() const { return (_root); }
                pointer getLast() const { return (_end);}

                pointer min(pointer node) const
                {
                    if (node == NULL || node == _end)
                        return (_end);
                    for ( ; node->left != _end; node = node->left);
                    return (node);
                }

                pointer min() const { return min(_root); }

                pointer max(pointer node) const
                {
                    if (node == NULL || node == _end)
                        return (_end);
                    for ( ; node->right != _end; node = node->right);
                    return (node);
                }

                pointer max() const { return max(_root); }

                pointer search(const value_type& key) const { return (recursive_search(_root, key)); }

                pointer successor(pointer node) const           // return le noeud juste au dessus de la node
                {
                    if (node->right != _end)                    // cas ou la node a un sous-arbre droit
                        return (min(node->right));
                    if (node->parent == NULL || node == max())   // cas ou la node est le max
                        return (_end);

                    pointer tmp = node->parent;
                    while (tmp != _end && node == tmp->right)   // trouver le successeur en remontant
                    {
                        node = tmp;
                        tmp = tmp->parent;
                    }
                    return (tmp);                               // return lorsque la node n'est plus le fils droit
                }

                pointer predecessor(pointer node) const       // return le noeud juste en dessous de la node (inverse de successor)
                {
                    if (node->left != _end)
                        return (max(node->left));
                    if (node->parent == NULL || node == min())
                        return (_end);

                    pointer tmp = node->parent;
                    while (tmp != _end && node == tmp->left)
                    {
                        node = tmp;
                        tmp = tmp->parent;
                    }
                    return (tmp);
                }

                pointer lower_bound(const value_type& value) const      // return le premier noeud qui est n'est pas < (>=) a value
                {
                    pointer find = min();

                    for ( ; find != _end; find = successor(find))
                    {
                        if (!(_comp(find->data, value)))   
                            break;
                    }
                    return (find);
                }

                pointer upper_bound(const value_type& value) const   // return le premier noeud qui est < a value
                {
                    pointer find = min();

                    for ( ; find != _end; find = successor(find))
                    {
                        if (_comp(value, find->data))   
                            break;
                    }
                    return (find);
                }

                /* Capacity */

                size_type size(pointer root) const
                {
                    if (root == _end)
                        return (0);
                    return (size(root->right) + size(root->left) + 1);
                }

                size_type size() const { return (size(_root)); }
                size_type max_size() const { return (allocator_type().max_size()); }

                /* Public Modifiers */

                void    transplant(pointer a, pointer b)              // echanger deux noeuds
                {
                    if (a->parent == NULL)                // cas a == root
                        _root = b;
                    else if (a == a->parent->left)        // cas a est un enfant gauche
                        a->parent->left = b;
                    else                                  // cas a est un enfant droit
                        a->parent->right = b; 
                    b->parent = a->parent;                // MAJ des parents
                }

                bool    insert(const value_type& key)                 // inserer un noeud
                {
                    pointer y = NULL;
                    pointer x = _root;

                    while (x != _end)                    // trouver l'emplacement ou inserer
                    {
                        y = x;
                        if (_comp(key, x->data))
                            x = x->left;
                        else if (_comp(x->data, key))
                            x = x->right;
                        else                            // key deja dans l'arbre
                            return (false);
                    }

                    pointer s = allocator_type().allocate(1);
                    allocator_type().construct(s, node_type(key, red, y, _end, _end));
                    if (y == NULL)                       // cas arbre vide
                        _root = s;
                    else if (_comp(s->data, y->data))   // cas nouveau noeud a inserer a gauche
                        y->left = s;
                    else                                // cas nouveau noeud a inserer a droite
                        y->right = s;
                    if (s->parent == NULL)               // cas arbre vide
                    {
                        s->color = black;               // regle : racine toujours noire
                        return (true);
                    }
                    if (s->parent->parent == NULL)      // cas nouveau noeud = enfant de root = pas besoin de fixup
                        return (true);
                    insertFixup(s);                     // réequilibrage de l'arbre
                    return (true);
                }

                size_type    delete_node(const value_type& key)        // delete un noeud
                {
                    pointer z = _end;
                    pointer node = _root;
                    pointer x, y;

                    while (node != _end)                             // trouver le noeud
                    {
                        if (_comp(key, node->data))
                            node  = node->left;
                        else if (_comp(node->data, key))
                            node = node->right;
                        else                                         // key trouvée
                        {
                            z = node;
                            node = node->right;
                        }
                    }
                    if (z == _end)                                  // cas ou la key n'existe pas
                        return (0);
                    y = z;
                    int y_original_color = y->color;
                                                                   // trouver le noeud a remplacer
                    if (z->left == _end)                           // cas 1 fils gauche
                    {
                        x = z->right;
                        transplant(z, z->right);
                    }                                              // cas 1 fils droit
                    else if (z->right == _end)
                    {
                        x = z->left;
                        transplant(z, z->left);
                    }
                    else                                           // cas 2 enfants
                    {
                        y = min(z->right);
                        y_original_color = y->color;
                        x = y->right;
                        if (y->parent == z)
                            x->parent = y;
                        else
                        {
                            transplant(y, y->right);
                            y->right = z->right;
                            y->right->parent = y;
                        }
                        transplant(z, y);
                        y->left = z->left;
                        y->left->parent = y;
                        y->color = z->color;
                    }

                    allocator_type().destroy(z);
                    allocator_type().deallocate(z, 1);

                    if (y_original_color == black)              // cas ou l'enfant du noeud a supprimer est noir, fixup necessaire
                        deleteFixup(x);
                    return (1);
                }

                void	destroy()
		        {
		        	recursive_destroy(_root);
		        	_root = _end;
		        }

		        void    destroy_last()
		        {
		        	allocator_type().destroy(_end);
		        	allocator_type().deallocate(_end, 1);
		        }

                void    swap(Tree &ptr)
                {
                    pointer tmp_root = _root;
                    pointer tmp_end = _end;
                    _root = ptr.getRoot();
                    _end = ptr.getLast();
                    ptr._root = tmp_root;
                    ptr._end = tmp_end;
                }

                /* Printing */

                // give the width of the tree

                int     width(pointer node) const
                {
                    if (node == _end)
                        return (0);
                    return (std::max(width(node->left), width(node->right)) + 1);
                }

                // print the tree structure and color using the width fonction

                void    printTree(pointer node, int space) const
                { 
                    if (node == _end)
                        return ;
                    space += width(_root);
                    printTree(node->right, space);
                    std::cout << std::endl;
                    for (int i = width(_root); i < space; i++)
                        std::cout << " ";
                    // create little stick for left and right child
                    if (node->parent != NULL)
                    {
                        if (node->parent->left == node)
                            std::cout << "/";
                        else
                            std::cout << "\\";
                    }
                    if (node->color == red)
                        std::cout << "\033[1;31m" << "<" << node->data.first << ", " << node->data.second << ">" << "\033[0m" << std::endl;
                    else
                        std::cout << "\033[1;32m" << "<" << node->data.first << ", " << node->data.second << ">" << "\033[0m" << std::endl;
                    printTree(node->left, space);
                }



            private:

                /* Private functions */

                pointer recursive_search(pointer node, const value_type& key) const
                {
                    if (node == _end)
                        return (node);
                    else if (_comp(key, node->data))
                        return (recursive_search(node->left, key));
                    else if (_comp(node->data, key))
                        return (recursive_search(node->right, key));
                    return (node);
                }

                void    left_rotate(pointer node)
                {
                    pointer tmp = node->right;             // tmp = sous arbre droit de la node

                    node->right = tmp->left;               // sous arbre droit de la node = sous arbre gauche de tmp
                    if (tmp->left != _end)                 // MAJ des parents impliqués
                        tmp->left->parent = node;
                    tmp->parent = node->parent;
                    if (node->parent == NULL)              // cas ou la node était la racine
                        _root = tmp;
                    else if (node == node->parent->left)
                        node->parent->left = tmp;
                    else
                        node->parent->right = tmp;
                    tmp->left = node;                    // MAJ des liens tmp et de la node
                    node->parent = tmp;
                }

                void    right_rotate(pointer node)        // inverse de left_rotate
                {
                    pointer tmp = node->left;

                    node->left = tmp->right;
                    if (tmp->right != _end)
                        tmp->right->parent = node;
                    tmp->parent = node->parent;
                    if (node->parent == NULL)
                        _root = tmp;
                    else if (node == node->parent->right)
                        node->parent->right = tmp;
                    else
                        node->parent->left = tmp;
                    tmp->right = node;
                    node->parent = tmp;
                }

                void    insertFixup(pointer node)
                {
                    pointer uncle;

                    while (node->parent->color == red)                     // continuer la fonction tant que le parent est rouge
                    {
                        if (node->parent == node->parent->parent->right)   // si le parent est un enfant droit
                        {
                            uncle = node->parent->parent->left;
                            if (uncle->color == red)                      // cas 1 : l'oncle est rouge
                            {
                                uncle->color = black;
                                node->parent->color = black;
                                node->parent->parent->color = red;
                                node = node->parent->parent;
                            }
                            else                                          // cas 2 : l'oncle est noir
                            {
                                if (node == node->parent->left)          // cas pas de ligne, right_rotate pour en creer une
                                {
                                    node = node->parent;
                                    right_rotate(node);
                                }
                                node->parent->color = black;           
                                node->parent->parent->color = red;
                                left_rotate(node->parent->parent);      // left_rotate pour finir le fixup
                            }
                        }
                        else                                            // si le parent est un enfant gauche
                        {
                            uncle = node->parent->parent->right;
                            if (uncle->color == red)
                            {
                                uncle->color = black;
                                node->parent->color = black;
                                node->parent->parent->color = red;
                                node = node->parent->parent;
                            }
                            else
                            {
                                if (node == node->parent->right)    // similaire a au dessus mais inversé
                                {
                                    node = node->parent;
                                    left_rotate(node);
                                }
                                node->parent->color = black;
                                node->parent->parent->color = red;
                                right_rotate(node->parent->parent);
                            }
                        }
                        if (node == _root)
                            break;
                    }
                    _root->color = black;                        // regle root est toujours noire
                }

                void    deleteFixup(pointer node)
                {
                    pointer sibling;

                    while (node != _root && node->color == black)
                    {
                        if (node == node->parent->left)       // cas x = left, sibling = right
                        {
                            sibling = node->parent->right;
                            if (sibling->color == red)       // cas 1, le frere est rouge
                            {
                                sibling->color = black;
                                node->parent->color = red;
                                left_rotate(node->parent);
                                sibling = node->parent->right;
                            }
                            if (sibling->left->color == black && sibling->right->color == black) // cas 2, le frere de la node est noir et ses deux enfants sont noirs
                            {
                                sibling->color = red;
                                node = node->parent;
                            }
                            else
                            {
                                if (sibling->right->color == black)                  // cas 3, le frere de la node est noir, il a un fils gauche rouge et un droit noir
                                {
                                    sibling->left->color = black;
                                    sibling->color = red;
                                    right_rotate(sibling);
                                    sibling = node->parent->right;
                                }
                                sibling->color = node->parent->color;              // cas 4, le frere de la node est noir et son fils droit est rouge
                                node->parent->color = black;
                                sibling->right->color = black;
                                left_rotate(node->parent);
                                node = _root;
                            }
                        }
                        else
                        {
                            sibling = node->parent->left;
                            if (sibling->color == red)       // cas 1, le frere est rouge
                            {
                                sibling->color = black;
                                node->parent->color = red;
                                right_rotate(node->parent);
                                sibling = node->parent->left;
                            }
                            if (sibling->left->color == black && sibling->right->color == black) // cas 2, le frere de la node est noir et ses deux enfants sont noirs
                            {
                                sibling->color = red;
                                node = node->parent;
                            }
                            else
                            {
                                if (sibling->left->color == black)                  // cas 3, le frere de la node est noir, il a un fils droit rouge et un gauche noir
                                {
                                    sibling->right->color = black;
                                    sibling->color = red;
                                    left_rotate(sibling);
                                    sibling = node->parent->left;
                                }
                                sibling->color = node->parent->color;              // cas 4, le frere de la node est noir et son fils gauche est rouge
                                node->parent->color = black;
                                sibling->left->color = black;
                                right_rotate(node->parent);
                                node = _root;
                            }
                        }
                    }
                    node->color = black;
                }

                void    recursive_destroy(pointer node)
                {
                    if (node == _end)
                        return ;
                    recursive_destroy(node->left);
                    recursive_destroy(node->right);
                    allocator_type().destroy(node);
                    allocator_type().deallocate(node, 1);
                }

            

                pointer                   _root;
                pointer                   _end;
                value_compare             _comp;
        };
}