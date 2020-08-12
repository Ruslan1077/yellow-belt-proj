#include <algorithm>
#include <iostream>
#include <vector>
#include <string>


namespace _RemoveDuplicates
{
	template<typename T>
	void RemoveDuplicates(std::vector<T>& elements)
	{
		std::sort(elements.begin(), elements.end());
		elements.erase(
			std::unique(elements.begin(), elements.end()),
			elements.end()
		);
	}

	template <typename It>
	void PrintRange(It begin_iter, It end_iter)
	{
		for (auto it = begin_iter; it != end_iter; it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

int main_h4()
{
	std::vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
	_RemoveDuplicates::PrintRange(v1.begin(), v1.end());
	_RemoveDuplicates::RemoveDuplicates(v1);
	_RemoveDuplicates::PrintRange(v1.begin(), v1.end());


	std::vector<std::string> v2 = { "C++", "C#","F#", "C++", "C++","C", "C++", "C#","C#", "C", "F#" };
	_RemoveDuplicates::PrintRange(v2.begin(), v2.end());
	_RemoveDuplicates::RemoveDuplicates(v2);
	_RemoveDuplicates::PrintRange(v2.begin(), v2.end());

	return 0;
}