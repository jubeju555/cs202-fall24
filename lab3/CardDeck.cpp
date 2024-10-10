#include "CardDeck.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <algorithm>
using namespace std;

/*use the assignment oporatoir or the default constructor to deal the cards
then take copy constructor and copy what was dealt and maybe last card
then use destructor to delete memory and deal new cards
use copy constructor to keep the memory of the old cards and keep playing. */

CardDeck::CardDeck(int n) : arr(n)
{

    for (int i = 0; i < n; i++)

        arr[i] = i + 1;

    // {
    //     arr[i] = 52;
    // }
}
CardDeck::CardDeck( const CardDeck &arrayToCopy )  : size( arrayToCopy.size )  {

  arr = new int[size]; // create space for pointer-based array
  for ( int i = 0; i < size; i++ )
    arr[ i ] = arrayToCopy.arr[i]; // copy into object

}
CardDeck::~CardDeck()
{
    delete [] arr;
    // dont know what to put inside a destructor
}


void CardDeck::play()
{
    // print out a test of the deck shuffle
    cout << "Testing Shuffle... " << endl;
    // cout << cardface[12] << endl;
    shuffle();
    getsize();
}
int CardDeck::getsize()
{

    cout << arr.size() << endl;
    return 0;
}
int myrandom(int i)
{
    return rand() % i;
}

void CardDeck::shuffle()
{
    unsigned seed = 0;
    srand(seed);
    int count = 0;
    // Printing our array
    for (int card : arr)
    {
        if (count <= 10)
        {
            cout << card << " ";
            count++;
        }else
        {
            break;
        }
        
    }
    cout << endl;

    random_shuffle(arr.begin(), arr.end(), myrandom);

    count = 0; 
    for (int card : arr)
    {
        if (count <= 10)
        {
            cout << card << " ";
            count++;
        }else
        {
            break;
        }
        
    }
    cout << endl;
    // default_random_engine rng(seed);
    // cout << cardvalue[15] << endl;
    int cardvalue[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 11};
    char cardface[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A'};
    size_t n = sizeof(cardvalue) / sizeof(cardvalue[0]);
}

bool CardDeck::deal(int playervalue, int dealervalue)
{
    if (playervalue > 21)
    {
        cout << "You bust!!" << endl;
        return false;
    }
    if (dealervalue > 21)
    {
        cout << " Dealer busts, You Win!!!" << endl;
        return true;
    }
    return false;
}
int deck()
{

    char cardvalue[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 11};
    char cardface[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A'};
    return 0;
}