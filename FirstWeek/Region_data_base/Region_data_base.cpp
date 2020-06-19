#include <iostream>
#include <vector>
#include <tuple>
#include <map>


enum class Lang
{
	DE,
	FR,
	IT
};

struct Region
{
	std::string std_name			  = "";
	std::string parent_std_name		  = "";
	std::map<Lang, std::string> names;
	int64_t population				  = 0;
};

bool operator <(const Region& lhs, const Region& rhs)
{
	return std::tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
		     std::tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);

}

int FindMaxRepetitionCount(const std::vector<Region>& regions)
{
	int result = 0;
	std::map<Region,int> count_of_regions;

	for (const Region& item : regions)
	{
		count_of_regions[item]++;
	}

	for (const auto& item : count_of_regions)
	{
		if (result < item.second)
		{
			result = item.second;
		}
	}
	
	return result;
}

int main()
{
	std::vector<Region> regions;
	Region tmp;

	tmp.std_name        = "Moscow";
	tmp.parent_std_name = "Russia";
	tmp.names[Lang::DE] = "Moskau";
	tmp.names[Lang::FR] = "Moscou";
	tmp.names[Lang::IT] = "Mosca";
	tmp.population      = 89;
	regions.push_back(tmp);
	regions.push_back(tmp);
	regions.push_back(tmp);

	tmp.std_name = "Russia";
	tmp.parent_std_name = "Eurasia";
	tmp.names[Lang::DE] = "Russland";
	tmp.names[Lang::FR] = "Russie";
	tmp.names[Lang::IT] = "Russia";
	tmp.population = 89;
	regions.push_back(tmp);
	regions.push_back(tmp);

	std::cout << FindMaxRepetitionCount(regions);


	return 0;
}
