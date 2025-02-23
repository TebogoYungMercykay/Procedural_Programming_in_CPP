# This is my makefile
FILES = *.cpp
NAME = rec
main:
	g++ -g *.cpp -std=c++98 -pedantic -o main

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
	g++ -fprofile-arcs -ftest-coverage -O0 -g -Wall -Wextra -o test main.cpp TesterHelpers.cpp ValueTesters.cpp
	./test
	gcov test-main.cpp -b -o .
	gcov test-TesterHelpers.cpp -b -o .
	gcov test-ValueTesters.cpp -b -o .