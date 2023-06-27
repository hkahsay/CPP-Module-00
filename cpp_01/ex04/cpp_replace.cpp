#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void my_replace(std::string& input, const std::string& to_find, const std::string& replacement) {
    // Doc of find, erase and insert:
    // - https://cplusplus.com/reference/string/string/find/
    // - https://cplusplus.com/reference/string/string/erase/
    // - https://cplusplus.com/reference/string/string/insert/
    std::size_t pos = input.find(to_find);
    while(pos != -1) {
        input.erase(pos, to_find.length());
        input.insert(pos, replacement);
        pos = input.find(to_find, pos + replacement.length());
    }
}

void tests() {
    std::string s1 = "Hello world";
    my_replace(s1, "Hello", "Hello everyone");
    assert(s1 == "Hello everyone world");

    std::string s2 = "a\nb\nc";
    my_replace(s2, "a\nb", "d");
    assert(s2 == "d\nc");
}

int main(int argc, char* argv[]) {
    //tests();
    //return EXIT_SUCCESS;

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return EXIT_FAILURE;
    }

    std::string input_filename = argv[1];
    std::string to_find = argv[2];
    std::string replacement = argv[3];

    std::ifstream input = std::ifstream(input_filename); // Same as std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Unable to open input file.\n";
        return EXIT_FAILURE;
    }

    // Doc for stringstream: https://cplusplus.com/reference/sstream/stringstream/
    std::stringstream buffer;
    buffer << input.rdbuf(); // read the whole file into the buffer
    std::string content = buffer.str();
    my_replace(content, to_find, replacement);

    std::ofstream output = std::ofstream(input_filename + ".replace"); // Same as std::ofstream output(input_filename + ".replace");
    if (!output) {
        std::cerr << "Unable to open output file.\n";
        return EXIT_FAILURE;
    }

    output << content;

    return EXIT_SUCCESS;
}
