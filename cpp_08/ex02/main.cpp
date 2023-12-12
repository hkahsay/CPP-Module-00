#include"MutantStack.hpp"

int main()
{
    {
        std::cout << "------------test with MutankStack------------"<<std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        std::cout <<"Orginal stack: "<< mstack.size() << std::endl;
        std::cout <<"The size of copied stack should be the same: "<< s.size() << std::endl;
    }
    // std::cout<<std::endl;
    {
        std::cout << "------------test with std::list------------"<<std::endl;

        std::list<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
        std::cout <<"Orginal stack: "<< mstack.size() << std::endl;
        std::cout <<"The size of copied stack should be the same: "<< s.size() << std::endl;
    }
    std::cout << "------------string type elementes of stack------------"<<std::endl;
    MutantStack<std::string>mystack;
    mystack.push("hello");
    mystack.push("world");
    mystack.push("thank you");
    mystack.push("2023");
    mystack.push("waiting new year");
    mystack.push("and new thing");
    mystack.push("merry christmas!");
    mystack.push("Happy new year");
    for (MutantStack<std::string>::iterator ite = mystack.begin(); ite != mystack.end(); ite++)
    {
        std::cout<<*ite<<std::endl;
    }
    std::cout <<"The last element in the stack is: "<< mystack.top() << std::endl;
    std::cout<<"size of the stack: "<<mystack.size()<<std::endl;
    mystack.push("2024");
    std::cout<<"top value before poped: "<<mystack.top()<<std::endl;

    mystack.pop();
    std::cout<<"top value after poped: "<<mystack.top()<<std::endl;

    return 0;
}