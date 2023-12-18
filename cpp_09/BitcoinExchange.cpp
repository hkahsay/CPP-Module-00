#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::BitcoinExchange(const std::string data, const std::string inputFile)
{
	// (void)inputFile;
	std::ifstream database(data);
	if (!database.is_open())
		std::cout<<"Error: unable to open the file"<<std::endl;
	
	std::string	dataline;
	getline(database, dataline);//this is to ignore header
	while(getline(database, dataline))
	{
			std::cout<<"dataline: "<<dataline<<std::endl;
			std::istringstream strm(dataline);
			std::string date;
			std::string rate_int_part;
			std::string rate_decimal_part;
		if (getline(strm, date, ',') && getline(strm, rate_int_part, '.') && strm >> rate_decimal_part)
		{
				std::cout<<"date: "<<date<<std::endl;
				std::cout<<"rate_int_part: "<<rate_int_part<<std::endl;
				std::cout<<"rate_decimal_part: "<<rate_decimal_part<<std::endl;
				int rate_value = std::stoi(rate_int_part) * 100 + std::stoi(rate_decimal_part);
				std::cout<<"rate_value: "<<rate_value<<std::endl;
				std::cout<<(rate_value/100)<<"."<<(rate_value%100)<<std::endl;

				data_map[date] = rate_value;

		}
	}
	
	parseinput(inputFile);
	database.close();
}

void BitcoinExchange::parseinput(const std::string input)
{
	std::ifstream inputFile(input);
		bool isopen = inputFile.is_open();
		std::string inputline;
        if(isopen)
        {
			while (getline(inputFile, inputline))
			{

				// int len = inputline.length();
				// std::stringstream strm(inputline);
				// std::cout<<inputline<<std::endl;
				//std::string date = inputline.substr(0, 10);
				//std::string spacebtween = inputline.substr(11, 12);
				//std::string value = inputline.substr(13, inputline.length());
				// std::cout<<"len: "<<len<<std::endl;
				// if (getline(inputFile,strm))
				// {

				// }
			}
        }
        else
            std::cerr<<"Error: Unable to open file"<<std::endl;
        inputFile.close();

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
	if(this != &rhs)
		this->data_map = rhs.data_map;
	return (*this);

}