#include <iostream>
#include "Matrix.h"


Matrix::Matrix(int rows, int cols)
{
	if (rows < 0 || cols < 0)
	{
		throw std::out_of_range("out_of_range");
	}

	num_rows = rows;
	num_cols = cols;
	vec.assign(rows, std::vector<int>(cols));
}

void Matrix::Reset(int rows, int cols)
{
	if (rows < 0 || cols < 0)
	{
		throw std::out_of_range("out_of_range");
	}

	num_rows = rows;
	num_cols = cols;
	vec.assign(rows, std::vector<int>(cols));
}

int Matrix::GetRowCount() const
{
	return num_rows;
}

int Matrix::GetColCount() const
{
	return num_cols;
}

int Matrix::At(const int & row, const int & col) const
{
	return vec.at(row).at(col);
}

int& Matrix::At(const int & row, const int & col)
{
	return vec.at(row).at(col);
}

bool Matrix::operator==(const Matrix & rhs) const
{
	if (this->num_rows == rhs.num_rows && this->num_cols == rhs.num_cols)
	{
		for (int r = 0; r < num_rows; r++)
		{
			for (int c = 0; c < num_cols; c++)
			{
				if (this->At(r,c) != rhs.At(r,c))
				{
					return false;
				}
			}
		}
	}

	return true;
}

Matrix Matrix::operator+(const Matrix & rhs)
{
	if (this->num_rows != rhs.num_rows || this->num_cols != rhs.num_cols)
	{
		throw std::exception("Size of lhs and rhs is diferent");
	}

	Matrix result(num_rows, num_cols);

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			result.At(r, c) = this->At(r, c) + rhs.At(r, c);
		}
	}

	return result;
}

std::istream & operator>>(std::istream & stream, Matrix & rhs)
{
	int num_rows;
	int num_cols;

	stream >> num_rows >> num_cols;
	if (num_rows < 0 || num_cols < 0)
	{
		throw std::out_of_range("out_of_range");
	}
	rhs.Reset(num_rows, num_cols);

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			stream >> rhs.At(r, c);
		}
	}

	return stream;
}

std::ostream & operator<<(std::ostream & stream, Matrix & rhs)
{
	int num_rows = rhs.GetRowCount();
	int num_cols = rhs.GetColCount();


	stream << "Size of matrix: " << num_rows << '/' << num_cols << '\n';
	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			stream << rhs.At(r, c);
		}
	}

	return stream;
}
