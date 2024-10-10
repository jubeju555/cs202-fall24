#include "C4Col.h"
#include <iostream>
#include <cstdio>
using namespace std;
C4Board::C4Board()
{
  numCols = 7;   
  lastMove = -1; 

  // Initialize each column as an array instead of 2d array 
  for (int i = 0; i < numCols; i++)
  {
    board[i] = C4Col();
  }
}
// write the interactive part of the program 
void C4Board::play()
{
  int turn = 0;
  char person;

  // turn counter
  while (true)
  {
    display(person);
    int col = 0;
    int row = 0;
    int move;
    cout << "Turn " << turn << endl;
    if (turn % 2 == 0)
    {
      person = 'X';
    }
    else
    {
      person = 'O';
    }

    cout << "Side " << person << " Enter your move (0 - 6)" << endl;
    cin >> move;

    // cout << "col " << col << endl;
    if (movechecker(move))
    {
      board[move].addDisc(person);
      lastMove = move;
    }

    if (checkwin(person))
    {
      cout << person << " wins!!" << endl;
      break;
    }

    // tie / and exit 
    if (turn == 42)
    {
      cout << " its a tie ";
      break;
    }
    if (move == -1)
    {
      break;
    }

    turn++;
  }
}
// display the board both before and after move
void C4Board::display(char person)
{
  int numCols = 7;
  int numRows = board[0].getmaxDiscs();
 
  for (int row = numRows - 1; row >= 0; row--)
  {
    for (int col = 0; col < numCols; col++)
    {
      cout << " | " << board[col].getDisc(row);
    }
    cout << endl;
  }
  cout << " ";
  for (int col = 0; col < numCols; col++)
  {
    cout << "  " << col << " ";
  }
  cout << endl;
}
// check if moves are valid
bool C4Board::movechecker(int col)
{
  if (col < 0 || col >= 7)
  {
    cout << "Sorry that move is invalid, please try again!" << endl;
    return false;
  }
  if (board[col].isFull())
  {
    cout << "Sorry this column is full " << endl;
    return false;
  }
  return true;
}

bool C4Board::checkwin(char person)
{
  const int rows = 6;
  const int cols = 7;

  // row check
  for (int row = 0; row < rows; row++)
  {
    int streak = 0;
    for (int col = 0; col < cols; col++)
    {
      if (board[col].getDisc(row) == person)
      {
        streak++;
      }
      else
      {
        streak = 0;
      }

      if (streak == 4)
      {
        return true;
      }
    }
  }

  // col check
  for (int col = 0; col < cols; col++)
  {
    int streak = 0;
    for (int row = 0; row < rows; row++)
    {
      if (board[col].getDisc(row) == person)
      {
        streak++;
      }
      else
      {
        streak = 0;
      }

      if (streak == 4)
      {
        return true;
      }
    }
  }

  // the second comments are for me, i have notes somewhere explaining the logic to myself. 

  // diag (bot left - top right)
  // (note) for this diag vs the last program i subtracted one for it to go up and added one to goe right
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      int streak = 0;
      for (int adjustment = 0; adjustment < 4; adjustment++)
      {
        int r = row - adjustment;
        int c = col + adjustment;

        if (r >= 0 && c < cols && board[c].getDisc(r) == person)
        {
          streak++;
        }
        else
        {
          break;
        }

        if (streak == 4)
        {
          return true;
        }
      }
    }
  }

  // opp diag check ( bot right - top left)
  /*(note) for this diag i drew it out since its not the same as the last, subtract to both go up and to the left
  */ 
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      int streak = 0;
      for (int adjustment = 0; adjustment < 4; adjustment++)
      {
        int r = row - adjustment;
        int c = col - adjustment;

        if (r >= 0 && c >= 0 && board[c].getDisc(r) == person)
        {
          streak++;
        }
        else
        {
          break;
        }
        if (streak == 4)
        {
          return true;
        }
      }
    }
  }

  return false;
}