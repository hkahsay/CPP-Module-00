#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

class BitcoinExchange
{
	private:
		std:: map<std:: string, float> data;
		double values;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange& BitcoinExchange(BitcoinExchange const & rhs);
		~BitcoinExchange();
};




#endif
