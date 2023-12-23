#include"PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe:: PmergeMe(std::string input)
{
    if(!createVector(input))
    {
        std::cout << "Invalid input. Exiting." << std::endl;
		return;
    }
   
    // std::cout<<"Before: ";
    // printVector(_myvec);
    // std::cout<<std::endl;
    // std::cout<<"After: ";
    // _myvec = sort(_myvec);
    // printVector( _myvec);
    // std::cout<<std::endl;


    // std::cout << "Before: ";

}

bool    PmergeMe:: isDigit(std::string & strInt)
{
    std::string::const_iterator   it;
    for ( it = strInt.begin(); it != strInt.end(); it++)
    {
       if(!std::isdigit(*it))
        return false;
    }
    return true;
    
}


bool PmergeMe::createVector(std::vector<int> inputVec)
{
   
	int num;



	if( _myvec.size() < 1 ) {

		std::cout << "List is empty" << std::endl;
		return false;
	}

	if( _myvec.size() == 1 ) {

		if( num == 0 ) {
			std::cout << "Usage: a positive integer sequence as argument" << std::endl;
			return false;
		}
	}
	return true;
}

std::string PmergeMe:: to_string(std::vector<int> input)
{
    std::string result;
    std::vector<int>::iterator  it;
    std::vector<int>::iterator  ite = input.end();

    for (it = input.begin(); it != ite; it++)
    {
        if (it != input.begin())
            result += ", ";
        result += std::to_string(*it);
    }
    return  result;
    
}

int  PmergeMe::binarySearch(std::vector<int> input, int search)
{
    size_t  lower = 0;
    size_t  higher = input.size();
    while (lower <= higher)
    {
        size_t  middle = lower + (higher - lower) / 2;
        if(input[middle] == search)
            return static_cast<int>(middle);
        if (input[middle] < search)
        {
            lower = middle + 1;
        }
        else
            higher = middle - 1; 
    }
    return -1;
}


/*The expression i * 2 is used to calculate the 
index of the first element in a pair, and (i * 2) + 1 
is used to calculate 
// the index of the second element in the pair.*/
std::vector<int> PmergeMe::sort(std::vector<int> input)
{
    if (input.size() == 1) return input;
    std::vector<int> smalls;//main-chain
    std::vector<int> bigs;
    /*find each pair elements*/
    for (size_t i = 0; i < input.size() / 2; i++)
    {
        int elm1 = input[i * 2];
        int elm2 = input[(i * 2) + 1];
        //we sort and store separatlyiin smalls and bigs
        if (elm1 > elm2)
        {
            bigs.push_back(elm1);
            smalls.push_back(elm2);
        }
        else
        {
            smalls.push_back(elm1);
            bigs.push_back(elm2);
        }
    }
    //if our input is odd we put the last unpaired in the bigs
    if (input.size()% 2 != 0)
    {
        int last_elm = input[input.size() - 1];
        bigs.push_back(last_elm);
    }
    /*till now we have sorted smalls and bigs element of pairs
    now lets sort bigs and smalls recursivly 
    and store each vector*/
    // Merge the sorted 'bigs' into the sorted 'smalls'.

    std::vector<int> main_chain = sort(smalls);
    std::vector<int> bigs_sorted = sort(bigs);

    for (size_t i = 0; i < bigs_sorted.size(); ++i) {
        int el = bigs_sorted[i];
        // Find the index _before_ which we should insert el into 'smalls'.
        size_t pos = binarySearch(main_chain, el);
        main_chain.insert(std::next(main_chain.begin(), pos), el);
    }
    return(main_chain);
}


void PmergeMe::printVector(const std::vector<int>& vec)
{
    std::vector<int>::const_iterator it;
    std::vector<int>::const_iterator ite = vec.end();

    for (it = vec.begin(); it != ite; it++) {
        std::cout << " "<< *it;
    }
    std::cout << std::endl;
}