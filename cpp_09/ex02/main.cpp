
#include <iostream>
#include <vector>
#include<list>
#include"PmergeMe.hpp"


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <list of integers>" << std::endl;
        exit(EXIT_SUCCESS);
    }
    PmergeMe pm;
    std::string inputStr;

    for (int i = 1; i < argc; ++i) {
        inputStr = argv[i];
        //fill my input to its corrsponding container
        pm.fillContainer(pm.getVector(), inputStr);
        pm.fillContainer(pm.getList(), inputStr);

    }

    std::cout << "Before sorting vector: " << pm.to_string(pm.getVector()) << std::endl;
    std::cout << "Before sorting list: " << pm.to_string(pm.getList()) << std::endl;

     // Call the sort function and get the sorted vector
    std::vector<int> sortedVec = pm.sort_vector(pm.getVector());
    std::list<int> sortedlist= pm.sort_list(pm.getList());


    // Print the sorted vector
    std::cout << "After sorting vector: " << pm.to_string(sortedVec) << std::endl;
    std::cout << "After sorting list: " << pm.to_string(sortedlist) << std::endl;

    return 0;
}

//./PmergeMe $(awk 'BEGIN { srand(); for(i=1;i<=3000;i++) print int(rand()*100000) }' | tr '\n' ' ')
