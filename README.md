#### `The Codes Are Yet To Be Optimised and Refined, I Implemented them whilst I was still a *beginner* in Programming!!`
________________________________________________________________________________________

#                         C++ Programming                               
________________________________________________________________________________________
- ### Requirements before running codes:
    - Install an IDE that compiles and runs C++ codes. Recommendation VS Code
    - How to setup WSL Ubuntu terminal shell and run it from Visual Studio Code: https://www.youtube.com/watch?v=fp45HpZuhS8&t=112s
    - Compiler Path Problems: https://forums.unrealengine.com/t/ue-4-27-how-to-fix-issues-in-visual-studio-code-red-squiggles-and-unable-to-resolve-configuration-with-compilerpath-c-program/568488
- ### About Codes:
    - The code is all written by myself only
    - I hard code them as part of my practice code, practical and assignemnts for my coding modules.
- ###  About Me: 
    - Tebogo Sello Selepe
    - Computer Sciences at Tuks
________________________________________________________________________________________
 ## Makefile
 ##### NB: A makefile Is Included to compile and run the codes on the terminal with the following commands:=
- make clean
- make
- make run


```C++
main:
	g++ -g *.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o *.tar.gz main
	reset
	clear

run:
	valgrind --leak-check=full ./main

tar:
	tar -cvz *.* -f Code.tar.gz
	
untar:
	tar -zxvf *.tar.gz
```
________________________________________________________________________________________
