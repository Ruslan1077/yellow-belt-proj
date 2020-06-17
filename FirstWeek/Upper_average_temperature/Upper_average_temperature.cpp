#include <iostream>
#include <cstdint>
#include <vector>

std::vector<int32_t> SetTemperature(size_t count_of_days);
int32_t CalcAvg(std::vector<int32_t> vec);
void PrintUpperAvg(const std::vector<int32_t>& temp, int32_t avg);

int main()
{
	size_t count_of_days = 0;
	std::cin >> count_of_days;

	std::vector<int32_t> temp = SetTemperature(count_of_days);
	int32_t avg = CalcAvg(temp);

	PrintUpperAvg(temp, avg);
	return 0;
}

std::vector<int32_t> SetTemperature(size_t count_of_days)
{
	std::vector<int32_t> vec(count_of_days);

	for (size_t i = 0; i < count_of_days; i++)
	{
		std::cin >> vec.at(i);
	}

	return vec;
}

int32_t CalcAvg(std::vector<int32_t> vec)
{
	int32_t sum = 0;

	for (int32_t i : vec)
	{
		sum += i;
	}

	return sum / static_cast<int32_t>(vec.size());
}

void PrintUpperAvg(const std::vector<int32_t>& temp, int32_t avg)
{
	for (int32_t i : temp)
	{
		if (i > avg)
		{
			std::cout << i << ' ';
		}
	}
}
