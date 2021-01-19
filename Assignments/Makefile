CC = g++
CXXFLAGS = -O3 -mcx16 -march=native -std=c++17 -Wall -Wextra -Werror -fcilkplus -DCILK -fpic

all: reduce

reduce: reduce.cc get_time.h
	$(CC) $(CXXFLAGS) reduce.cc -o reduce

par: par.cpp get_time.h
	$(CC) $(CXXFLAGS) par.cpp -o par

seq: seq.cpp get_time.h
	$(CC) $(CXXFLAGS) seq.cpp -o seq

clean:
	rm reduce
	rm par
	rm seq

.PHONY: clean
