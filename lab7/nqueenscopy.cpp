// Lab 7:  N-queens using backtracking
/*
judah benjamin
lab 7
sources:
w3school: how to write recursive funtion
google: #include for abs()

*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
long long boardCounter = 0;

void print(vector<int> &board)
{
  for (int i = 0; i < board.size(); i++)
  {
    cout << board[i];
    if (i < board.size() - 1)
    {
      cout << ", ";
    }
  }
  cout << endl;
}

bool isvalid(vector<int> &board, int size, int row )
{
  int col;
  boardCounter++;
  for (int r = 0; r < board.size(); r++)
  {
    int c = board[r];
    if (board[col] == board[r] && r != col)
    {
      return false;
    }

    if (abs(r - row) == abs(board[col] - board[r]) && r != col)
    {
      return false;
    }
  }
  print(board);
  return true;
}

void nqueens(vector<int> &board, int row, int size)
{
  if (row == size)
  {
    if (isvalid(board, size, row))
    {
      for (int col = 0; col < size - 1; col++)
    {
      print(board);
    }
      return;

    }
  }
  else
  {
    for (int i = 0; i < size; i++)
    {
      board[row] = i;
      nqueens(board, row + 1, size);
    }
  }
}

int main(int argc, char *argv[])
{
  // int n = atoi(argv[1]);
  // // cout << "what size you you want" << endl;
  // vector<int> board(n, -1);
  // nqueens(board, 0, n);
  // cout << boardCounter;
  // return 0;
  int n = 4;
  cout << "what size you you want" << endl;
  cin >> n;
  vector<int> board(n, -1);
  nqueens(board, 0, n);
  cout << boardCounter;
  return 0;
}
