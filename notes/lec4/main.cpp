/************************************************************************************/

// Program:  Simple battleship simulator

/************************************************************************************/

#include <iostream>    // for cout
#include <ctime>       // to seed the random number generator
#include <cstdlib>     // for srand
#include "board.h"     // board class

using namespace std;

int main () {

  bool res;          // result of adding a ship
  char col;          // column of ship
  int row, orient;   // row of ship and its orientation

  Board my_board;    // battleship board

  // initialize random number generator
  srand(time(NULL));
//
  cout << "Orientation: 0 = vertical; horizontal otherwise" << endl << endl;

  // display board
  my_board.printMine();

  // obtain position of carrier, looping until success
  do {

    cout << "Enter coordinates for carrier (col, row, orient):  ";  // input col, row, orientation
    cin >> col >> row >> orient;

    res = my_board.place_ship(col, row, orient, 5, 'C', true);   // attempt to place ship
    
  } while (res == false);

  // display board
  my_board.printMine();


  // obtain position of battleship, looping until success
  do {

    cout << "Enter coordinates for battleship (col, row, orient):  ";    // input col, row, orientation
    cin >> col >> row >> orient;

    res = my_board.place_ship(col, row, orient, 4, 'B', true);   // attempt to place ship
    
  } while (res == false);

  // display board
  my_board.printMine();


  // obtain position of cruiser, looping until success
  do {

    cout << "Enter coordinates for cruiser (col, row, orient):  ";      // input col, row, orientation
    cin >> col >> row >> orient;

    res = my_board.place_ship(col, row, orient, 3, 'R', true);    // attempt to place ship
    
  } while (res == false);


  // display board
  my_board.printMine();


  // obtain position of submarine, looping until success
  do {

    cout << "Enter coordinates for submarine (col, row, orient):  ";    // input col, row, orientation
    cin >> col >> row >> orient;

    res = my_board.place_ship(col, row, orient, 3, 'S', true);     // attempt to place ship
    
  } while (res == false);


   // display board
  my_board.printMine();


  // obtain position of destroyer, looping until success
  do {

    cout << "Enter coordinates for destroyer (col, row, orient):  ";
    cin >> col >> row >> orient;

    res = my_board.place_ship(col, row, orient, 2, 'D', true);  // attempt to place ship
    
  } while (res == false);

  // display board
  my_board.printMine();

  // choose untested spots at random, until all ships are sunk
  while (! my_board.amKaput() ) {   // test for defeat

    col = rand() % 10 + 'A';    // determine random col
    row = rand() % 10 + 1;      // determine random row

    // check to see if col, row space was tested
    if (! my_board.wasTested (col, row)) {

      cout << "Firing at " << col << " " << row << " ..." << endl;    // fire in the hole!
      my_board.fire(col, row, true);    // kaboom!
    
      // display statistics and the board after each term
      my_board.printStats();     
      my_board.printMine();

    }

  }

}

