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