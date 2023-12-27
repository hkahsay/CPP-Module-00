#include"PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}
std::vector<int> & PmergeMe:: getVector()
{
    return this->_myvec;
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


int  PmergeMe::binarySearch(std::vector<int> input, int search)
{
    size_t  lower = 0;
    size_t  higher = input.size();
    while (lower < higher)
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
// the index of the second element in the pair.sorttttttttt*/

std::vector<int> PmergeMe::sort_vector(std::vector<int> input)
{
    if (input.size() <= 1)
    {
        //  std::cerr << "Invalid input: a vector has only one element." << std::endl;
        //  exit(EXIT_FAILURE);
         return input;
    }

    // if (input.size() == 1) return input;
    std::vector<int> smalls;//main-chain
    std::vector<int> bigs;
    /*find each pair elements*/
    for (size_t i = 0; i < input.size() / 2; i++)
    {
        int elm1 = input[i * 2];
        int elm2 = input[(i * 2) + 1];

        //we sort and store separatly in smalls and bigs
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
 
    std::vector<int> main_chain = sort_vector(smalls);
    std::vector<int> bigs_sorted = sort_vector(bigs);

    size_t index = 0;
    for (size_t i = 0; i < bigs_sorted.size(); ++i) {
        int el = bigs_sorted[i];
        while (index < main_chain.size() && el > main_chain[index]) {
            index++;
        }
        main_chain.insert(std::next(main_chain.begin(), index), el);
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

//----------------for List container------------------


std::list<int> & PmergeMe:: getList()
{
    return this->_myList;
}

std::list<int> PmergeMe:: sort_list(std::list<int> input)
{
    if (input.size() <= 1)
    {
        //  std::cerr << "Invalid input: a vector has only one element." << std::endl;
        //  exit(EXIT_FAILURE);
        return input;
    }
    // we create pairs for each elements
    std::list<int> smalls;
    std::list<int> bigs;

     // Use iterators to traverse the list
    std::list<int>::const_iterator it = input.begin();
    // std::list<int>::const_iterator end = input.end();

    for (size_t i = 0; i < input.size() / 2; i++)
    {
        int elm1 = *it;
        std::advance(it, 1);
        int elm2 = *it;
        std::advance(it, 1);
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

   if (input.size() % 2 != 0) 
   {
    std::list<int>::iterator last_it = input.end();
    --last_it;
    int last_elm = *last_it;
    bigs.push_back(last_elm);
    }

    // Sort the lists recursively
    std::list<int> main_chain = sort_list(smalls);
    std::list<int> bigs_sorted = sort_list(bigs);

    std::list<int>::iterator main_it = main_chain.begin();
    std::list<int>::iterator bigs_it = bigs_sorted.begin();

    while (bigs_it != bigs_sorted.end()) {
        int el = *bigs_it;

        // Find the index _before_ which we should insert el into 'smalls'.
        while (main_it != main_chain.end() && el > *main_it) {
            ++main_it;
        }

        main_chain.insert(main_it, el);

        // Move to the next element in bigs_sorted
        ++bigs_it;
    }
    return main_chain;
}
