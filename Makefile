CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build_best: algo.o algo_test.o
	$(CC) algo_test.o algo.o $(CFLAGS) -o tester

build_snd_best: algo2.o algo2_test.o
	$(CC) algo2_test.o algo2.o $(CFLAGS) -o tester

algo.o: algo.cpp
	$(CC) algo.cpp -c $(CFLAGS)

algo2.o: algo2.cpp
	$(CC) algo2.cpp -c $(CFLAGS)

algo_test.o: algo_test.cpp
	$(CC) algo_test.cpp -c $(CFLAGS)

algo2_test.o: algo2_test.cpp
	$(CC) algo2_test.cpp -c $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o tester
