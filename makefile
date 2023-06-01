main:
	g++ *.cpp -std=c++98 -pedantic -o main
run:
	valgrind --leak-check=full ./main
clean:
	rm -f *.o *.tar main
	clear
	reset
tar:
	tar -cvz makefile *.cpp -f FileName.tar
tar_gz:
	tar -cvz makefile *.cpp -f FileName.tar.gz
untar:
	tar -zxvf *.tar
untar_gz:
	tar -zxvf *.tar.gz
