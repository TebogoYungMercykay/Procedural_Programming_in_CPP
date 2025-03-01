main:
	g++ -g *.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.info *.gz *.html main test *.css output.txt coverage.txt
	reset
	clear

run:
	valgrind --leak-check=full ./main

tar:
	tar -cvz *.cpp -f CODE.tar.gz

untar:
	tar -zxvf *.tar.gz

cov:
	make clean
	g++ -fprofile-arcs -ftest-coverage -O0 -g -Wall -Wextra -o test ROBOTS.cpp main.cpp
	./test
	gcov test-ROBOTS.cpp -b -o .
