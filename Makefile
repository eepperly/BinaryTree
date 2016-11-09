CXX=g++
flags=-std=c++11
objects=tree.h.gch

all: test

test: ${objects} test.cpp
	${CXX} ${flags} ${objects} test.cpp -o test

tree.h.gch : tree.h
	${CXX} ${flags} -c tree.h

clean:
	rm -f test *.o *~
