/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:20:51 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/23 13:12:05 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <cstdlib> 

/*
receive an empty non-associative container and a size, 
fill it with random values (modulo max char to be potential int, float, char)
then randomly either return a number that is guarantee to be inside the continer 
or not
*/
template <typename T>
typename T::value_type seqctr_loader(T& ctr, size_t size)
{
        for (size_t i = 0; i < size; ++i)
        {
                typename T::value_type val = static_cast<typename T::value_type>(rand() % std::numeric_limits<char>::max());
                ctr.push_back(val);
        }
        int idx = rand();
        if (idx % 2)
        {
                idx = idx % size;
                typename T::iterator it = ctr.begin();
                for (int i = 0; i < idx; ++i)
                    it++;
                std::cout << "look for : " << *it << std::endl;
                return (*it);
        }
        else
        {
            std::cout << "NO FOUND GUARANTEE :look for : " << idx << std::endl;
            return (idx);
        }
}

template <typename T>
void find_wrapper(T ctr, int n)
{
     try 
    {
        typename T::iterator r = easyfind(ctr, n);
        std::cout << "found : " << *r << " in the cointainer\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

template <typename Container>
void printContainer(const Container& container) 
{
    typename Container::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
        std::vector<int> vec;
        std::vector<float> lst;
        std::deque<double> dq;
        //std::list<std::string> lst;
        // std::queue<char> q;
        // std::stack<double> stk;

        int i = seqctr_loader(vec, 20);
        float f = seqctr_loader(lst, 10);
        double d = seqctr_loader(dq, 42);
        
        printContainer(vec);
        printContainer(lst);
        printContainer(dq);
        
        find_wrapper(vec, i);
        find_wrapper(lst, f);
        find_wrapper(dq, d);
}   
