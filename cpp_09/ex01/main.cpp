#include"RPN.hpp"

	// if (argc == 2)
	// {
	// 	RPN	reversePolish;
	// 	int	result = reversePolish.performPostfix(argv[1]);
	// 	std::cout<<"Final result: "<<result<<std::endl;
	// }
	// else
	// 	std::cerr<<"Error: invalid number of arguments."<<std::endl;	

int main (int argc, char **argv)
{
	 if (argc == 2) {
        try {
            RPN reversePolish;
			const char* input = argv[1];
			int len = 0;
			for (const char* it = input; *it != '\0'; ++it) {
				if (!isspace(*it)) {
					len++;
				}
			}
			if(len < 2)
			{
				std::cerr << "Error: Invalid input." <<input<< std::endl;
        		return EXIT_FAILURE;
			}
            int result = reversePolish.performPostfix(input);
            std::cout << "Final result: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    } else {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
	
}