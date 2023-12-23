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
        bool isDigit(std::string& strInt);
        bool createVector(std::vector<int> inputVec);
        int binarySearch(std::vector<int> input, int search);
        std::string to_string(std::vector<int> input);
        std::vector<int> sort(std::vector<int> input);
        void printVector(const std::vector<int>& vec);
        
};

template<typename T>
void    fillContainter(int num, T &container, std::string input)
{
    if (!isDigit(*input))
    {
        std:: cout << "Usage: a positive integer sequence as argument" << std::endl;
        return;
	}
    num = std::stoi(input);
    container.push_back(num);
}
        


#endif