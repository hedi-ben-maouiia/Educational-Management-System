CPP=g++
CPPFLAGC=-Wall -ggdb -o
SRC=src/helper.cpp src/main.cpp src/students.cpp

build:
	$(CPP) $(CPPFLAGC) main $(SRC)
gdb:
	gdb ./main

run:
	./main
