#ifndef INITIALIZATIONLIST_HPP
#define INITIALIZATIONLIST_HPP
#include<iostream>

class mySample{
    public:
        char const a1;
        int a2;
        float a3;
        mySample(char p1, int p2, float p3);
        ~mySample(void);
        void    bar(void)const;

};
#endif
