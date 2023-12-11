#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


class MutantStack 
{
    private:
    std::stack<int> _myStack;
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(MutantStack const & src);
        MutantStack& operator= (MutantStack const & rhs);
        class iterator
        {
            private:
                std::stack<int>::iterator   begin;
                std::stack<int>::iterator   end;
            public:
                iterator(/* args */);
                ~iterator();
        };
        
};

#endif
