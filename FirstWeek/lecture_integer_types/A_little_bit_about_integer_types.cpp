#include <iostream>
#include <vector>
#include <iomanip>

/*
	�������� � ������������� ����
*/


// ������ ������� ����� ����������� ��� ������ => ��� ������� ��������� ���� �� ����������� ������� ������������ ������������ ���� 
// ������ ����������� ������ (� ��� �������)
/*
int main()
{
	std::vector<int> t = { -8, -7, 3, -5 };
	int sum = 0;

	for (int x : t)
	{
		sum += x;
	}

	int avg = sum / t.size();
	std::cout << "Average value is: " << avg << std::endl;


	return 0;
}
*/



//	int - ����������� ������������� ��� ������ (�������� �������� ��������: [-2^31; 0; 2^31-1])
//	��� ����� ����� � ���� ���������� ������� int-��
// auto x = 1 -> int

// unsigned int - ����������� ������ int-� (�������� �������� ��������: [0; 2^32-1])
// size_t - ��� ��� ������������� �������� ����������  (��� 32-������ ������ [0; 2^32-1]
//														��� 64-������ ������ [0; 2^641-])
/*
int main()
{
	int x = 2'000'000'000;
	std::cout << x << ' ';	// ��� �� ��

	x *= 2;	// � �������� ��� int 4'000'000'000 �� ��������� => �����, ��� ���������, ������������ ������
	std::cout << x << ' ';

	return 0;
}
*/

#include <cstdint>	// ��������� ������������ ���� ������ � ������� ��������� �������� (include ����� ���� ��� ����������� �������, � �������� �������� ����� ��������� �����������!!!)
#include <limits>   // ��������� ������ ������ �������� �������� ����� ������

int main()
{
	std::cout << "Size of int8_t:  " << std::setw(2) << sizeof(int8_t)  * 8 << " bit" << std::endl;
	std::cout << "Size of int16_t: " << std::setw(2) << sizeof(int16_t) * 8 << " bit" << std::endl;
	std::cout << "Size of int32_t: " << std::setw(2) << sizeof(int32_t) * 8 << " bit" << std::endl;
	std::cout << "Size of int64_t: " << std::setw(2) << sizeof(int64_t) * 8 << " bit" << std::endl;
	
	std::cout << std::endl;

	std::cout << "Limit of int8_t:  " << std::numeric_limits<int8_t>::min()  << "; " << std::numeric_limits<int8_t>::max()  << std::endl;
	std::cout << "Limit of int16_t: " << std::numeric_limits<int16_t>::min() << "; " << std::numeric_limits<int16_t>::max() << std::endl;
	std::cout << "Limit of int32_t: " << std::numeric_limits<int32_t>::min() << "; " << std::numeric_limits<int32_t>::max() << std::endl;
	std::cout << "Limit of int64_t: " << std::numeric_limits<int64_t>::min() << "; " << std::numeric_limits<int64_t>::max() << std::endl;
	

	return 0;
}