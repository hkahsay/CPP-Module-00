#include"sed.hpp"
#include<string>
#include<sstream>
#include<iostream>
#include<fstream>

// void myReplace(std:: string& filename, const std:: string& s1, const std:: string& s2) {
// 	std:: size_t pos = filename.find(s1);
	
// 	while (pos != std:: string ::npos) {
// 		filename.erase(pos, s1.length());
// 		filename.insert(pos, s2);
// 		pos = filename.find(s1, pos + s2.length());
// 		// std:: cout << "replace by s2"<< filename<< std:: endl;
// 	}

// }

int	main(int argc, char* argv[]) {
	if (argc < 4) {
		
		std:: cerr << "usage: " << argv[0]<< "<inputFile> <toFind> <toReplace>\n";
		return 1;
	}
	std:: string inputFile = argv[1];
	std:: string toFind = argv[2];
	std:: string toReplace = argv[3];

	//.c_str() member of std::string that returns c-style(const char*) constructor to open std::ifstream
	std:: ifstream ifs(inputFile.c_str());// is the same as  std::ifstream ifs = std::ifstream(inputFile)
	if (!ifs)
	{
		std:: cerr << "Unable to open input file.\n";
		return 1;
	}
	std:: stringstream buffer;
	buffer << ifs.rdbuf(); // read the whole file into the buffer
	std:: string strContent = buffer.str();// change stringstream into string
	myReplace(strContent, toFind, toReplace);
	ifs.close();

	std:: cout << "strcontent "<< strContent<<std::endl;

	std::ofstream ofs(inputFile + ".replace");
	if (!ofs)
	{
		std:: cerr<< "Unable to open outpu file." << std:: endl;
		return 1;
	}
	
	ofs << strContent;
	ofs.close();

	return 0;
}
