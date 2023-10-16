#include <stdio.h>
#include <stdlib.h>

// Compile this file with: gcc -o person person.c

// In C++, this would be a class.
typedef struct {
    char *name;
    int birth_year;
} Person;

// In C++, this function would be a method of the Person class.
int age(Person *person) {
    return 2023 - person->birth_year;
}

/* WROOONG
Person* create_john_wrong() {
   Person john;
   john.birth_year = 2010;
   john.name = "John";
   return &john; // not valid because john will not exist after the function returns
/
*/

Person* create_john() {
   Person* john = malloc(sizeof(Person)); // john is allocated on the heap
   john->birth_year = 2010;
   john->name = "John";
   return john; // valid because john is allocated on the heap. We should not forget to free it later.
}

int main() {
   Person ada; // ada is allocated on the stack
   ada.birth_year = 1990;
   ada.name = "Ada";
   printf("%s is %d years old\n", ada.name, age(&ada));

   Person* john = create_john();
   printf("%s is %d years old\n", john->name, age(john));
   free(john); // we should not forget to free john, otherwise we will have a memory leak
   return 0;
}