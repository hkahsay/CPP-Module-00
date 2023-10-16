#include <iostream>
#include <string>
#include <locale>
#include <cassert>

// Next things to learn about C++:
// 1. Namespaces: namespaces are used to group related classes, functions, and
//    variables. They help avoid name collisions. In the example, the "std"
//    namespace is used to access the "cout" and "endl" objects.
// 2. Header filers: header files contain the declarations of functions and
//    classes.
// 3. Standard library: the C++ standard library provides a set of common
//    functions and classes that can be used in C++ programs. In the example, we
//    used the "std::string" class from the standard library to represent a
//    string. The standard library contains many other useful classes and
//    functions. For example, the "std::vector" class can be used to represent a
//    dynamic array.
// 4. Templates: templates are used to write generic code that can be used with
//    different types.

int main(int argc, char* argv[]) {
    assert(argc == 2); // Ensures exactly one argument is provided

    std::string argument = argv[1];
    
    // A locale is an object that encapsulates cultural differences in language,
    // collation, and other conventions. We use the default locale.
    std::locale loc;

    // Capitalize the string using std::use_facet<std::ctype<char>>(loc).toupper:
    //std::use_facet<std::ctype<char> >(loc).toupper(&argument[0], &argument[0] + argument.size());

    // Using range-based for loop from C++11:
    //for (char& c : argument) {
    //    c = std::toupper(c, loc);
    //}

    // Using traditional for loop:
    for (unsigned long i = 0; i < argument.size(); ++i) {
        // We use std::toupper from <locale> to capitalize the string. This
        // function takes a character and a locale as arguments.
        argument[i] = std::toupper(argument[i], loc);
    }

    std::cout << argument << std::endl;
    return 0;
}