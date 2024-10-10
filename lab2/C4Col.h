#include "C4Board.h"
#include <iostream>
#ifndef C4COL_H
#define C4COL_H
class C4Col
{
private:
    int numDiscs;
    static const int maxDiscs = 6;
    char discs[maxDiscs];

public:
    C4Col();
    bool isFull();
    char getDisc(int col);
    int getmaxDiscs();
    void addDisc(char disc);

};
#endif 
