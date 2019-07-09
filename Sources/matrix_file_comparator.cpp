#include <utility.hpp>

#include <limits>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>

void matrixNumberComparator(std::ifstream&, std::ifstream&, std::ofstream&,
					    std::size_t&, std::size_t&);
bool matrixComparator(const Matrix&, const Matrix&);
void Summarize(std::size_t, std::size_t, std::ofstream&);

int main()
{
	std::ifstream fg("Data/golden_out.txt"), fr("Data/result.txt");
	std::ofstream fw("Data/test_compare_result.txt");
	Matrix g, r;
	std::size_t total_matrix_count = 0;
	std::size_t incompatible_matrices = 0;
	std::size_t number_g = std::numeric_limits<std::size_t>::max();
	std::size_t number_r = std::numeric_limits<std::size_t>::max();
	char s;
	while(fg >> s && fr >> s) {
		++total_matrix_count;
		assert(s == '#' && "reading '#' character failed");
                matrixNumberComparator(fg, fr, fw, number_g, number_r);
		assert(number_g < std::numeric_limits<std::size_t>::max() && "invalid matrix number value");
		assert(number_r < std::numeric_limits<std::size_t>::max() && "invalid matrix number value");
		readMatrix(g, fg);
		readMatrix(r, fr);
		if(!matrixComparator(g, r)) {
			++incompatible_matrices;
			assert(fw.good() && "writing to file failed!");
	                fw << "Incompatible matrices: #";
        	        assert(fw.good() && "writing to file failed!");
                	fw << number_g;
         	        assert(fw.good() && "writing to file failed!");
               		fw << " -> #";
                	assert(fw.good() && "writing to file failed!");
                	fw << number_r << '\n';
		}
	}
	Summarize(total_matrix_count, incompatible_matrices, fw);
}

void matrixNumberComparator(std::ifstream& fg, std::ifstream& fr, std::ofstream& fw, 
			    std::size_t& number_g_out, std::size_t& number_r_out)
{
	number_g_out = std::numeric_limits<std::size_t>::max();
        number_r_out= std::numeric_limits<std::size_t>::max();
        assert(fg.good() && "reading from file failed!");
        fg >> number_g_out;
        assert(number_g_out < std::numeric_limits<std::size_t>::max() && "matrix number value is not valid");
        assert(fr.good() && "reading from file failed!");
        fr >> number_r_out;
        assert(number_r_out < std::numeric_limits<std::size_t>::max() && "matrix number value is not valid");
        if(number_g_out != number_r_out) {
      		assert(fw.good() && "writing to file failed!");
		fw << "Divergence of matrix number: #";
		assert(fw.good() && "writing to file failed!");
                fw << number_g_out;
                assert(fw.good() && "writing to file failed!");
                fw << " -> #";
                assert(fw.good() && "writing to file failed!");
                fw << number_r_out << '\n';
      	}
}	

bool matrixComparator(const Matrix& g, const Matrix& r)
{
        assert(g.getRows() == r.getRows() && " rows incompatibility!\n");
        assert(g.getColumns() == r.getColumns() && " columns incompatibility!\n");
        for(std::size_t i = 0; i < g.getRows(); ++i) {
                for(std::size_t j = 0; j < g.getColumns(); ++j) {
                        if(g.getData(i, j) != r.getData(i, j)) {
				return false;
                        }
                }
        }
        return true;
}


void Summarize(std::size_t total_matrix_count, std::size_t incompatible_matrices, std::ofstream& fw)
{
	if(0 == total_matrix_count) {
		assert(fw.good() && "writing to file failed");
		fw << "There is no any data for compare!\n";
                return;
        }
	assert(fw.good() && "writing to file failed");
        fw << "===================================================================\n";
	assert(fw.good() && "writing to file failed");
        fw << "checked matrices: ";
	assert(fw.good() && "writing to file failed");
        fw << total_matrix_count << "\n";
	assert(fw.good() && "writing to file failed");
        fw << "incompatible matrices: ";
	assert(fw.good() && "writing to file failed");
        fw << incompatible_matrices;
	assert(fw.good() && "writing to file failed");
	fw << ", percentage: ";
	assert(fw.good() && "writing to file failed");
        fw << float(incompatible_matrices) / total_matrix_count * 100;
	assert(fw.good() && "writing to file failed");
        fw << " %.\n";
	assert(fw.good() && "writing to file failed");
        fw << "===================================================================\n";
}



