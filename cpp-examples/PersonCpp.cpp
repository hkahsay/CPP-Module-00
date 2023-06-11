#include <iostream>
#include <string>

// Compile this file with: g++ -o person_cpp person_cpp.cpp

// In C++, we define a class instead of a struct.
class Person {
public:
    std::string name; // We use string instead of char* for the person's name.
    int birth_year;

    // In C++, we define age as a method of the class Person.
    // A method is a function that is associated with a class.
    int age() {
        return 2023 - birth_year;
    }
};

Person* create_john() {
    Person* john = new Person(); // john is allocated on the heap using the 'new' keyword
    john->birth_year = 2010;
    john->name = "John";
    return john; // valid because john is allocated on the heap.
    // We should not forget to delete it later.
}


/*
Main C++ concepts used in this example:
1. Streams: In C++, streams are used for input and output operations. The
   "std::cout" object is a standard output stream that is used for printing text
   to the console. It is used with the insertion operator (<<) to output data.
2. Class: In C++, a class is a blueprint for creating objects that encapsulate
   data and related functionality. It provides a way to define the structure and
   behavior of objects. In the example, the "Person" class is defined with
   member variables (name and birth_year) and a member function (age).
3. Method: In C++, a method is a member function of a class that operates on
   objects of that class. It defines the behavior or actions that objects of the
   class can perform. In the example, the "age" function is a method of the
   "Person" class that calculates the age based on the birth year.
4. Dynamic Memory Allocation: C++ provides the "new" keyword to allocate memory
   dynamically on the heap. In the example, the "new" keyword is used to
   allocate memory for the "john" object of the "Person" class.
5. Deallocation: In C++, the "delete" keyword is used to deallocate memory that
   was allocated using "new". It ensures that the allocated memory is freed and
   can be reused. In the example, the "delete" keyword is used to deallocate the
   memory for the "john" object.
*/

int main() {
    Person ada; // ada is allocated on the stack
    ada.birth_year = 1990;
    ada.name = "Ada";
    std::cout << ada.name << " is " << ada.age() << " years old" << std::endl;

    Person* john = create_john();
    std::cout << john->name << " is " << john->age() << " years old" << std::endl;
    delete john; // we need to explicitly delete the object allocated with 'new'
    return 0;
}