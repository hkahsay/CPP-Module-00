#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include<array>
#include<vector>
#include<list>
#include<iostream>
# include <algorithm>
# include <iterator>
// #include <algorithm>
/*
template < class T, class Alloc = allocator<T> > class list;
List containers are implemented as doubly-linked lists;
find value in range Returns an iterator to the first element
 in the range [first,last) that compares equal to val.
 If no such element is found, the function returns last.
 
 // using std::find with vector and iterator:
  std::vector<int> myvector (myints,myints+4);
  std::vector<int>::iterator it;

  it = find (myvector.begin(), myvector.end(), 30);
  if (it != myvector.end())
    std::cout << "Element found in myvector: " << *it << '\n';
  else
    std::cout << "Element not found in myvector\n";
}*/
template<typename T>
bool easyfind(T  & containerList, int  const & tofind)
{
    typename T :: const_iterator  it;
    it = std::find(containerList.begin(), containerList.end(), tofind);
    if (it == containerList.end())
        return false;
    else
        return true;
    
}

#endif


