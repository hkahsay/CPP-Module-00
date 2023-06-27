#include"sed.hpp"
#include<string>
#include<iostream>



void myReplace(std:: string& filename, const std:: string& s1, const std:: string& s2) {
	std:: size_t pos = filename.find(s1);
	
	while (pos != std:: string ::npos) {
		filename.erase(pos, s1.length());
		filename.insert(pos, s2);
		pos = filename.find(s1, pos + s2.length());
		// std:: cout << "replace by s2"<< filename<< std:: endl;
	}

}

// if (pos > filename.length())
	// {
	// 	std:: cout << "the psition must not me greater than the file"<<std:: endl;
	// 	return ;
	// }