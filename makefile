CPP=g++
CPPFLAGC=-Wall -ggdb -o
SRC=src/persons.cpp src/helper.cpp src/system.cpp src/doctors.cpp src/TA.cpp src/students.cpp src/main.cpp

build:
	$(CPP) $(CPPFLAGC) main $(SRC)
gdb:
	gdb ./main

run:
	./main
