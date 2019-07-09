#include <utility.hpp>

#include <iostream>
#include <fstream>
#include <cstddef>
#include <cassert>
#include <limits>
#include <cstdlib>

int main()
{
	std::ifstream fa("Data/a.txt"), fb("Data/b.txt"), fc("Data/c.txt"), fd("Data/d.txt");
	std::ofstream fr("Data/result.txt");
	Matrix a, b, c, d, t1, t2, r;
	char s;
	while(fa >> s && fb >> s && fc >> s && fd >> s) {
		assert(s == '#' && "reading '#' character failed");
		std::size_t number = std::numeric_limits<std::size_t>::max();
		bool bv = matrixNumberComparator(fa, fb, fc, fd, number);
	        assert(number < std::numeric_limits<std::size_t>::max() && "matrix number value is not valid");	
	        assert(bv && "incompatible numbers");	
		readMatrix(a, fa);
	        readMatrix(b, fb);
		t1.initialize(a.getRows(), a.getColumns());
		addMatrix(a, b, t1);
	        readMatrix(c, fc);
		readMatrix(d, fd);
		t2.initialize(c.getRows(), c.getColumns());
		addMatrix(c, d, t2);
		r.initialize(t1.getRows(), t2.getColumns());
		multMatrix(t1, t2, r);
		writeMatrix(number, r, fr);
	}
	fa.close();
	fb.close();
	fc.close();
	fd.close();
	fr.close();
	return 0;
}
