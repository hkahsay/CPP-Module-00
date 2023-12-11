#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<iostream>
#include<iterator>
class MutantStack 
{
    private:
    std::stack<int> _myStack;
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(MutantStack const & src);
        MutantStack& operator= (MutantStack const & rhs);
        class myIterator
        {
            private:
                std::stack<int>::myIterator   _begin;
                std::stack<int>::myIterator   _end;
            public:
                myIterator(/* args */);
                ~myIterator();
                myIterator(int begin, int end);
                myIterator(const myIterator & src);
                myIterator & operator= (const myIterator & rhs);
                bool    operator ==(const myIterator & rhs)const;

        };
        
};

#endif
