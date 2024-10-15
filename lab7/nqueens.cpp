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

bool isvalid(vector<int> &board, int size, int row, int col)
{

  for (int r, c : enumerate(board))
  {
    if (r == row || c == col || abs(r - row) == abs(c - col))
    {
      return false;
    }
    return true;
  }
}

void print(vector<int> &board)
{
  // int n = 4;
  // vector <int> & board(n, -1);
  //  cout << "what size you you want" << endl;
  //  while (cin >> n)
  //  {
  // board.push_back(n);
  //  }

  for (int i = 0; i < board.size(); i++)
  {
    cout << board[i] << " ";
  }
  cout << endl;
}
void nqueens(vector<int> &board, int col, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (col < size)
    {
      board[col] = i;
      if (isvalid(board, size))
      {
        nqueens(board, col + 1, size);
      }
      else if (col == size)
      {
        print(board);
      }
    }
  }
}
int main(int argc, char *argv[])
{
  int n = 4;
  vector<int> board(n, -1);
  cout << "what size you you want" << endl;
  int size = board.size();

  while (cin >> n)
  {
    board.push_back(n);
  }

  print(board);

  return 0;
}
