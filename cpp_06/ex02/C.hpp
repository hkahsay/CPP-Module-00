/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:24:26 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:24:26 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

#include "Base.hpp"
#include <iostream>

class C : public Base
{
    private:
    /* data */
    public:
        C(/* args */);
        void    print();
        ~C();
};



#endif