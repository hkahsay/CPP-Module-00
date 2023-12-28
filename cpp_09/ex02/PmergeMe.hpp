#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include<list>
#include<sstream>
#include<algorithm>
#include<cstdlib>


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
        int binarySearch(std::vector<int> input, int search);
        std::vector<int> sort_vector(std::vector<int> input);
        void printVector(const std::vector<int>& vec);
        std::vector<int> &getVector();
   

        std::list<int> sort_list(std::list<int> input);
        std::list<int> &getList();
        
        template <typename T>
        void fillContainer(T& container, const std::string& input) {
            size_t start = 0;
            size_t end = input.find(' ');
            while (end != std::string::npos) {
                std::string token = input.substr(start, end - start);
                if (!token.empty()) {
                    if (!PmergeMe::isDigit(token)) 
                    {
                        std::cout << "Invalid input: " << token << " is not a digit." << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    
                    // Check for a positive integer before converting
                    if (token[0] == '-' || token[0] == '+' || std::stoi(token) <= 0) {
                        std::cout << "Usage: " << " ' "<< token << " ' "<< " positive integer sequence as argument." << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    int num = std::stoi(token);                   
                    container.push_back(num);
                    
                }
                start = end + 1;
                end = input.find(' ', start);
            }

            // Handle the last token
            std::string lastToken = input.substr(start);
            if (!lastToken.empty()) {
                if (!PmergeMe::isDigit(lastToken)) {
                    std::cerr << "Usage: "<< " ' " << lastToken << " ' " << " positive integer sequence as argument." << std::endl;
                    // exit();
                    exit(EXIT_FAILURE);
                }
                else
                {
                     // Check for a positive integer before converting
                    if ((lastToken[0] == '-' && lastToken.size() > 1) ||
                        (lastToken[0] == '+' && lastToken.size() > 1) ||
                        (lastToken[0] != '-' && lastToken[0] != '+' && std::stoi(lastToken) <= 0)) {
                        std::cout << "Usage: " << " ' "<< lastToken << " ' "<< "  positive integer sequence as argument" << std::endl;
                        exit(EXIT_FAILURE);
                    }

                    int num = std::stoi(lastToken);
                    container.push_back(num);
                }
            }
        }
        template<typename Container>
        std::string to_string(const Container& container)const
        {
            std::string result;
            typename Container::const_iterator it;
            for(it = container.begin(); it != container.end();it++)
            {
                if(it != container.begin())
                    result += ", ";
                std::stringstream ss;
                ss << *it;
                result += ss.str();
            }
            return result;
        }

};



#endif