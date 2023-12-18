#include"BitcoinExchange.hpp"
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

void  print_map(std::string_view comment, const std::map<std::string, int> &m)
{
  std::cout<<comment;
  for (std::map<std::string, int>::const_iterator  it = m.begin() ; it != m.end(); it++)
  {
    std::cout<<it->first<< " = "<< it->second<< ";"<<std::endl;
  }
  
}

int main (int ac, char **av) {
    if (ac == 2)
    {
        // std::ofstream myfile (av[1]);
        // std::ifstream dataBase("data.csv");
        // std::cerr<<"Error: Unable to open file"<<std::endl;

        BitcoinExchange btc("data.csv", av[1]);
        
        // myfile.close();

       
    }
    else
        std::cerr<<"Error: could not open file"<<std::endl;

    
  return 0;
}