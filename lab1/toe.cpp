// Lab 1:  Tic-tac-toe solver
// judah benjamin
// tic tak toe lab
// a interactive tic tac toe game, that may increase in size
/*sites used for reasearch: stack overflow(set pair, found a post that reccomended sperating al lthe check win functions ), 
geeks for geeks: error checking
youtube: move checker logic was very close to the youtube video that was provided
chat gpt was used for syntax checking and learning how to use gdb for segmentation errors, after ria just told me to "figure it out" */ 

/*Notes from video: assume x goes first, keep a turn counter that increments every turn of the loop, use modulo to tell if turn is even or odd,
use set of pairs to track if move has been made before.
quesitons: how to determin bourndies, check if the move has been made before,
*/
/*got idea for seperating win conditions from TA, as well as using mod from youtube video
looked up how to include set pairs
confirmed method for move checking from friend 
kapildev - renamed a SIGNIFIGANT amount of variables to help him understand, explained process of resetting "streak" reseting. explained that it would keep resetting the win count.  
*/

#include <iostream>
#include <array>
#include <sstream>
#include <fstream>
#include <set>

using namespace std;
// print a formatted board out
void print_board(char **game, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << game[i][j] << " " ;
    }
    cout << endl;
  }
}
// check win/tie conditions,
bool checktie(char **game, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (game[i][j] == '-')
      {
        return false;
      }
    }
  }
  return true;
}

bool check_if_person_won(char **board, int board_size, char person)
{

  for (int row = 0; row < board_size; row++)
  {
    int streak = 0;
    for (int column = 0; column < board_size; column++)
    {
      if (board[row][column] == person)
        streak++;
      else
      {
        streak = 0;
      }
      if (streak == board_size)
      {
        return true;
      }
    }
  }

  for (int column = 0; column < board_size; column++)
  {
    int streak = 0;
    for (int row = 0; row < board_size; row++)
    {
      if (board[row][column] == person)
        streak++;
      else
      {
        streak = 0;
      }
      if (streak == board_size)
      {
        return true;
      }
    }
  }

  int streak = 0;
  for (int row = 0; row < board_size; row++)
  { 
    int column = row; 

    if (board[row][column] == person)
    {
      streak++;
    }
    else
    {
      streak = 0;
      
    }
    if (streak == board_size)
      {
        return true;
      }
  }

  streak = 0;
  for (int row = 0; row < board_size; row++)
  {  
    int column = board_size - row - 1;

    if (board[row][column] == person)
    {
      streak++;
    }
    else
    {
      streak = 0;
    }
    if (streak == board_size)
    {
      return true;
    }
  }
  return false;
}

// check for invalid or repeated moves
bool movechecker(int row, int col, int n, set<pair<int, int> > &pickedmoves)
{
  if (row < 0 || col < 0 || row >= n || col >= n)
  {
    cout << "Sorry that move is invalid, please try again!" << endl;
    return false;
  }
  if (pickedmoves.find(make_pair(row, col)) != pickedmoves.end())
  {
    cout << "Sorry this move has already been made!" << endl;
    return false;
  }
  return true;
}

int main()
{
  //  use the input for dimensions of game
  int i, n, j, row, col;
  double move;
  set<pair<int, int> > pickedmoves;
  cout << "Please enter board size: ";
  cin >> n;

  char **game = new char *[n];
  for (int i = 0; i < n; i++)
  {
    game[i] = new char[n];
    for (int j = 0; j < n; j++)
    {

      game[i][j] = '-';
    }
  }

  print_board(game, n);
  cout << "Enter your move in the following format X Y, the range is [0, Board size -1] then hit Enter" << endl;

  // use mod to keep track of turn, set X as first move
  int turn = 0;
  char person;
  while (true)
  {

    if (turn % 2 == 0)
    {
      person = 'X';
    }
    else
    {
      person = 'O';
    }
    cout << "Side " << person << " Enter your move" << endl;
    cin >> row >> col;

    if (!movechecker(row, col, n, pickedmoves))
    {
      continue;
    }
    game [row][col] = person;
    pickedmoves.insert(make_pair(row, col));
    print_board(game, n);

    if (check_if_person_won(game, n, person))
    {
      cout << person << "wins!!" << endl;
      break;
    }else if (checktie(game, n))
    {
      cout << "its a tie" << endl;
      break;
    }

    turn++;
  }

  return 0;
}
