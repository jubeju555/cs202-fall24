#ifndef C4BOARD_H
#define C4BOARD_H
#include "C4Col.h"

class C4Board
{
private:

    int numCols;
    C4Col board[7];
     int lastMove;
    bool checkwin(char person);


public:
    C4Board();
    void display(char person); 
    void play();
    bool movechecker(int col);
    

    
};
#endif 