#include <algorithm>
#include <iostream>
#include <vector>


void PrintVectorPart(const std::vector<int>& numbers);


int main_hv1(){
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	std::cout << std::endl;
	
	PrintVectorPart({ -6, 1, 8, -5, 4 });	// Вывод отсутствует
	std::cout << std::endl;
	
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	std::cout << std::endl;


	return 0;
}


void PrintVectorPart(const std::vector<int>& numbers){
	// Класно, НО можно короче
	/*
	std::vector<int>::const_iterator border = numbers.end();
	for (auto it = numbers.begin(); it != numbers.end(); it++){
		if (*it < 0){
			border = it;
			break;
		}
	}*/

	std::vector<int>::const_iterator border = std::find_if(
		numbers.begin(), numbers.end(),
		[](int value) {
			return value < 0;
		}
	);

	while (border != numbers.begin()){
		border--;
		std::cout << *border << " ";
	}
}