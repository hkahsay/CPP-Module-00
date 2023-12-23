
#include <iostream>
#include <vector>
#include<list>
#include"PmergeMe.hpp"
// void insertionSort(std::vector<int>& vec, int start, int end) {
//     for (int i = start + 1; i <= end; ++i) {
//         int key = vec[i];
//         int j = i - 1;

//         while (j >= start && vec[j] > key) {
//             vec[j + 1] = vec[j];
//             --j;
//         }
//         vec[j + 1] = key;
//     }
// }


        // std::string printValues = m.to_string(input);
        // std::cout<<printValues<<std::endl;
        // int result = m.binarySearch(myVector, 9);
        // std::cout<<result<<std::endl;


int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <list of integers>" << std::endl;
        return 1;
    }
    std::vector<int> vec;
    // int num;
    std::string inputstr;
//     int c = 1;
//     while(c < argc) {
//         input.push_back(std::stoi(argv[c]));
//         ++c;
//     }

//     std::cout << "Before sorting: " << to_string(input) << std::endl;
//     std::vector<int> sorted = sort(input);
//     std::cout << "After sorting: " << to_string(sorted) << std::endl;

//     return 0;
    for (int i = 1; i < argc; ++i) {
        // num = std::atoi(argv[i]);
        inputstr = argv[i];
        // fillContainter(num, vec, inputstr);
        
        // PmergeMe m(input);
    }

    return 0;
}

    // int arr[] = {5, 2, 9, 1, 5, 6};
    // int arr[] = {2, 5, 6, 7, 9, 11, 15, 16};

    // size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    // // Initialize vector using iterators
    // std::vector<int> myVector(arr, arr + arrSize);

    
    // std::cout << "Original Vector: ";
    // for (size_t i = 0; i < myVector.size(); i++)
    // {
    //     std::cout << i << " "<<std::endl;
    // }

    // int start = 0;
    // int end = myVector.size() - 1;

    // insertionSort(myVector, start, end);

    // std::cout << "Sorted Vector: ";
    // for (size_t i = 0; i < myVector.size(); i++)
    // {
    //     std::cout << i << " "<<std::endl;
    // }


//     return 0;
// }
