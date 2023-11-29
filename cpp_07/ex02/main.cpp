#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int	main()
{
	std::cout<<"--------Empty array test--------\n";
	Array<int> empty;
	try//<< empty[0]
	{
		std::cout<< "access the value of empty array: "<<&empty <<std::endl;
		std::cout<< " access empty[0]: "<<empty[0]<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout<<"--------test copy constructor int string and float --------\n";
	Array<int> arr(3);
	arr[1] = 5;
	Array<int> arr2(arr);
	arr[1] = 6;
	Array<float> fnbr(MAX_VAL);
	fnbr[5]= 7.8f;
	Array<float> copyfnbr(fnbr);
	fnbr[5] = 10.7f;

	std::cout<<"arr.size():  " << arr.size()<< std::endl;
	std::cout<<"arr[1]:      " << arr[1]<< std::endl;
	std::cout<<"arr2.size(): " << arr2.size()<< std::endl;
	std::cout<<"arr2[1]:     " << arr2[1]<< std::endl;
	std::cout<<"fnbr.size():  " << fnbr.size()<< std::endl;
	std::cout<<"fnbr[5]:      " << fnbr[5]<< std::endl;
	std::cout<<"copyfnbr.size():  " << copyfnbr.size()<< std::endl;
	std::cout<<"copyfnbr[5]:      " << copyfnbr[5]<< std::endl;

	// std::cout<<"--------test assignment operator --------\n";
	// Array<int> arr3(3);
	// arr3[1] = 5;
	// Array<int> arr4(2);
	// arr4 = arr3;
	// arr3[1] = 6;

	// std::cout<<"arr3.size():  " << arr3.size()<< std::endl;
	// std::cout<<"arr3[1]:      " << arr3[1]<< std::endl;
	// std::cout<<"arr4.size():  " << arr4.size()<< std::endl;
	// std::cout<<"arr4[1]:      " << arr4[1]<< std::endl;



	return 0;
}


// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[15] = 50;
//         numbers[25] = 100;
//         numbers[745] = 250;

//         std::cout<<"numbers.size():  " << numbers.size()<< std::endl;
// 	    std::cout<<"numbers[15]:      " << numbers[15]<< std::endl;
// 	    std::cout<<"numbers[25]:      " << numbers[25]<< std::endl;
// 	    std::cout<<"numbers[745]:      " << numbers[745]<< std::endl;

//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }