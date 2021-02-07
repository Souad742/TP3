CC = clang-6.0
CFLAGS = -O3
CFLAG = -O0 -g
queens = queens
test_main=test_main
test_queens=test_queens
standard= -std=c99 

all:queens test_main test_queens


queens: queens.o main.o
	$(CC) $(standard) $(CFLAGS) -o $@ $^ 
	

%.o: %.c
	$(CC) $(standard) $(CFLAGS)  -c -o $@  $<

test_main:test_main.c main.c
	$(CC) $(standard) $(CFLAG)  -o $@ $<  -lcmocka
	
	./test_main 

test_queens:test_queens.c queens.c 
	$(CC) $(standard) $(CFLAG)  -o $@ $<  -lcmocka
	./test_queens


main.o: queens.h
main.o: rdtsc.h
queens.o: queens.h



clean:
	rm -f *.o queens test_main test_queens
.PHONY: clean
