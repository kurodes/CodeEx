level: test.o level_hashing.o hash.o KVStore.o
	g++ -o level test.o level_hashing.o hash.o KVStore.o  -lm -lglog -lboost_serialization

test.o: test.cpp
	g++ -c test.cpp
level_hashing.o : level_hashing.cpp level_hashing.hpp
	g++ -c level_hashing.cpp
hash.o : hash.cpp hash.hpp
	g++ -c hash.cpp
KVStore.o : KVStore.cpp KVStore.hpp
	g++ -c KVStore.cpp

clean:
	rm *.o level
