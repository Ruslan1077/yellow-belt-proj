#include <iostream>

#include "sum_reverse_sort.h"

int main()
{
	std::vector<int> vec = { 10,1,8,4,2,5,6 };
	Sort(vec);

	std::cout << "Sum: " << Sum(5, 8) << std::endl;
	std::cout << "Reverse" << Reverse(std::string{ "Hello World!" }) << std::endl;
	std::cout << "Sort: ";
	for (const int& item : vec)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;

	return 0;
}