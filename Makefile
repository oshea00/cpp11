CC=g++
CFLAGS=-std=c++11 -I.

cpp11:
	$(CC) $(CFLAGS) -o $@ main.cc

clean:
	rm cpp11

