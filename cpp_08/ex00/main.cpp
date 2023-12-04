#include"easyfind.hpp"
/*i use vector container becaouse

to create list // int t[] = {1,5,6,4};
    int tofind = 65;
    std::list<int>  list1 (t, t + 4) 4 is the size of the list;
    to create array container
    std::array<int, 4>  list1 ={1,5,6,4}; */
int main()
{
    int tofind = 65;
    std::cout<<" --------array container----------- "<<std::endl;
    std::cout<<std::endl;


    std::array<int, 4>  arr ={1,5,6,4};
    if(easyfind(arr, tofind))
        std::cout<<" tofind: "<<tofind<<std::endl;
    else
        std::cout<<" not find: "<<tofind<< " is not in the list"<<std::endl;
    std::cout<<std::endl;

    std::cout<<" --------list container----------- "<<std::endl;
    std::cout<<std::endl;

    std::list<int> list1;
  
    for (size_t i = 0; i < 20; i++)
    {
        list1.push_back(i * 2);

    }
    std::list<int>::const_iterator  it;
    for ( it = list1.begin(); it != list1.end(); ++it)
    {
       std::cout<<*it<< " " ;
    }
    std::cout<<std::endl;
    
    std::cout<< std::boolalpha <<" 10: "<< easyfind(list1, 10)<<std::endl;
    std::cout<< std::boolalpha <<" 15 "<< easyfind(list1, 15)<<std::endl;
    std::cout<< std::boolalpha <<" 23 "<< easyfind(list1, 23)<<std::endl;
    std::cout<< std::boolalpha <<" 26 "<< easyfind(list1, 26)<<std::endl;
    std::cout<< std::boolalpha <<" 40 "<< easyfind(list1, 40)<<std::endl;
    std::cout<< std::boolalpha <<" 36 "<< easyfind(list1, 36)<<std::endl;

    std::cout<<" --------vector container----------- "<<std::endl;
    std::cout<<std::endl;


    std::vector<int>    v1;
    for (size_t i = 0; i < 20; i++)
    {
        v1.push_back(i * 2);

    }
    std::vector<int>::const_iterator  vit;
    for ( vit = v1.begin(); vit != v1.end(); ++vit)
    {
       std::cout<<*vit<< " " ;
    }
    std::cout<<std::endl;

    std::cout<< std::boolalpha <<" 10: "<< easyfind(v1, 10)<<std::endl;
    std::cout<< std::boolalpha <<" 15 "<< easyfind(v1, 15)<<std::endl;
    std::cout<< std::boolalpha <<" 23 "<< easyfind(v1, 23)<<std::endl;
    std::cout<< std::boolalpha <<" 26 "<< easyfind(v1, 26)<<std::endl;
    std::cout<< std::boolalpha <<" 40 "<< easyfind(v1, 40)<<std::endl;
    std::cout<< std::boolalpha <<" 36 "<< easyfind(v1, 36)<<std::endl;

    return 0; 
}

