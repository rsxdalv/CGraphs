# Project: Project
# Makefile created by Dev-C++ 4.9.9.0

CPP  = g++.exe
CC   = gcc.exe
WINDRES = windres.exe
RES  = 
OBJ  = Timetest.o Timeh.o $(RES)
LINKOBJ  = Timetest.o Timeh.o $(RES)
LIBS =  -L"C:/Dev-Cpp/lib"  
INCS =  -I"C:/Dev-Cpp/include" 
CXXINCS =  -I"C:/Dev-Cpp/include/c++/3.3.1"  -I"C:/Dev-Cpp/include/c++/3.3.1/mingw32"  -I"C:/Dev-Cpp/include/c++/3.3.1/backward"  -I"C:/Dev-Cpp/lib/gcc-lib/mingw32/3.3.1/include"  -I"C:/Dev-Cpp/include" 
BIN  = Project.exe
CXXFLAGS = $(CXXINCS)  
CFLAGS = $(INCS)  

.PHONY: all all-before all-after clean clean-custom

all: all-before Project.exe all-after


clean: clean-custom
	rm -f $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "Project.exe" $(LIBS)

Timetest.o: Timetest.cpp
	$(CPP) -c Timetest.cpp -o Timetest.o $(CXXFLAGS)

Timeh.o: Timeh.cpp
	$(CPP) -c Timeh.cpp -o Timeh.o $(CXXFLAGS)
