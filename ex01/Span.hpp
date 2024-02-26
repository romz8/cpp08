/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:47:07 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/26 17:04:15 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
private:
	std::vector<int> _vec;
	unsigned int _N;

public:
	Span(unsigned int n);
	~Span();
	Span(const Span& src);
	Span& operator=(const Span& src);
	
	void addNumber(int x);
	int shortestSpan() const;
	int longestSpan() const;
	
	template <typename T>
	void multipleAdd(typename T::iterator begin, typename T::iterator end);
	
	void printvec() const;
};

//tempalte function defined here, subject doesn't allow .tpp
template <typename T>
void Span::multipleAdd(typename T::iterator begin, typename T::iterator end)
{
	if (std::distance(begin, end) >= this->_N)
		throw std::out_of_range("Range Filling would outgrow the Span instance");
	for (typename T::const_iterator start = begin; start != end; ++start)
		this->addNumber(*start);
}
#endif
