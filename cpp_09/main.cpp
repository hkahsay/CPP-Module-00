#include<iostream>
#include<fstream>
/*
int main(int argc, char **argv)
{
    printf("1\n");
    std::ifstream  *afile = NULL;
    printf("2\n");
  
    if (argc == 2)
    {
    printf("3\n");

        std::cout<< "argv[0]: "<<argv[0]<< " <argv[1]: "<<argv[1]<<std::endl;
        afile->open(argv[1]);
        printf("4\n");
    }
    else
    {
        std::cerr<<"Error: could not open file"<<std::endl;
    }
    
}*/
/*
int main(int argc, char **argv)
{
  std::cout << "Have " << argc << " arguments:" << std::endl;
  for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << std::endl;
  }
  std::istream* input = &std::cin; 
  if(argc > 1) {
    std::cout << input;
    std::cout << "more than argument found\n";
  }

  std::string inputs;
  std::cout<< "1:\n";
  std::cout<< argv[0];
  std::cout<< "\n2:\n";
  std::cout<< argv[1];
  std::cout<< "\n3:\n";
  std::cout<< input;

  std::cout<< "\nEnd\n";

  return 0;
}*/


using namespace std;
// int inputFormat()
// {

// }
int main (int ac, char **av) {
    if (ac == 2)
    {
        ofstream myfile (av[1]);
        bool isopen = myfile.is_open();
        if(isopen == true)
        {
            myfile << "Writing this to a file.\n";
            myfile << "Writing this to a file.\n";
            myfile << "Writing this to a file.\n";
            // if (inputformat)
            // {
            //     /* code */
            // }
            

        }
        // myfile.open (av[1]);

        else
            std::cerr<<"Error: Unable to open file"<<std::endl;

        myfile.close();
       
    }
    else
        std::cerr<<"Error: could not open file"<<std::endl;

    
  return 0;
}