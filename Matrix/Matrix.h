#pragma once
#include <vector>

class Matrix
{
public:
	Matrix() : Matrix(0, 0) { }
	Matrix(int rows, int cols);

	void Reset(int rows, int cols);

	int GetRowCount() const;
	int GetColCount() const;
	int At(const int& row, const int& col) const;
	int& At(const int& row, const int& col);

	bool operator ==(const Matrix& rhs) const;

	Matrix operator+ (const Matrix& rhs);

private:
	std::vector<std::vector<int>> vec;
	int num_rows;
	int num_cols;
};


std::istream& operator >>(std::istream& stream, Matrix& rhs);
std::ostream& operator <<(std::ostream& stream, Matrix& rhs);
