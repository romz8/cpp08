/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:17:19 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/23 12:49:23 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

template<typename container>
typename container::iterator easyfind(container& ctr, int n)
{
        typename container::iterator found = find(ctr.begin(), ctr.end(), n);
        if (found != ctr.end())
                return (found);
        throw std::logic_error("no occurrence found");
}

#endif
