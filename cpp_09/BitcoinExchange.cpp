#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}

void	BitcoinExchange::printDataMap()const
{
	std::map<std::string, float>::const_iterator it;
	std::map<std::string, float>::const_iterator ite = data_map.end();
	for (it = data_map.begin(); it != ite; it++)
	{
		std::cout << "Date: " << it->first << ", Rate: " << it->second << std::endl;
	}

}


BitcoinExchange::BitcoinExchange(const std::string data, const std::string inputFile)
{
	// (void)inputFile;
	std::ifstream database(data);
	if (!database.is_open())
	{
		std::cout<<"Error: unable to open the file"<<std::endl;
		return;
	}
	std::string	dataline;
	getline(database, dataline);//this is to ignore header
	while(getline(database, dataline))
	{
			// std::cout<<"dataline: "<<dataline<<std::endl;

			// std::string date(dataline, 0, 10);
			std::string date;
			float rate;
			std::istringstream strm(dataline); //(dataline.substr(11, dataline.size() - 1)) >> rate;
		if (getline(strm, date, ',') && strm >> rate)
		{
			std::cout<<std::fixed<<std::setprecision(2);
			data_map[date] = rate;
			// std::cout<<"date: "<<date<<std::endl;
			// // std::cout<<"rate: "<<rate<<std::endl;

		}
	}
	// printDataMap();
	
	parseinput(inputFile);
	database.close();
}
                           
// void BitcoinExchange::parseinput(const std::string input)
// {
// 	std::ifstream inputFile(input);
// 	if(inputFile.is_open())
// 	{
// 		std::string expectedFormat = "date | value";
// 		std::string inputline;
// 		if (getline(inputFile, inputline) && inputline.compare(0, expectedFormat.length(), expectedFormat) == 0)
// 		{
// 			std::string inputDate;
// 			std::string value;
// 			double	result;
//             size_t valueStart = value.find_first_not_of(" \t");
//             size_t valueEnd = value.find_last_not_of(" \t");
// 			while (getline(inputFile, inputline))
// 			{
// 				inputDate = inputline.substr(0, 10);
// 				if(inputline.length() >= 11)
// 				{
// 					size_t pos = inputline.find('|');
// 					value = inputline.substr(pos + 1);

// 					// if (pos != std::string::npos)
// 					// {
// 						value = inputline.substr(valueStart, valueEnd - valueStart + 1);
// 						std::cout<<"inputDate: "<<inputDate<<" value: "<<value<<std::endl;
// 						// try
// 						// {
// 							result = std::stod(value);
// 							std::cout << "inputDate: " << inputDate << " value: " << value << std::endl;
// 							std::cout << "result: " << result << std::endl;
// 						// }
// 						// catch (const std::invalid_argument& e)
// 						// {
// 						// 	std::cerr << "Error: Invalid argument in converting value: " << e.what() << std::endl;
// 						// }
// 						// catch (const std::out_of_range& e)
// 						// {
// 						// 	std::cerr << "Error: Out of range in converting value: " << e.what() << std::endl;
// 						// }
// 					// }
// 				}
// 			}
// 		}
// 		else
//             std::cerr << "Error: The first line does not match the expected format." << std::endl;
// 	}
// 	else
// 		std::cerr<<"Error: Unable to open fileee"<<std::endl;
// 	inputFile.close();
// }

BitcoinExchange::~BitcoinExchange()
{
}

// bool	BitcoinExchange::check_input(std::string inputstrm)
// {
// 	if(inputstrm)
// 	{
// 		return true;
// 	}
// 	else
// 		return false;

// }

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