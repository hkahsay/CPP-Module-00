#include <iostream> // std::cout
#include <string>   // std::string, std::stod
#include <cmath>

void exit_failure(char *argv[])
{
    std::cerr << "Usage: " << argv[0] << " <input>" << std::endl;
    std::cerr << "  where <input> is a double, a float or a char." << std::endl;
    exit(EXIT_FAILURE);
}

/**
 * Convert a float to a string. Always print at least one digit after the
 * decimal point, and always print the 'f' at the end.
 */
void print_float(float value)
{
    // Add a trailing '.0' if the value has no decimal part using modf
    // Source: https://stackoverflow.com/a/47245857
    double integral;
    if(std::modf(value, &integral) == 0)
    {
        std::cout << value << ".0f";
    } else {
        std::cout << value << "f";
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        exit_failure(argv);

    std::string input = argv[1];

    // TODO: check if we want to handle the case without quotes
    // TODO: add char handling
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
    {
        std::cout << "char: '" << input[1] << "'" << std::endl;

        // TODO: Check if within printable range
        std::cout << "int: " << static_cast<int>(input[1]) << std::endl;

        // TODO: Check if within printable range
        std::cout << "float: ";
        print_float(static_cast<float>(input[1]));
        std::cout << std::endl;

        // TODO: Check if within printable range
        std::cout << "double: " << static_cast<double>(input[1]) << std::endl;
    }
    else if (input.find('.') != std::string::npos)
    {
        // Check if ends with 'f'
        if (input[input.length() - 1] == 'f')
        {
            // Use stof to convert to float
            // See https://en.cppreference.com/w/cpp/string/basic_string/stol
            // and https://cplusplus.com/reference/string/stod/
            // and https://cplusplus.com/reference/string/stof/
            try
            {
                std::size_t pos;
                const float value = std::stof(input, &pos);

                if (pos != input.length() - 1)
                {
                    std::cerr << "Unexpected input after the float at position " << pos << std::endl;
                    exit_failure(argv);
                }
                // Print the value cast to a char, to an int, to a float, to a double.
                // TODO: if not a printable character, print "Not displayable"
                std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
                std::cout << "int: " << static_cast<int>(value) << std::endl;

                std::cout << "float: ";
                print_float(value);
                std::cout << std::endl;

                // TODO: always print at least one digit after the decimal point
                std::cout << "double: " << static_cast<double>(value) << std::endl;
            }
            catch (std::invalid_argument const &ex)
            {
                std::cerr << "Tried to parse as a float, but failed." << std::endl;
                exit_failure(argv);
            }
            catch (std::out_of_range const &ex)
            {
                // TODO: understand why we never get here
                std::cerr << "Float value out of range." << std::endl;
                exit_failure(argv);
            }
        }
        else
        {
            try
            {
                std::size_t pos;
                const double value = std::stod(input, &pos);

                if (pos != input.length())
                {
                    std::cerr << "Unexpected input after the double at position " << pos << std::endl;
                    exit_failure(argv);
                }
                std::cout << "We got a double: " << value << std::endl;
            }
            catch (std::invalid_argument const &ex)
            {
                std::cerr << "Tried to parse as a double, but failed." << std::endl;
                exit_failure(argv);
            }
            catch (std::out_of_range const &ex)
            {
                // TODO: understand why we never get here
                std::cerr << "Double value out of range." << std::endl;
                exit_failure(argv);
            }
        }
    }

    // TODO: add int handling

    return 0;
}
