#ifndef TICTACTOEHELPER_H
#define TICTACTOEHELPER_H

#include <string>

std::string generateEmptyBoard();

// TASK 1 - 25%
char getCell(std::string board, int cellIndex);
std::string makeMove(std::string board, int position, char symbol);
std::string prettyPrint(std::string board);

// TASK 2 - 12%
bool isValidMove(std::string board, int cell);
bool isInValidMove(std::string board, int cell);
bool isPlayerTurn(int turnCount, char symbol);
bool isPlayerATurn(int turnCount);
bool isPlayerBTurn(int turnCount);

// TASK 3 - 10%
bool rowCheck(std::string board, int row, char symbol);
bool colCheck(std::string board, int col, char symbol);

// TASK 4 - 32%
bool isAWinner(std::string board);
bool isBWinner(std::string board);
bool boardFull(std::string board);
bool gameOver(std::string board);

// TASK 5 - 17%
bool checkAllRows(std::string board, char symbol);
bool checkAllCols(std::string board, char symbol);
bool upwardDiagonalCheck(std::string board, char symbol);
bool downwardDiagonalCheck(std::string board, char symbol);

#endif /*TICTACTOEHELPER_H*/