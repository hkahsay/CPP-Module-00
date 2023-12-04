#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include<list>
#include<iostream>
template<typename T>
void    easyfind(T  *intlis, int tofind)
{
    std::list<int>  list1;
    // std::list<int>::const_iterator  it = list1.begin();
    // std::list<int>::const_iterator  ite = list1.end();

    list1.push_front(12);
    list1.push_front(2);
    list1.push_front(122);

    // for (size_t i = it; i < ite; i++)
    // {
        if (intlis != 0 && tofind == intlis.find())
        {
            std::cout<<tofind<<std::endl;
        }
        else
            std::cout<<"not find"<<std::endl;
        
    // }
    
}

#endif