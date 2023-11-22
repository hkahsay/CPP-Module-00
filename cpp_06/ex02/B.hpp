/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:24:09 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:24:09 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

#include "Base.hpp"
#include <iostream>
#include<ctime>

class B : public Base
{
    private:
    /* data */
    public:
        B(/* args */);
        void    print();
        ~B();
};



#endif