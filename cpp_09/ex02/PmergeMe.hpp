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
    std::list<int>    _myList;

        
    public:
        PmergeMe(std::string input);
        PmergeMe();
        ~PmergeMe();
        bool isDigit(std::string& strInt);
        bool createVector(int num);
        int binarySearch(std::vector<int> input, int search);
        std::string to_string();
        std::string to_string2(std::vector<int> input);

        std::vector<int> sort(std::vector<int> input);
        void printVector(const std::vector<int>& vec);
        std::vector<int> getVector();
        std::list<int> getList();

        
};

template <typename T>
void fillContainer(T& container, const std::string& input) {
    size_t start = 0;
    size_t end = input.find(' ');

    while (end != std::string::npos) {
        std::string token = input.substr(start, end - start);
        if (!token.empty()) {
            if (!container.isDigit(token)) {
                std::cout << "Invalid input: " << token << " is not a digit." << std::endl;
                return;
            }
            int num = std::stoi(token);
            container.createVector(num);
        }

        start = end + 1;
        end = input.find(' ', start);
    }

    // Handle the last token
    std::string lastToken = input.substr(start);
    if (!lastToken.empty()) {
        if (!container.isDigit(lastToken)) {
            std::cout << "Invalid input: " << lastToken << " is not a digit." << std::endl;
            return;
        }
        int num = std::stoi(lastToken);
        container.createVector(num);
    }
}

#endif