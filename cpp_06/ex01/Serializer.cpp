/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:23:48 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:23:48 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer:: Serializer()
{
    std::cout<< "Default constructor is created"<<std::endl;
}

Serializer:: ~Serializer()
{
    
}

Serializer:: Serializer(Serializer const & src)
{
    *this = src;
}

Serializer & Serializer:: operator= (Serializer const &rhs)
{
    (void)rhs;
    return (*this);
}

uintptr_t   Serializer:: Serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Serializer:: Data*  Serializer:: deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Serializer::Data*>(raw));
}
