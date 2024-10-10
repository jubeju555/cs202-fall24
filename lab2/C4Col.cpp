#include "C4Col.h"
#include "iostream"
#include "vector"
using namespace std;

C4Col::C4Col()
{
    int maxDiscs = 6;
    // char discs[maxDiscs] = {' '};
for (int i = 0; i < maxDiscs; i++)
{
    discs[i] = ' ';
}

}
// store and check discs 
char C4Col::getDisc(int row)
{     char person;  
    // cout << "get disc" << person << endl;

    if ((row < 0) || (row >= maxDiscs))
{
        cout << "Sorry that move is invalid, please try again!"<< endl;
        return ' ';
    }
    return discs[row];
}
// store max amount of discs in row 
int C4Col::getmaxDiscs()
{
    return maxDiscs;
}
// add the move just enterd onto the board
void C4Col::addDisc(char disc)
{
    // may have to change col back to row 
    // cout << "in add disc" << endl;    
    for (int col = 0; col < maxDiscs; col++)
    {   // issue here 
        // cout << " move added " << discs[col] << endl;

        if (discs[col] == ' ')
        {
            // cout << " in side add disc " << discs[col] << endl;

            discs[col] = disc;
            // cout << col << endl;
            return;
        } 

    }  
    cout << " Sorry this column is full " << endl; 
    
}
// limit the amount of discs in a column 
bool C4Col::isFull()
{
    // cout << "maxDiscs " << maxDiscs << endl;
    for (int i = 0; i < maxDiscs; i++)
    {
        // cout << "i = " << i << endl;
        if (discs[i] == ' ')
        {
            // cout << "in condition" << endl;
            return false;
        }
    }
    return true;
}