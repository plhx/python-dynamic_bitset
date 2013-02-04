all: dynamic_bitset.so

dynamic_bitset.so: dynamic_bitset.o
	g++ -shared -o $@ $< -I/usr/include/python2.7 -lboost_python

dynamic_bitset.o: dynamic_bitset_wrapper.cpp
	g++ -O2 -fPIC -o $@ -c $< -I/usr/include/python2.7

clean:
	rm dynamic_bitset.o

