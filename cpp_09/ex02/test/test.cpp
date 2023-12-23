#include <iostream>
#include <vector>


// Return the index before which to insert n
int linear_search(std::vector<int> input, int n) {
    for(size_t i = 0; i < input.size(); ++i) {
        if(n < input[i]) return i;
    }
    return input.size();
}

int binary_search(std::vector<int> input, int n) {
    size_t lower = 0;
    size_t upper = input.size();
    while(lower + 1 < upper) {
        size_t middle = (lower + upper) / 2;
        //std::cout << "lower: " << lower << std::endl;
        //std::cout << "upper: " << upper << std::endl;
        //std::cout << "middle: " << middle << std::endl;
        if(n < input[middle]) {
            upper = middle;
        } else {
            lower = middle;
        }
    }
    return upper;
}

std::string to_string(std::vector<int> input) {
    std::string result = "";
    for (size_t i = 0; i < input.size(); ++i) {
        if (i > 0) {
            result += ", "; // Add a separator between numbers
        }
        result += std::to_string(input[i]); // Convert each integer to string and add it to the result
    }
    return result;
}


std::vector<int> sort(std::vector<int> input) {
    if(input.size() == 1) return input;

    std::vector<int> smalls;
    std::vector<int> bigs;

    for(size_t i = 0; i < input.size() / 2; ++i) {
        int el1 = input[i * 2];
        int el2 = input[(i * 2) + 1];
        if(el1 < el2) {
            smalls.push_back(el1);
            bigs.push_back(el2);
        } else {
            smalls.push_back(el2);
            bigs.push_back(el1);
        }
    }

    if(input.size() % 2 == 1) {
        int last = input[input.size() - 1];
        bigs.push_back(last);
    }

    std::cout << "smalls: " << to_string(smalls) << std::endl;
    std::cout << "bigs: " << to_string(bigs) << std::endl;

    std::vector<int> main_chain = sort(smalls);
    std::vector<int> bigs_sorted = sort(bigs);

    // Wrong order?
    // We can minimize the cost by following an order
    // based on the Jacobsthal Numbers.
    for(size_t i = 0; i < bigs_sorted.size(); ++i) {
        int el = bigs_sorted[i];
        // Find the index _before_ which we should insert
        // el into main_chain.
        size_t pos = binary_search(main_chain, el);
        main_chain.insert(std::next(main_chain.begin(), pos), el);
    }

    return main_chain;
}

// int main(int argc, char** argv) {
    /*  
    int arr[] = {0,1,2,4,7,9};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);
    // std::vector<int> example = {0,1,2,4,7,9};

    // Initialize vector using iterators
    std::vector<int> example(arr, arr + arrSize);
    //                          0,1,2,3,4
    std::cout << binary_search(example, 5) << std::endl;
    std::cout << binary_search(example, 1) << std::endl;

    return 0;
    */

//     std::vector<int> input;
//     int c = 1;
//     while(c < argc) {
//         input.push_back(std::stoi(argv[c]));
//         ++c;
//     }

//     std::cout << "Before sorting: " << to_string(input) << std::endl;
//     std::vector<int> sorted = sort(input);
//     std::cout << "After sorting: " << to_string(sorted) << std::endl;

//     return 0;
// }