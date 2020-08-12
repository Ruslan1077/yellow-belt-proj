#include <algorithm>
#include <iostream>
#include <vector>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);


int main_h7_v2()
{
	std::vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
	MergeSort(std::begin(v), std::end(v));
	for (int x : v) 
	{
		std::cout << x << " ";
	}

	return 0;
}


template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
	if ((range_end - range_begin) < 3)
	{
		return;
	}

	std::vector<RandomIt::value_type> elements(range_begin, range_end);

	auto f_part_iter = elements.begin() + elements.size() / 3;
	auto s_part_iter = f_part_iter      + elements.size() / 3;

	MergeSort(elements.begin(), f_part_iter);
	MergeSort(f_part_iter, s_part_iter);
	MergeSort(s_part_iter, elements.end());

	std::vector<RandomIt::value_type> temp;
	std::merge(elements.begin(), f_part_iter, f_part_iter, s_part_iter, std::back_inserter(temp));

	std::merge(temp.begin(), temp.end(), s_part_iter, elements.end(), range_begin);
}