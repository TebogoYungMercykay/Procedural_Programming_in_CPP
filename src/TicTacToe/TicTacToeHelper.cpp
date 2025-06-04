#include "TicTacToeHelper.h"
#include <iostream>

std::string generateEmptyBoard() { return "         "; }

// TASK 1 - 25%

char getCell(std::string board, int cellIndex) { return board[cellIndex]; }

std::string makeMove(std::string board, int position, char symbol) {
  std::string newBoard = board;
  newBoard[position] = symbol;
  return newBoard;
}

std::string prettyPrint(std::string board) {
  std::string result = "";
  result += board[0];
  result += "|";
  result += board[1];
  result += "|";
  result += board[2];
  result += "\n";
  result += "-+-+-\n";
  result += board[3];
  result += "|";
  result += board[4];
  result += "|";
  result += board[5];
  result += "\n";
  result += "-+-+-\n";
  result += board[6];
  result += "|";
  result += board[7];
  result += "|";
  result += board[8];
  result += "\n";
  return result;
}

// TASK 2 - 12%

bool isValidMove(std::string board, int cell) {
  return (cell >= 0 && cell < 9 && board[cell] == ' ');
}

bool isInValidMove(std::string board, int cell) {
  return !isValidMove(board, cell);
}

bool isPlayerTurn(int turnCount, char symbol) {
  return (symbol == '0' && turnCount % 2 == 0) ||
         (symbol == '1' && turnCount % 2 == 1);
}

bool isPlayerATurn(int turnCount) { return turnCount % 2 == 0; }

bool isPlayerBTurn(int turnCount) { return turnCount % 2 == 1; }

// TASK 3 - 10%

bool rowCheck(std::string board, int row, char symbol) {
  int startIndex = row * 3;
  return (board[startIndex] == symbol && board[startIndex + 1] == symbol &&
          board[startIndex + 2] == symbol);
}

bool colCheck(std::string board, int col, char symbol) {
  return (board[col] == symbol && board[col + 3] == symbol &&
          board[col + 6] == symbol);
}

// TASK 4 - 32%

bool isAWinner(std::string board) {
  char symbol = '0';
  return checkAllRows(board, symbol) || checkAllCols(board, symbol) ||
         upwardDiagonalCheck(board, symbol) ||
         downwardDiagonalCheck(board, symbol);
}

bool isBWinner(std::string board) {
  char symbol = '1';
  return checkAllRows(board, symbol) || checkAllCols(board, symbol) ||
         upwardDiagonalCheck(board, symbol) ||
         downwardDiagonalCheck(board, symbol);
}

bool boardFull(std::string board) {
  return board[0] != ' ' && board[1] != ' ' && board[2] != ' ' &&
         board[3] != ' ' && board[4] != ' ' && board[5] != ' ' &&
         board[6] != ' ' && board[7] != ' ' && board[8] != ' ';
}

bool gameOver(std::string board) {
  return isAWinner(board) || isBWinner(board) || boardFull(board);
}

// TASK 5 - 17%

bool checkAllRows(std::string board, char symbol) {
  return rowCheck(board, 0, symbol) || rowCheck(board, 1, symbol) ||
         rowCheck(board, 2, symbol);
}

bool checkAllCols(std::string board, char symbol) {
  return colCheck(board, 0, symbol) || colCheck(board, 1, symbol) ||
         colCheck(board, 2, symbol);
}

bool upwardDiagonalCheck(std::string board, char symbol) {
  return (board[6] == symbol && board[4] == symbol && board[2] == symbol);
}

bool downwardDiagonalCheck(std::string board, char symbol) {
  return (board[0] == symbol && board[4] == symbol && board[8] == symbol);
}
