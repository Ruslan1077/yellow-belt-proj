#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>



template<typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border);


int main_hw2() {
	for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::string to_find = "Python";
	std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;

	return 0;
}


template<typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border) {
	auto border_it = std::find_if(elements.begin(), elements.end(), [border](const T & value) {
		return value > border;
	});


	std::vector<T> result;
	for (auto it = border_it; it != elements.end(); it++) {
		result.push_back(*it);
	}

	return result;
}