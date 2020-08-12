#include"sum_reverse_sort.h";

int Sum(int lhs, int rhs)
{
	return lhs + rhs;
}


std::string Reverse(std::string str)
{
	std::string buff = "";

	for (int i = str.size(); i >= 0; i--)
	{
		buff += str[i];
	}

	return buff;
}


void Sort(std::vector<int>& nums)
{
	if (nums.size() > 1)
	{
		bool exit = false;
		int end_border = nums.size();

		while (!exit)
		{
			exit = true;
			for (int i = 0; i + 1 < end_border; i++)
			{
				if (nums[i] > nums[i + 1])
				{
					std::swap(nums[i], nums[i + 1]);
					exit = false;
				}
			}

			end_border--;
		}
	}
}