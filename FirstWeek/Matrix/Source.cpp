#include <iostream>
#include "Matrix.h"



int main()
{
	Matrix m1;
	Matrix m2;
	Matrix sum;

	try
	{
		std::cout << "Matrix1:\n";
		std::cin >> m1;

		std::cout << "Matrix2:\n";
		std::cin >> m2;

		sum = m1 + m2;

		std::cout << m1  << std::endl;
		std::cout << m2  << std::endl;
		std::cout << sum << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");
	return 0;
}
