SOURCES = $(wildcard Sources/*.cpp)
#OBJECTS = $(patsubst Sources/%.cpp,Objects/%.o,$(SOURCES))
TARGETS = Bin/matrix_generator.exe Bin/main.exe Bin/matrix_file_comparator.exe

.PHONY : clean

START : $(TARGETS)

Bin/matrix_generator.exe : Objects/matrix_generator.o
	mkdir -vp Bin
	g++ $< -o $@

Bin/main.exe : Objects/main.o Objects/utility.o
	mkdir -vp Bin
	g++ $^ -g -o $@

Bin/matrix_file_comparator.exe : Objects/matrix_file_comparator.o Objects/utility.o
	mkdir -vp Bin
	g++ $^ -g -o $@

Objects/%.o : Sources/%.cpp
	mkdir -vp Objects
	g++ -c $< -I./Headers -o $@

clean :
	rm -rf Bin Objects
