# This is my makefile
FILES = *.cpp *.h *.csv *.txt *.md *.sh *.py
NAME = Files
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
