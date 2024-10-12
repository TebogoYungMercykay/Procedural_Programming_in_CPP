main:
	g++ *.cpp -std=c++98 -pedantic -o main
run:
	./main
clean:
	rm -f *.o *.tar main
	clear
tar:
	tar -cvz makefile *.cpp -f Pointers_and_Struct.tar
tar_gz:
	tar -cvz makefile *.cpp -f Pointers_and_Struct.tar.gz
untar:
	tar -zxvf *.tar
untar_gz:
	tar -zxvf *.tar.gz