#include "TicTacToe.h"
#include "TicTacToeHelper.h"
#include <iostream>

using namespace std;

void testBoardFunctions();
void testMoveValidation();
void testEdgeCases();

int main() {
  cout << "TicTacToe Test Suite" << endl;

  testMoveValidation();
  testBoardFunctions();
  testEdgeCases();

  return 0;
}

void testBoardFunctions() {
  string board = generateEmptyBoard();
  cout << "Empty board: " << prettyPrint(board) << endl;
  cout << "Cell: " << getCell(board, 1) << endl;

  board = makeMove(board, 0, '0');
  cout << "Board after move at position 0: " << prettyPrint(board) << endl;

  board = makeMove(board, 4, '1');
  cout << "Board after move at position 4: " << prettyPrint(board) << endl;
}

void testMoveValidation() {
  string board = "01 0 1   ";
  cout << "Move at position 2 valid: " << isValidMove(board, 2) << endl;
  cout << "Move at position 0 valid: " << isValidMove(board, 0) << endl;
  cout << "Move at position 0 Invalid: " << isInValidMove(board, 0) << endl;
  cout << "Turns: " << isPlayerATurn(3) << endl;
  cout << "Turns: " << isPlayerTurn(6, '0') << endl;
  cout << "Row Check: " << rowCheck(board, 0, '0') << endl;
  cout << "Col Check: " << colCheck(board, 0, '0') << endl;
  cout << "Winner Check: " << isAWinner(board) << endl;
  cout << "Winner Check: " << isBWinner(board) << endl;
  cout << "Board Full: " << boardFull(board) << endl;
}

void testEdgeCases() {
  string board = "01 0 1   ";
  cout << "isValidMove at position -1: " << isValidMove(board, -1) << endl;
  cout << "isValidMove at position 9: " << isValidMove(board, 9) << endl;

  string emptyBoard = "         ";
  cout << "gameOver(emptyBoard): " << gameOver(emptyBoard) << endl;

  string drawBoard = "010101010";
  cout << "gameOver(drawBoard): " << gameOver(drawBoard) << endl;

  string invalidBoard = "0123456789";
  cout << "Pretty print of invalid board:" << endl;
  cout << prettyPrint(invalidBoard);
  cout << "Row Check: " << checkAllRows(board, '0') << endl;
  cout << "Col Check: " << checkAllCols(board, '0') << endl;
  cout << "Up Check: " << upwardDiagonalCheck(board, '0') << endl;
  cout << "Down Check: " << downwardDiagonalCheck(board, '0') << endl;
}
