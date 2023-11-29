/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:23:42 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:23:42 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main() {
    // Create an instance of the Data struct
    Serializer::Data myData;
    myData.new_ptr = "Hello, World!";
    myData.iValue = 42;
    myData.fValue = 3.14f;
    myData.dValue = 2.71828;

    // Serialize the Data struct
    uintptr_t serializedData = Serializer::Serialize(&myData);
    /*std::cout << "Serialized Values:" << std::endl;
    std::cout << "new_ptr: " << reinterpret_cast<uintptr_t>(&myData.new_ptr) << std::endl;
    std::cout << "iValue: " << reinterpret_cast<uintptr_t>(&myData.iValue) << std::endl;
    std::cout << "fValue: " << reinterpret_cast<uintptr_t>(&myData.fValue) << std::endl;
    std::cout << "dValue: " << reinterpret_cast<uintptr_t>(&myData.dValue) << std::endl;*/

    // Deserialize the serialized data
    Serializer::Data* deserializedData = Serializer::deserialize(serializedData);

    // Check the deserialized values
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "new_ptr: "<< deserializedData->new_ptr << std::endl;
    std::cout << "iValue: " << deserializedData->iValue << std::endl;
    std::cout << "fValue: " << deserializedData->fValue << std::endl;
    std::cout << "dValue: " << deserializedData->dValue << std::endl;


    return 0;
}
