#include <iostream>
#include <vector>
using namespace std;
class CardDeck {

public:
CardDeck(int cardeck = 52);
CardDeck(const CardDeck& other);
CardDeck& operator=(const CardDeck& other);
~CardDeck();


int getsize();
void shuffle();
bool deal(int playervalue, int dealervalue);
void play();


private:
int size;
vector<int> arr;

};
