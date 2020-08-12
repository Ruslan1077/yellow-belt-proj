#include <iostream>
#include <string>
#include <map>





template<typename Key, typename Value> Value& GetRefStrict(std::map<Key, Value>& map, const Key& key);




int main()
{
	std::map<int, std::string> m = { {0, "value"} };
	std::string& item = GetRefStrict(m, 1);
	item = "newvalue";
	std::cout << m[0] << std::endl; // выведет newvalue

	return 0;
}

template<typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& map, const Key& key)
{
	try
	{
		return map.at(key);
	}
	catch (std::exception e)
	{
		throw std::runtime_error("");
	}
}
