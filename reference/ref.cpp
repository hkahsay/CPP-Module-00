#include<iostream>

int increment(int& num) {
    std::cout << "add of num "<< &num << std::endl;  // Output: 6
    return num++;
}

int main() {
    int value = 5;
    // increment(value);
    std::cout  << "add of value "<< &value << std::endl;  // Output: 6
    std::cout << increment(value) << std::endl;  // Output: 6

    return 0;
}