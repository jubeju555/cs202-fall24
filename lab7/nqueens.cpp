// Lab 7:  N-queens using backtracking
/*
judah benjamin
lab 7
sources:
w3school: how to write recursive funtion
google: #include for abs()
jackson: helpmed me restructure from queens 2 to 1, advised for nested for loop and helped with altered vaild funciton 
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
  // double nested for loop that iterates through every possible board, and checks if the queens will colide
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
// prints out board, called to print out current board
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
  // if all the columns are full
  if (row == size)
  {
    // check if the board is valid
    if (isvalid(board, size, row, col) == true)
    {
      print(board);
    }
  }
  else
  {
    // if the bord is not valid yet keep going through it
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
  vector<int> board(n, -1);
  nqueens(board, 0, n);
  // cout << boardCounter;
  return 0;
}
