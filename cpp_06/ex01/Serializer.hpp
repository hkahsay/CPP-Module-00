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
// #include<cstdint>

struct Data
{
    std::string new_ptr;
};

uintptr_t  Serialize(Data *ptr);
Data* deserialize(uintptr_t raw);

#endif