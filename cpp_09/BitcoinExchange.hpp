#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <algorithm>
#include<cstdlib>
// #include<ifstream>
#include<map>

class BitcoinExchange
{
	private:
		std:: map<std:: string, float> data_map;
		// double values;
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string database, const std::string inpt);
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange& operator =(BitcoinExchange const & rhs);
		~BitcoinExchange();
		void parseinput(const std::string input);
		void	printDataMap()const;
		bool	check_input(std::string inputstrm);



};




#endif
