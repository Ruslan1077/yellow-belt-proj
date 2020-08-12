#include <algorithm>
#include <iostream>
#include <vector>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);


int main_h7()
{
	std::vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort(begin(v), end(v));
	for (int x : v) 
	{
		std::cout << x << " ";
	}
	
	return 0;
}


template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
	if (range_end - range_begin < 2)
	{
		return;
	}

	std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
	auto mid = std::begin(elements) + elements.size() / 2;
	MergeSort(elements.begin(), mid);
	MergeSort(mid, elements.end());
	std::merge(elements.begin(), mid, mid, elements.end(), range_begin);
}