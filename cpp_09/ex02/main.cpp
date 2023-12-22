
#include <iostream>
#include <vector>
#include<list>
void insertionSort(std::vector<int>& vec, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int key = vec[i];
        int j = i - 1;

        while (j >= start && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}



// int main()
// {
 
//     std::list<int> myList = {5, 2, 9, 1, 5, 6};
//     int arr[] = {5, 2, 9, 1, 5, 6};
//     size_t arrSize = sizeof(arr) / sizeof(arr[0]);

//     // Initialize vector using iterators
//     std::vector<int> myVector(arr, arr + arrSize);
    
//     std::cout << "Original Vector: ";
//     for (size_t i = 0; i < myVector.size(); i++)
//     {
//         std::cout << i << " "<<std::endl;
//     }

//     int start = 0;
//     int end = myVector.size() - 1;

//     insertionSort(myVector, start, end);

//     std::cout << "Sorted Vector: ";
//     for (size_t i = 0; i < myVector.size(); i++)
//     {
//         std::cout << i << " "<<std::endl;
//     }

//     return 0;
// }
