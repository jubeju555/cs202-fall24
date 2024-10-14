// Lab 7:  N-queens using backtracking
#include <iostream>
#include <vector>

using namespace std;

void nqueens(vector<int> &board, int col, int size)
{
}

bool isvalid(vector<int> &board, int size)
{

  return true;
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
}

int main(int argc, char *argv[])
{
  int n = 4;
  cout << "what size you you want" << endl;
  cin >> n;
  vector<int> board(n, -1);
  print(board);

  return 0;
}
