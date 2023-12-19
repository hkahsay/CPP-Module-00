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
	if(this != &rhs)
		this->data_map = rhs.data_map;
	return (*this);

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
			if(rate)
			// std::cout<<std::fixed<<std::setprecision(2);
			data_map[date] = rate;
			// std::cout<<"date: "<<date<<std::endl;
			// std::cout<<"rate: "<<rate<<std::endl;

		}
	}
	// printDataMap();
	
	parseinput(inputFile);
	database.close();
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
                           
int	BitcoinExchange:: checkValue(std::string & value)
{
	for (size_t i = 0; i < value.length(); i++)
	{
		if(!isdigit(value[i])&& value[i] != '.' && value[i] != '-')
			return 0;
	}
	return 1;
		
}

float	BitcoinExchange::checkupperBound(const std::string & inputDate)const
{
	std::map<std::string, float>::const_iterator	upperBoundter;
	upperBoundter = data_map.upper_bound(inputDate);

	if (upperBoundter == data_map.begin())
		return upperBoundter->second;
	else
	{
		--upperBoundter;
		return upperBoundter->second;
	}
}

void	BitcoinExchange:: parseinput(const std::string input)
{
	std::ifstream	inputFile(input);
	if (inputFile.is_open())
	{
		std::string	expectedFormat = "date | value";
		std::string inputLine;
		if (getline(inputFile, inputLine) && inputLine.compare(0, expectedFormat.length(), expectedFormat) == 0)
		{
			while (getline(inputFile, inputLine))
			{
				std::string inputDate = inputLine.substr(0, 10);
				std::string	value;
				double	result;
				if (inputLine.length() >= 11)
				{
					 // Find the position of the '|' character
					 size_t	pos = inputLine.find('|');
					if (pos != std::string::npos)
					{
						// Extract the value part, skipping whitespaces and the '|' character
						value = inputLine.substr(pos + 1);
						size_t valueStart = value.find_first_not_of(" \t");
						size_t	valueEnd = value.find_last_not_of(" \t");
						if (valueStart != std::string::npos && valueEnd != std::string:: npos)
						{
							value = value.substr(valueStart, valueEnd - valueStart + 1);
							if(checkValue(value))
							{
								 // Use std::istringstream for more robust conversion
                                std::istringstream valueStream(value);
                                valueStream >> result;
								if(!valueStream.fail() && result >= 0 && result <= 1000)
								{
									result = result * (checkupperBound(inputDate));
									std::cout<<"result: "<<result<<std::endl;
								
								}
								else
								{
									if(result < 0)
									{
										std::cout<<"Error: not a positive number."<<std::endl;
										continue;
									}
									if(result > 1000)
									{
										std::cout<<"Error: too large a number."<<std::endl;
										continue;
									}
								}
							}
						}
						else
							std::cerr<<"Error: invalid value formatin line: "<<inputLine<<std::endl;
					} 
					else
						std::cerr<<"Error: Separator | is not found"<<std::endl;
				}
				if(value.empty())
				{
					std::cout<<"Error: Error: bad input => "<<inputLine<<std::endl;
					continue;
				}
			}	
		}
		else
			std::cerr<<"Error: first line does not match the expected format"<<std::endl;
	}
	else
		std::cerr<<"Error: Unable to open the file"<<std::endl;
}
