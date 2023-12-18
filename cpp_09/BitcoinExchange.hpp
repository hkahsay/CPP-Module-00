#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <algorithm>
// #include<ifstream>
#include<map>

class BitcoinExchange
{
	private:
		std:: map<std:: string, int> data_map;
		// double values;
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string database, const std::string inpt);
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange& operator =(BitcoinExchange const & rhs);
		~BitcoinExchange();
		void parseinput(const std::string input);

};




#endif
