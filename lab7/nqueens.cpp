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

int boardCounter = 0;

bool isvalid(vector<int> &board, int size, int row, int col)
{
  boardCounter++;
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = i + 1; j < board.size(); j++)
    {
      if (abs(i - j) == abs(board[i] - board[j]) || board[i] == board[j])
      {
        return false;
      }
    }
  }
 return true;
}
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
void nqueens(vector<int> &board, int row, int size)
{
  int col;
  if (row == size)
  {
    // isvalid(board, size, row, col);
    if (isvalid(board, size, row, col) == true)
    {
      print(board);
    }
  }
  else
  {
    for (int col = 0; col < size; col++)
    {
      board[row] = col;
      nqueens(board, row + 1, size);
    }
  }

  return;
}
int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  // cout << "what size you you want" << endl;
  // cin >> n;
  vector<int> board(n, -1);
  nqueens(board, 0, n);
  // cout << boardCounter;
  return 0;
}
