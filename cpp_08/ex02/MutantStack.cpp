#include "MutantStack.hpp"

MutantStack:: MutantStack(): _myStack(0)
{
    return ;
}

MutantStack:: ~MutantStack()
{
    return ;
}

MutantStack::MutantStack(MutantStack const & src):_myStack(_myStack.src)
{

}

MutantStack& MutantStack:: operator=(MutantStack const & rhs)
{
    
}

MutantStack:: myIterator:: myIterator(int begin, int end): _begin(begin), _end(end)
{

}

bool    MutantStack:: myIterator::operator==(const myIterator & rhs)const{
    return 
}