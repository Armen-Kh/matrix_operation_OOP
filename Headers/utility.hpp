#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <fstream>
#include <cstddef>

using dataType = int;

class Matrix
{
private:
	std::size_t mRows;
	std::size_t mColumns;
	dataType* mData;
public:
	Matrix();
	~Matrix();
	void initialize(const std::size_t, const std::size_t);
	void setData(const std::size_t, const std::size_t, const dataType&);
	dataType getData(const std::size_t, const std::size_t) const;
	std::size_t getRows() const;
	std::size_t getColumns() const; 
};

std::size_t readMatrixNumber(std::ifstream&);
bool matrixNumberComparator(std::ifstream&, std::ifstream&, std::ifstream&, std::ifstream&, std::size_t&);
void readMatrix(Matrix&, std::ifstream&);
void writeMatrix(std::size_t, const Matrix&, std::ofstream&);
void addMatrix(const Matrix&, const Matrix&, Matrix&);
void multMatrix(const Matrix&, const Matrix&, Matrix&);

#endif
