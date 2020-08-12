#include <algorithm>
#include <iostream>
#include <string>


std::string GetValuesString();
void PrintPermutation(std::string& values);


int main_h5()
{
	std::string val = GetValuesString();
	PrintPermutation(val);

	return 0;
}


std::string GetValuesString()
{
	int inputed_value = 0;
	std::cin >> inputed_value;

	std::string result = "";
	for (int i = inputed_value; i > 0; i--)
	{
		result += std::to_string(i);
	}

	return result;
}

void PrintPermutation(std::string& values)
{
	do
	{
		for (size_t i = 0; i < values.size(); i++)
		{
			std::cout << values[i] << " ";
		}

		std::cout << std::endl;
	} while (std::prev_permutation(values.begin(), values.end()));
}