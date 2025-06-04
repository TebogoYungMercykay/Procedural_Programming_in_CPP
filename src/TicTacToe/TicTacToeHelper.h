#ifndef TICTACTOEHELPER_H
#define TICTACTOEHELPER_H

#include <string>

std::string generateEmptyBoard();

char getCell(std::string board, int cellIndex);
std::string makeMove(std::string board, int position, char symbol);
std::string prettyPrint(std::string board);

bool isValidMove(std::string board, int cell);
bool isInValidMove(std::string board, int cell);
bool isPlayerTurn(int turnCount, char symbol);
bool isPlayerATurn(int turnCount);
bool isPlayerBTurn(int turnCount);

bool rowCheck(std::string board, int row, char symbol);
bool colCheck(std::string board, int col, char symbol);

bool isAWinner(std::string board);
bool isBWinner(std::string board);
bool boardFull(std::string board);
bool gameOver(std::string board);

bool checkAllRows(std::string board, char symbol);
bool checkAllCols(std::string board, char symbol);
bool upwardDiagonalCheck(std::string board, char symbol);
bool downwardDiagonalCheck(std::string board, char symbol);

#endif /*TICTACTOEHELPER_H*/