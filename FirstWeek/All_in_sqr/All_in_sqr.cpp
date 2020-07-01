#include <iostream>
#include <utility>
#include <vector>
#include <map>



template <typename T> T Sqr(T& item);
template <typename T> std::vector<T> operator *(const std::vector<T>& lhs, const std::vector<T>& rhs);
template <typename Key, typename Value> std::map<Key, Value> operator *(const std::map<Key, Value>& lhs, const std::map<Key, Value>& rhs);
template <typename First, typename Second> std::pair<First, Second> operator *(const std::pair<First, Second>& lhs, const std::pair<First, Second>& rhs);




int main()
{
	//VECTOR
	std::vector<int> v = { 1, 2, 3 };

	std::cout << "vector:";
	for (int x : Sqr(v))
	{
		std::cout << ' ' << x;
	}
	std::cout << std::endl;


	//MAP<INT,PAIR>
	std::map<int, std::pair<int, int>> map_of_pairs = { {4, {2, 2}}, {7, {4, 3}} };

	std::cout << "map of pairs:" << std::endl;
	for (const auto& x : Sqr(map_of_pairs))
	{
		std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
	}

	return 0;
}



template<typename T>
T Sqr(T& item)
{
	return item * item;
}


template<typename T>
std::vector<T> operator*(const std::vector<T>& lhs, const std::vector<T>& rhs)
{
	std::vector<T> res;
	for (size_t iter = 0; iter < lhs.size(); iter++)
	{
		res.push_back(lhs[iter] * rhs[iter]);
	}

	return res;
}


template<typename Key, typename Value>
std::map<Key, Value> operator*(const std::map<Key, Value>& lhs, const std::map<Key, Value>& rhs)
{
	std::map<Key, Value> res;
	for (const auto& item : lhs)
	{
		auto rhs_second_value = rhs.at(item.first);
		res[item.first] = item.second * rhs_second_value;
	}

	return res;
}


template<typename First, typename Second>
std::pair<First, Second> operator*(const std::pair<First, Second>& lhs, const std::pair<First, Second>& rhs)
{
	return std::make_pair(lhs.first * rhs.first, lhs.second * rhs.second);
}
