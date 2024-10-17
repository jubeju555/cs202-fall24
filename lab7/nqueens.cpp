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
using namespace std;

long long boardCounter = 0;
void print(vector<int> &board)
{
  for (int i = 0; i < board.size(); i++)
  {
    cout << board[i];
    if (i < board.size() - 1)
    {
      cout << ",";
    }
  }
  cout << endl;
}
bool isvalid(vector<int> &board, int size, int row, int col)
{
  boardCounter++;
  for (int r = 0; r < row; r++)
  {
    int c = board[r];

    if (r == row || c == col || abs(r - row) == abs(c - col))
    {
      return false;
    }
      return true;
  }  
}

void nqueens(vector<int> &board, int row, int size)
{
  int col;
  if (row == size)
  {
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
      // print(board);
    }
  }
  return;
}
int main(int argc, char *argv[])
{
  int n = 4;
  cout << "what size you you want" << endl;
  cin >> n;
  vector<int> board(n, -1);
  nqueens(board, 0, n);
  cout << boardCounter;
  return 0;
}
