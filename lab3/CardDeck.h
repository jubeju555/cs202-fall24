#ifndef CARDDECK_H
#define CARDDECK_H
#include <iostream>
#include <vector>
using namespace std;
class CardDeck {

public:
CardDeck(int CardDeck = 52);
CardDeck(const CardDeck& other);
CardDeck& operator=(const CardDeck& other);
~CardDeck();

void play();
int getsize();
void shuffle();
void printshuffle();
bool checkwin(int playervalue, int dealervalue);
void refill();
int dealcard();

private:
int size;
vector<int> Cards;
int playerwins = 0;
int dealerwins = 0;

};
#endif