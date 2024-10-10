// Lab 1:  Tic-tac-toe solver (as requested by awesome grad TA grader Tom)
// Judah B
// tic tac toe
// checker that states who won in tic tac toe
// looked at stack overflow for how matrix couting works in tic tac toe and matched what a diagonal win would be (like connect the dots)
// question answered on piazza why prof emirch read in file using cin
// no ' ' needed on check tie (by someone in the programming clinic)
// for expanding parameters of game, was told to improve logic used to determine winner
// logic for checking win, if you simultaniously try to check all of them at the same time you might run into errors

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// int n = 3;
// char game[n][n];

// check to see who wins
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

bool checkwin(char **game, int n, char person)
{

  for (int i = 0; i < n; i++)
  {
    bool rwin = true;
    bool cwin = true;
    for (int j = 0; j < n; j++)
    {
      if (game[i][j] != person)
        rwin = false;
      if (game[j][i] != person)
        cwin = false;
    }

    if (rwin || cwin)
    {
      return true;
    }
  }
  bool diagwin = true;
  bool oppdiagwin = true;
  for (int i = 0; i < n; i++)
  {

    if (game[i][i] != person)
      diagwin = false;
    if (game[i][n - i - 1] != person)
      oppdiagwin = false;
  }
  if (diagwin || oppdiagwin)
  {
    return true;
  }

  return false;
  //     if ((game[0][i] == 'X' && game[1][i] == 'X' && game[2][i] == 'X') || (game[i][0] == 'X' && game[i][1] == 'X' && game[2][i] == 'X'))
  //     {
  //       return true;
  //     }
  //     if ((game[0][i] == 'O' && game[1][i] == 'O' && game[2][i] == 'O') || (game[i][0] == 'O' && game[i][1] == 'O' && game[2][i] == 'O'))
  //     {
  //       return true;
  //     }

  //     if ((game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X') || (game[0][2] == 'X' && game[1][1] == 'X' && game[2][0] == 'X'))
  //     {
  //       return true;
  //     }
  // if ((game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O'&& game[3][3] == 'O') || (game[0][2] == 'O' && game[1][1] == 'O' && game[2][0] == 'O'))
  //     {
  //       return true;
  //     }
}

int main()
{
  int n;
  cin >> n;

  char **game = new char *[n];
  for (int i = 0; i < n; i++)
  {
    game[i] = new char[n];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> game[i][j];
    }
  }
  // if (argc != 2)
  // {
  //   cerr << "usage" << argv[0] << " <input_file>" << endl;
  //   return 1;
  // }

  // ifstream inputfile(argv[1]);
  // if (!inputfile.is_open())
  // {
  //   cerr << "error unable to open file " << argv[1] << endl;
  //   return 1;
  // }

  // declare the result of the game

  bool xwins = checkwin(game, n, 'X');
  bool owins = checkwin(game, n, 'O');
  bool tie = !xwins && !owins && checktie(game, n);

  if (xwins)
  {
    cout << "X wins" << endl;
  }
  else if (owins)
  {
    cout << "O wins" << endl;
  }
  else if (tie)
  {
    cout << "Tie" << endl;
  }

  // use for loops to orgnaize grid

  // while (cin >> c)
  // {
  //   cin >> game[n][n];

  //   cout << game << endl;

  //   return 0;
  // }

  // inputfile.close();
  return 0;
}
