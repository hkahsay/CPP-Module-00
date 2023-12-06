#include<iostream>
#include<string>
#include<array>
#include<vector>


/*now lets use one single print function for all different data type that is with STL*/
template<typename T>
void	print(T arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout<< arr[i]<<std::endl;
	}
}

template<typename T>
void	print(T arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout<< arr[i]<<std::endl;
	}
}
void	printCollection(std::string *arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout<< arr[i]<<std::endl;
	}

}
void	printCollection(std::array<std::string, 3> stdarr)
{
	/*is possible to use printfcoolection of array for all printcollection 
	overloads by simply changing the data type or to be compatible use .data() 
	this will help for not repeatinf for loop for the same usage*/
	printCollection(stdarr.data(), stdarr.size());
	
}
void	printCollection(std::vector<std::string> item)
{
	/*for (size_t i = 0; i < size; i++)
	{
		std::cout<< arr[i]<<std::endl;
	}
	or you can you printCollection()*/
	printCollection(item.data(), item.size());

}

// int	main()
// {
	/*printcollection array and this food1 are the same where as 
	std array and std vectors are different*/

	// std::string food1[3] = {"lemon", "carrot", "potatoes"};
	// std::array<std::string, 3> food2 = {"lemon", "carrot", "potatoes"};
	// std::vector<std::string> vic = {"her", "grape", "banana", "hannu"};


	// for (size_t i = 0; i < foods.size(); i++)
	// {
	// 	std::cout<< foods[i]<<std::endl;
	// }
	// std::cout<<"------------Array------------"<<std::endl;

	// printCollection(food1, sizeof(food1)/sizeof(food1[0]));
	// std::cout<<"------------STDArray------------"<<std::endl;
	// printCollection(food2);
	// print(food2, food2.size());
	// print(food2);


	// vic.push_back("hello");
	// vic.push_back("world");
	// std::cout<<"------------STDVector------------"<<std::endl;

	// printCollection(vic);
	// print(vic, vic.size());
	// print(vic);

	/*we can also use other print with out passing the size since STL can have also the size*/


	/*
	we can print in many ways below and above options
	for (std::array<std::string, 3>::const_iterator itr = food2.begin(); itr != food2.end(); itr++)
	{

		std::cout<< *itr<<std::endl;
	}
	for (std::vector<std::string>::const_iterator it = vic.begin(); it != vic.end(); it++)
	{
		// std::cout<<"the address of each it: "<< it<<std::endl;

		std::cout<<"the values of it: "<< *it<<std::endl;
	}
		

	for (auto food : foods)
	{
			std::cout<< food<<std::endl;
	}*/
	
	// return 0;

// }