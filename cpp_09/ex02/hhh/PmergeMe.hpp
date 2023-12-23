#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include<list>
#include<sstream>


class PmergeMe
{
    private:
    std::vector<int>    _myvec;
        
    public:
        PmergeMe(std::string input);
        PmergeMe();
        ~PmergeMe();
        bool isDigit(const std::string& strInt);
        bool createVector(std::string input);
        int binarySearch(std::vector<int> input, int search);
        std::string to_string(std::vector<int> input);
        std::vector<int> sort(std::vector<int> input);
        void printVector(const std::vector<int>& vec);
        
};


        


#endif