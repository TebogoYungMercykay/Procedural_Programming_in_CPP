# This is my makefile
FILES = *.cpp *.txt
NAME = Assignment
main:
	g++ -g *.cpp -std=c++98  -pedantic -Wall -Wextra -pthread -o main

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.info *.gz *.html main test *.css output.txt coverage.txt
	reset
	clear

run:
	valgrind --leak-check=full ./main

tar:
	tar -cvz $(FILES) -f $(NAME).tar.gz

untar:
	tar -zxvf *.tar.gz

cov:
	make clean
	g++ -fprofile-arcs -ftest-coverage -O0 -g -Wall -Wextra -o test main.cpp IO.cpp Instructions.cpp Memory.cpp OS.cpp
	./test
	gcov test-IO.cpp -b -o .
	gcov test-Instructions.cpp -b -o .
	gcov test-Memory.cpp -b -o .
	gcov test-OS.cpp -b -o .