CC = g++
CXXFLAGS = -O3 -mcx16 -march=native -std=c++17 -Wall -Wextra -Werror -fcilkplus -DCILK -fpic

all: reduce

reduce: reduce.cc get_time.h
	$(CC) $(CXXFLAGS) reduce.cc -o reduce

par: par.cpp get_time.h
	$(CC) $(CXXFLAGS) par.cpp -o par

par2: par2.cpp get_time.h
	$(CC) $(CXXFLAGS) par2.cpp -o par2

seq: seq.cpp get_time.h
	$(CC) $(CXXFLAGS) seq.cpp -o seq

seq2: seq2.cpp get_time.h
	$(CC) $(CXXFLAGS) seq2.cpp -o seq2

clean:
	rm reduce
	rm par
	rm par2
	rm seq
	rm seq2

.PHONY: clean
