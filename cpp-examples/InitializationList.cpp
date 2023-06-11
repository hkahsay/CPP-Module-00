#include "initializationList.hpp"
// #include<iostream>

using namespace std;
mySample:: mySample(char const p1, int p2, float p3): a1(p1), a2(p2), a3(p3) {
    cout<<"this->a1 " <<this->a1<<endl;
    cout<<"this->a2 " <<this->a2<<endl;
    cout<<"this->a3 " <<this->a3<<endl;
}

mySample:: ~mySample(void) {
    cout << "deconstructor" << endl;
}

void mySample:: bar(void) const {
    cout<<"bar is member function  of class mySample" <<endl;
    cout<<"this->a3 " <<this->a3<<endl;
    
}