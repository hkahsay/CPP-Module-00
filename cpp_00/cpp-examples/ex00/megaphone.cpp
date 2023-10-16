#include<iostream>
#include<string>
#include<locale>

// using namespace std;

int main(int argc, char **argv)
{
   if (argc > 1)
   {
        for (int i = 1; i < argc; i++)
        {
            std:: string arguments = argv[i];
            std::locale loc;
            for (std:: string::size_type j = 0; j < arguments.size(); ++j)
            {
                arguments[j] = toupper(arguments[j], loc);
            }
            std::cout << arguments;

        }
        std::cout << std:: endl;

   }
   else
        std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
    return (0);
}
