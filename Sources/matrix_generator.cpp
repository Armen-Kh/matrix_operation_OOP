#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <cstddef>
#include <cassert>
#include <vector>
#include <string>

void Four_Matrix_File_Generator(std::size_t matrix_number, std::size_t limit)
{
	std::size_t** dim = new std::size_t*[3];
	for(int i = 0; i < 3; ++i) {
		dim[i] = new std::size_t[matrix_number];
	}
        for (std::size_t i = 0; i < matrix_number; ++i) {
                dim[0][i] = (rand () % limit) + 1;
                dim[1][i] = (rand () % limit) + 1;
                dim[2][i] = (rand () % limit) + 1;
        }

	std::vector<std::string> file_name = {"Data/a.txt", "Data/b.txt", "Data/c.txt", "Data/d.txt"};

	for(int i = 0; i < 4; ++i) {
		std::ofstream fout(file_name[i], std::ios::out);
		for(std::size_t n = 1; n <= matrix_number; ++n) {
			assert(fout.good() && "unable to write '#' to file");
		        fout << '#';
        		
        		assert(fout.good() && "unable to write matrix number to file");
        		fout << n << '\n';

       			assert(fout.good() && "unable to write matrix rows number to file");
        		fout << dim[i / 2][n-1] << 'x';

       			assert(fout.good() && "unable to write matrix columns number to file");
        		fout << dim[i / 2 + 1][n-1] << '\n';

        		for(std::size_t j = 0; j < dim[i / 2][n-1]; ++j) {
                		for(std::size_t k = 0; k < dim[i / 2 + 1][n-1]; ++k) {
                        		assert(fout.good() && "unable to write to file");
                        		fout << std::setw(3) << rand() % 198 -99 << ", ";
               			}
                		assert(fout.good() && "unable to write to file");
				fout << std::endl;
        		}
                	assert(fout.good() && "unable to write to file");
			fout << std::endl;
		}	
		fout.close();
	}
	std::cout << "a.txt, b.txt, c.txt, d.txt matrix files are created!\n";
}


int main()
{
	srand(time(0));

	std::size_t matrix_number, mrc_limit;
	std::cout << "To generate matrix file you should\n";
        std::cout << "enter number of matrices for each file: ";
        std::cin >> matrix_number;
        std::cout << "enter upper limit for matrix rows and columns: ";
        std::cin >> mrc_limit;

	Four_Matrix_File_Generator(matrix_number, mrc_limit);

	return 0;
}

