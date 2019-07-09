#!/bin/bash

if [ -z $1 ]; then
	echo "To generate matrix files, use the \"g\" key."
	echo "To execute matrix operation, use the \"e\" key."
 	echo "To compare with golden output, use the \"t\" key."
elif [ $1 = "g" ]; then
	Bin/matrix_generator.exe
elif [ $1 = "e" ]; then
	Bin/main.exe
elif [ $1 = "t" ]; then
	Bin/matrix_file_comparator.exe
else
	echo "Incorrect key!"
fi	

