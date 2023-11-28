/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:24:29 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:24:29 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// #include<iostream>

Base *generate(void)
{
    int r;
    /*uses a seed to generate the series
    initialized to some distinctive value using function srand */
    // std::cout<<"first no: "<<rand()%3<<std::endl;
    srand(static_cast<unsigned>(time(NULL)));
    r = rand() % 3;
    if (r == 0)
    {
        return new A();
    }
    else if (r == 1)
    {
        return new B();
    }
    else if (r == 2)
        return new C();
    else
    {
        std::cout<<"gererate null"<<std::endl;
        return NULL;
    }

}

void identify(Base* p)
{
    std::cout<< "dynamic cast as a pointers"<<std::endl;
    if(dynamic_cast<A*> (p))
        std::cout<<"class A "<<std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout<<"class B"<<std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout<<"class C"<<std::endl;
    else
        std::cout<<"cast failed "<<std::endl;
}

/* dynamic_cast with reference does not demonstrate good programming 
style because it uses exceptions to control 
execution flow. Using dynamic_cast with pointers is betterway*/


void identify(Base& p)
{
    std::cout<< "dynamic cast as a reference"<<std::endl;
    try
    {
        p = dynamic_cast<A&>(p);
        std::cout<< "class A"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p = dynamic_cast<B&>(p);
        std::cout<< "class B"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p = dynamic_cast<C&>(p);
        std::cout<< "class C"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    Base *b = generate();
    std::cout <<"b "<< b <<std::endl;
    identify(*b);
    identify(b);
    
    Base    *c = generate();
    identify(c);
    identify(*c);

    
    return 0;

}