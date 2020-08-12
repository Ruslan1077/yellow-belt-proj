#include <algorithm>
#include <iostream>
#include <string>
#include <vector>



std::vector<std::string> SplitIntoWords(const std::string& str);



int main_hw3(){
	std::string s = "C Cpp Java Python ";
	std::vector<std::string> words = SplitIntoWords(s);


	std::cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			std::cout << "/";
		}
		std::cout << *it;
	}
	std::cout << std::endl;



	return 0;
}



std::vector<std::string> SplitIntoWords(const std::string& str) {
	std::vector<std::string> result;
	auto first_char = str.begin();

	for (auto it = str.begin(); it != str.end(); it++) {
		if (*it == *std::find(it, str.end(), ' ')) {
			result.push_back(std::string(first_char, it));
			first_char = it + 1;
		}
	}

	return result;
}