/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:59:59 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/28 12:59:11 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
	
Span::Span(unsigned int n) : _N(n) {}

Span::~Span(){}

Span::Span(const Span& src)
{
	*this = src;
}
Span& Span::operator=(const Span& src)
{
	if (this != &src)
	{
		this->_N = src._N;
		this->_vec = src._vec;
	}
	return (*this);
}
	
void Span::addNumber(int x)
{
	
	if (this->_vec.size() >= this->_N)
		throw std::out_of_range("Span vector already full");
	if (this->_vec.size() < this->_N)
		this->_vec.push_back(x);
}

/*
first we check vector is not empty (so we can use .begin() and .end() iterators or
throw an error.
then we copy the vector (the copy vector mem is already dynmaic and will be deleted 
when the function is out of scope)
- sort the copy 
- start with highest int limits as minspan
- implement comparison of difference in sorted pair to minspan, return the smallest of them
*/

int Span::shortestSpan() const
{
	if (_vec.empty() || _vec.size() == 1)
		throw std::out_of_range("Span vector has less than 2 values");
	
	std::vector<int>	tempvec = _vec;
	std::sort(tempvec.begin(), tempvec.end());
	int minspan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < _vec.size() - 1; ++i)
	{
		int tempspan = tempvec[i + 1] - tempvec[i];
		if (tempspan< minspan)
			minspan = tempspan;
	}
	return (minspan);
}

/*
if less than 2 elements -> throw error
iterator (const) to max and min of the vetor, return the difference
*/
int Span::longestSpan() const
{
	if (_vec.empty() || _vec.size() == 1)
		throw std::out_of_range("Span vector has less than 2 values");
	std::vector<int>::const_iterator maxIt = std::max_element(_vec.begin(), _vec.end());
	std::vector<int>::const_iterator minIt = std::min_element(_vec.begin(), _vec.end());
	return (*maxIt - *minIt);
}

void Span::printvec() const
{
	if (_vec.empty())
	{
		std::cout << "empty vector \n";
		return;
	}
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << "[" << _vec[i] <<"] ";
	std::cout << std::endl;
}

//template function defined here, subject doesn't allow .tpp
void Span::multipleAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vec.size() + std::distance(begin, end) > this->_N)
		throw std::out_of_range("ERROR : Range Filling would outgrow the Span instance");
	this->_vec.insert(_vec.begin(), begin, end);
}

