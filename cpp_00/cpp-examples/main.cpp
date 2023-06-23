#include "initializationList.hpp"

// int main() {
//     mySample('z', 32, 4.2f);
//     return(0);
// }
// const int MAX_VALUE = 100; // Declaring a constant variable

void printValue(const int value) {
    // The 'value' parameter cannot be modified within this function
    // Attempting to modify it would result in a compilation error
    std::cout << "Value: " << value << std::endl;
}

int main() {
    const int x = 5; // Declaring a constant variable
    mySample instance('z', 32, 4.2f);
    // return(0);
    // Attempting to modify 'x' will generate a compilation error
    // x = 10;
    instance.bar();
    printValue(x);

    return 0;
}
