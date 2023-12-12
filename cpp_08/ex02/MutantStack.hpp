/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:47:49 by hkahsay           #+#    #+#             */
/*   Updated: 2023/12/12 15:34:34 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<iostream>
#include<iterator>
#include<stack>
#include<list>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(MutantStack const & src):std::stack<T>(src){ *this = src;}
        // MutantStack& operator= (MutantStack const & rhs)
        // {
           
        // }

        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
        const_iterator begin()const
        {
            return this->c.begin();
        }

        const_iterator end()const
        {
            return this->c.end();
        }
        
};

#endif
