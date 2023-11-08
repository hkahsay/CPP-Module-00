#include"Array.hpp"
#define MAX_VALUE 10

int	main()
{
	std::cout<<"--------Empty array test--------\n";
	Array<int> empty;
	try
	{
		std::cout<< "access the value of empty array which is not possible: "<<&empty <<std::endl<< " access empty[0]"<< empty[0]<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout<<"--------test n size of array--------\n";
	
	Array<int> tarray(6);
	int * a = new int();
	std::cout << "value of a"<<a<<std::endl;
	int	*marraay = new int[6];
	tarray[0] = 2;
	tarray[1] = 5;
	tarray[3] = 6;
	marraay[0] = 5;
	marraay[1] = 8;
	std::cout<<"marray: "<<marraay[0]<<"\ntarray: "<< tarray[0]<<std::endl;
	

	return 0;
}