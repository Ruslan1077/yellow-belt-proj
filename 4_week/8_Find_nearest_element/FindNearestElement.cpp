#include <algorithm>
#include <iostream>
#include <set>


std::set<int>::const_iterator FindNearestElement(const std::set<int>& numbers, int border);





int main_h8()
{
	std::set<int> numbers = { 1, 4, 6};
	int param = 100;

	std::cout <<
		*FindNearestElement(numbers, 0) << " " <<
		*FindNearestElement(numbers, 3) << " " <<
		*FindNearestElement(numbers, 5) << " " <<
		*FindNearestElement(numbers, 6) << " " <<
		*FindNearestElement(numbers, 100) << std::endl;


	std::set<int> empty_set;
	std::cout << (FindNearestElement(empty_set, 8) == empty_set.end()) << std::endl;

	return 0;
}




std::set<int>::const_iterator FindNearestElement(const std::set<int> & numbers, int border)
{
	auto nearest_it = std::lower_bound(numbers.begin(), numbers.end(), border);

	if (nearest_it != numbers.begin())
	{
		if (nearest_it == numbers.end() ||
			abs(*nearest_it - border) >=
			abs(border - *std::prev(nearest_it)))
		{
			return std::prev(nearest_it);
		}
	}
	return nearest_it;
}
