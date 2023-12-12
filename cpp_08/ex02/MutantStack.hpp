/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:47:49 by hkahsay           #+#    #+#             */
/*   Updated: 2023/12/12 14:11:36 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<iostream>
#include<iterator>
#include<stack>

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
        //     if  (this != &rhs)
        //     {
        //         this->c = c.rhs;
        //     }
        //     return *this;
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
// std::ostream & operator<<(std::ostream &os, MutantStack const & rhs)
// {
//     return os;
// }
#endif
//  class myIterator
//         {
//             private:
//                 std::stack<int>::myIterator   _begin;
//                 std::stack<int>::myIterator   _end;
//             public:
//                 myIterator();
//                 ~myIterator();
//                 myIterator(int begin, int end);
//                 myIterator(const myIterator & src);
//                 myIterator & operator= (const myIterator & rhs);
//                 bool    operator ==(const myIterator & rhs)const;

//         };