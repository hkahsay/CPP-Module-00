/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:23:54 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:23:54 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include<string>
#include<stdint.h>

class Serializer 
{
    private:
        Serializer();
    public:
        ~Serializer();
        Serializer(Serializer const & src);
        Serializer & operator = (Serializer const & rhs);

    struct Data
    {
        std::string new_ptr;
        int iValue;
        float fValue;
        double dValue;
    };
    static Data* deserialize(uintptr_t raw);
    static uintptr_t  Serialize(Data *ptr);
};

#endif