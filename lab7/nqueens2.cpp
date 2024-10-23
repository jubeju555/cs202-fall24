// Lab 7:  N-queens using backtracking
/*
judah benjamin
lab 7
sources:
w3school: how to write recursive funtion
google: #include for abs()
stackoverflow: did the math my self on how abs would work for diagonals, then tried implementing. 
got inspiration from stack, nameing convention are similar, howver math and idea was completly mine
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int boardCounter = 0;
bool isvalid(vector<int> &board, int size, int row, int col)
{
  boardCounter++;
  // checks if current board is valid
  for (int r = 0; r < row; r++)
  {
    int c = board[r];

    if (r == row || c == col || abs(r - row) == abs(c - col))
    {
      return false;
    }
  }
  return true;
}
// prints out board
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
  // runs through board
  for (int col = 0; col < size; col++)
  {
    // checks if its valid
    if (isvalid(board, size, row, col))
    {
      // adds queen to column
      board[row] = col;
      //recursion 
      nqueens(board, row + 1, size);
    }
  }
// once the board is full, it prints it out 
  if (row == size)
  {
    print(board);
    return;
  }
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
