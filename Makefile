CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec.o: llrec.cpp llrec.h 
		$(CXX) $(CXXFLAGS) -c $< -o $@

llrec-test: llrec-test.cpp llrec.o 
		$(CXX) $(CXXFLAGS) $< -o $@

stack-test: stack-test.cpp
  	$(CXX) $(CXXFLAGS) $^ -o $@


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 