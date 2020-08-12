#include <iostream>
#include <string>
#include <deque>



std::string ArithmeticAlgorithm_f(int start_value, int count_of_operations);
std::string ArithmeticAlgorithm_s(int start_value, int count_of_operations);


int main()
{
	int start_value = 0;
	std::cin >> start_value;

	int count_of_operations = 0;
	std::cin >> count_of_operations;

	std::string result = ArithmeticAlgorithm_f(start_value, count_of_operations);

	for (char item : result)
	{
		if (item == '+' || item == '-' || item == '*' || item == '/')
		{
			std::cout << " " << item << " ";
		}
		else
		{
			std::cout << item;
		}
	}
	
	
	return 0;
}


std::string ArithmeticAlgorithm_f(int start_value, int count_of_operations)
{
	std::string result = std::to_string(start_value);
	std::string operation = "";

	for (int i = 0; i < count_of_operations; i++)
	{
		std::cin >> operation;

		result = "(" + result + ")" + operation;
	}

	return result;
}


std::string ArithmeticAlgorithm_s(int start_value, int count_of_operations)
{
	std::string result = std::to_string(start_value);
	std::string operation = "";
	std::string prev_operation = "";
	

	for (int i = 0; i < count_of_operations; i++)
	{
		std::cin >> operation;

		if (operation[0] == '*' || operation[0] == '/')
		{
			if (prev_operation[0] == '+' || prev_operation[0] == '-')
			{
				result = "(" + result + ")";
			}
		}

		result += operation;
		prev_operation = operation;
	}

	return result;
}
