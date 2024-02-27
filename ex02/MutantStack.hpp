/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:51:49 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/27 19:58:24 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack& src);
	MutantStack& operator=(const MutantStack& src);

	typedef std::stack<T>::container_type under_ctr;
	typedef under_ctr::iterator iterator;
	typedef under_ctr::const_iterator const_iterator;
};

# include MutantStack.tpp

#endif