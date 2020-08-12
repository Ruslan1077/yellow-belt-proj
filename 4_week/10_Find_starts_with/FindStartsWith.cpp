#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <tuple>

#define ALLRANGE(a) std::begin(a),std::end(a)



template<typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith_char(RandomIt range_begin, RandomIt range_end, char prefix);

template<typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith_string(RandomIt range_begin, RandomIt range_end, const std::string& prefix);

template<typename RandomIt>
void MyPrint(RandomIt begin, RandomIt end);



int main_h10()
{
	std::vector<std::string> v = {
		"minsk",
		"kiev",
		"moscow",
		"istambul",
		"varshava",
		"murmansk",
		"mogilew",
	};
	MyPrint(ALLRANGE(v));
	std::sort(ALLRANGE(v));
	MyPrint(ALLRANGE(v));
	auto result = FindStartsWith_string(ALLRANGE(v), "mo");
	MyPrint(result.first, result.second);

	return 0;
}


template<typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith_char(RandomIt range_begin, RandomIt range_end, char prefix)
{	
	std::string lower_target = { prefix };
	std::string upper_target = { prefix + 1};

	auto lower = std::lower_bound(range_begin, range_end, lower_target);
	auto upper = std::upper_bound(range_begin, range_end, upper_target);

	return std::make_pair(lower, upper);
}


template<typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith_string(RandomIt range_begin, RandomIt range_end, const std::string& prefix)
{
	return std::equal_range(range_begin, range_end, prefix, 
		[&prefix](const std::string & a, const std::string & b) {
			return a.compare(0, prefix.length(), b.substr(0, prefix.length())) < 0;
	    });
}


template<typename RandomIt>
void MyPrint(RandomIt begin, RandomIt end)
{
	for (RandomIt it = begin; it != end; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}