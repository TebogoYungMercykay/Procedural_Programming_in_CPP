# C++ Programming

---

## Description

This repository is dedicated to solving **Linear Programming** problems in **C++**. It includes various algorithms and methods, all implemented as part of my practice and assignments for coding modules. The focus is on building efficient solutions using fundamental C++ programming concepts.

---

## Requirements

Before running the C++ code, ensure you have the following set up:

- **IDE Recommendation**: Install an IDE that supports C++ compilation and execution, such as **Visual Studio Code**.
- **Setting up WSL Ubuntu terminal**: Follow this [guide](https://www.youtube.com/watch?v=fp45HpZuhS8&t=112s) to set up WSL on Visual Studio Code for a Linux-based terminal environment.
- **Compiler Path Configuration**: If you encounter issues with compiler paths in VS Code, refer to this [forum discussion](https://forums.unrealengine.com/t/ue-4-27-how-to-fix-issues-in-visual-studio-code-red-squiggles-and-unable-to-resolve-configuration-with-compilerpath-c-program/568488) for troubleshooting steps.

---

## Code Overview

- All the code provided here is written by me.
- This code includes practice exercises, practical implementations, and assignments related to **Linear Programming**.

---

## Compilation and Execution

### Using the Makefile

A Makefile is provided to simplify the process of compiling and running the C++ code via the terminal.

#### Makefile Commands:

- **`make`**: Compiles the `.cpp` files and generates an executable named `main`.
- **`make run`**: Runs the executable using `valgrind` to check for memory leaks.
- **`make clean`**: Removes the executable and object files, and clears the terminal.
- **`make tar`**: Compresses the source files and the Makefile into a `.tar.gz` archive.
- **`make untar`**: Extracts files from the `.tar.gz` archive.

```Makefile
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

---

## Conclusion

This C++ program was developed as part of my coding practice and assignments. Using the Makefile, you can easily compile, run, and manage the code. Additionally, memory leaks can be checked with `valgrind` to ensure proper memory management.

## Contributing

This project is primarily for personal learning and demonstration purposes. However, if you have suggestions for improvements, feel free to open an issue or submit a pull request.

## License

This project is open source. Please check the repository for any specific license information.
