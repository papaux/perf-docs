CC?=gcc
CXX?=g++ 
CXXFLAGS= -g -std=c++11 -Wall

BIND=./bin

all: prepare 2d-array callstack matrix-mult sudoku

prepare:
	@mkdir -p $(BIND)

2d-array: 2d-array-bad.cpp 2d-array-good.cpp
	$(CXX) -o $(BIND)/2d-array-good 2d-array-good.cpp $(CXXFLAGS)
	$(CXX) -o $(BIND)/2d-array-bad 2d-array-bad.cpp $(CXXFLAGS)

callstack: callstack.cpp
	$(CXX) -o $(BIND)/callstack-ok callstack.cpp $(CXXFLAGS) -fno-omit-frame-pointer
	$(CXX) -o $(BIND)/callstack-not-ok callstack.cpp $(CXXFLAGS) -fomit-frame-pointer

matrix-mult: matrix-mult.cpp
	$(CXX) -o $(BIND)/$@ $^ $(CXXFLAGS)
 
sudoku: sudoku-checks.cpp sudoku-solver.cpp 
	$(CXX) -o $(BIND)/$@ $^ $(CXXFLAGS)
	cp *.sudoku $(BIND)/


#$(OBJD)/%.o: $(SRCD)/%.cpp
#	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: mrproper clean all prepare

clean:
	rm -f $(BIND)/*

mrproper:
	rm -rf $(BIND)
	rm -f perf.data perf.data.old
