/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:51:49 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/28 12:37:48 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define RESET  "\033[0m" 
# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define YELLOW "\033[33m"
# define BLUE   "\033[34m"

# include <iostream>
# include <stack>

/*
we basically override the stack by referring to its underlying container
using type alias to sideline its lack of iterator 
*/

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack& src);
	MutantStack<T>& operator=(const MutantStack<T>& src);

	typedef typename std::stack<T>::container_type under_ctr;
	typedef typename under_ctr::iterator iterator;
	typedef  typename under_ctr::const_iterator const_iterator;
	
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
};

# include "MutantStack.tpp"

#endif
