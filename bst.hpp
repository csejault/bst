/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:50:03 by csejault          #+#    #+#             */
/*   Updated: 2022/03/22 18:54:35 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//SOURCES :	Introduction to Algorithms : Thomas H. Cormen - Charles E. Leiserson - Ronald L. Rivest - Clifford Stein
//Class_Name = bst

//define{
#ifndef BST_HPP
# define BST_HPP

# ifndef COL_GREEN
#  define COL_GREEN 		"\033[0;32m"
# endif
# ifndef COL_RED
#  define COL_RED		"\033[0;31m"
# endif
# ifndef COL_YELLOW
#  define COL_YELLOW		"\033[0;33m"
# endif
# ifndef COL_NORMAL
#  define COL_NORMAL		"\033[0m"
# endif

# include <iostream>
# include "node.hpp"
template < typename T >
class node;
//define - END}

template < typename T >
class	bst {
	public:
		typedef	typename node<T>::node_type		node_type;
		typedef	typename node<T>::nd			nd;
		typedef	typename node<T>::value_type	value_type;
		//pub_constructor{
		bst( void ) : root(NULL) {}
		~bst( void ) { delete_tree(root); }
		//pub_constructor - END}

		//pub_operator{
		//pub_operator - END}

		//pub_debug{
		//pub_debug - END}

		//pub_static{

		//pub_static - END}

		//pub_getter{
		//pub_getter - END}

		//pub_setter{
		//pub_setter - END}

		//pub_exception{
		//pub_exception - END}

		//pub_fct{
		void	add_value(value_type k)
		{
			nd n = new node_type(k);
			t_insert(n);
		}

		void	delete_tree( nd p ) {
			if (p)
			{
				delete_tree(p->left);
				delete p;
				delete_tree(p->right);
			}
		}

		void	inorder_walk( void ) {
			inorder_walk(root);
		}

		void	inorder_walk( nd p ) {
			if (p)
			{
				inorder_walk(p->left);
				p->print_key();
				inorder_walk(p->right);
			}
		}

		nd	search(nd n, value_type k)
		{
			if (!n || n->key == k)
				return (n);
			if (k < n->key)
				return (search(n->left, k));
			else
				return (search(n->right, k));
		}

		nd	iterative_search(nd n, value_type k)
		{
			while (n && k != n->key)
			{
				if (k < n->key)
					n = n->left;
				else
					n = n->right;
			}
			return (n);
		}

		void	t_insert(nd n)
		{
			nd y = NULL;
			nd x = root;
			while (x)
			{
				y = x;
				if (n->key < x->key)
					x = x->left;
				else
					x = x->right;
			}
			n->p = y;
			if (!y)
				root = n;
			else if (n->key < y->key)
				y->left = n;
			else
				y->right = n;
		}

		void transplant(nd u, nd v)
		{
			nd t = root;
			if (!u->p)
				*t = v;
			else if (u == u->p->left)
				u->p->left = v;
			else
				u->p->right = v;
			if (v)
				v->p = u->p;
		}

		void	t_delete(nd z)
		{
			if (!z->left)
				transplant(z,z->right);
			else if (!z->right)
				transplant(z,z->left);
			else
			{
				nd y = z->right->minimum();
				if (y->p != z)
				{
					transplant(y,y->right);
					y->right = z->right;
					y->right->p = y;
				}
				transplant(z,y);
				y->left = z->left;
				y->left->p = y;
			}
		}
		//pub_fct - END}

		//pub_var{
		nd		root;
		//pub_var - END}

	private:
		//priv_debug{
		//priv_debug - END}

		//priv_constructor{
		//priv_constructor - END}

		//priv_static{
		//priv_static - END}

		//priv_var{
		//priv_var - END}
};

//out_class{
//std::ostream &	operator<<(std::ostream &os, bst &to_print);
//out_class - END}

#endif

//Color{
//The codes for foreground and background colours are:
//
//         foreground background
//black        30         40
//red          31         41
//green        32         42
//yellow       33         43
//blue         34         44
//magenta      35         45
//cyan         36         46
//white        37         47
//Color - END}
