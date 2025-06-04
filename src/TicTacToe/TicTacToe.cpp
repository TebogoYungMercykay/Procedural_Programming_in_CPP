#include "TicTacToe.h"

using namespace std;

int playGame() {
  cout << "GAME START NOW" << endl;
  string board = generateEmptyBoard();

  int turnCount = 0;

  while (!gameOver(board)) {
    cout << "Turn: " << turnCount << endl;
    int position = -1;
    char symbol = ' ';
    while (isInValidMove(board, position)) {
      if (isPlayerATurn(turnCount)) {
        symbol = '0';
      } else if (isPlayerBTurn(turnCount)) {
        symbol = '1';
      };
      position = askPlayerForPosition(board, symbol);
      if (isInValidMove(board, position)) {
        cout << "The provided position, " << position
             << ", is invalid for board: " << endl;
        cout << prettyPrint(board) << endl;
      }
    }
    board = makeMove(board, position, symbol);
    turnCount++;
  }

  if (isAWinner(board)) {
    cout << "Player A is the winner" << endl;
    return 0;
  } else if (isBWinner(board)) {
    cout << "Player B is the winner" << endl;
    return 1;
  } else if (boardFull(board)) {
    cout << "Game is a draw" << endl;
    return 2;
  } else {
    cout << "Unsure why game terminated" << endl;
    return -1;
  }
}

int askPlayerForPosition(string board, char symbol) {
  if (symbol == '0')
    cout << "Player A ";
  else if (symbol == '1')
    cout << "Player B ";
  else
    return -1;

  cout << "please give a position between 0 and 8 (inclusive) for board "
       << endl;
  cout << prettyPrint(board) << endl;

  int res = -1;
  cin >> res;
  return res;
}
