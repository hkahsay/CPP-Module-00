#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange& BitcoinExchange:: operator=(BitcoinExchange const & rhs)
{
	this->data = rhs.data;
	return (*this);

}