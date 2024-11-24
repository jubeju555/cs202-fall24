#include "CardDeck.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <algorithm>
#include <random>
#include <iterator>
using namespace std;
/*use the assignment Operator or the default constructor to deal the cards
then take copy constructor and copy what was dealt and maybe last card
then use destructor to delete memory and deal new cards
use copy constructor to keep the memory of the old cards and keep playing. */
// write the main constuctor 
CardDeck::CardDeck(int n) : size(n), Cards(n)
{
    for (int i = 0; i < n; i++)
    {
        Cards[i] = (i % 13) + 1;
    }
    shuffle();
}
// assignment operator
CardDeck &CardDeck::operator=(const CardDeck &copy)
{
    if (this != &copy)
    {
        size = copy.size;
        Cards = copy.Cards;
    }
    return *this;
}
// copy constructor
CardDeck::CardDeck(const CardDeck &arrayToCopy) : size(arrayToCopy.size), Cards(arrayToCopy.Cards)
{

}
// destructor
CardDeck::~CardDeck()
{
}

int CardDeck::getsize()
{
    return Cards.size();
}

// display shuffle
void CardDeck::printshuffle()
{
    int seed;
    cout << "Testing Shuffle... " << endl;
    cout << "please pick a seed number: ";
    cin >> seed;
    cout << endl;
    default_random_engine rng(seed);

    // Printing our array
    for (int i = 0; i < 9; i++)
    {
        cout << (Cards[i] % 10) << " ";
    }
    cout << endl;
    // i think i have to put std:: so that it doenst confuse it with calling its own function
    std::shuffle(Cards.begin(), Cards.end(), rng);
    for (int i = 0; i < 9; i++)
    {
        cout << (Cards[i] % 10) << " ";
    }
    cout << endl;
}

// game shuffle
void CardDeck::shuffle()
{
    int seed;
    default_random_engine rng(seed);
    // put std:: so that it doenst confuse it with calling its own function
    std::shuffle(Cards.begin(), Cards.end(), rng);
}
int CardDeck::dealcard()
{
    int card = Cards.back();
    Cards.pop_back();
    int value = (card % 13) + 1;
    if (value == 1)
    {
        value = 11;
    }
    if (value >= 11 && value <= 13)
    {
        value = 10;
    }
    cout << value << " ";
    return value;
}
// check win function
bool CardDeck::checkwin(int playervalue, int dealervalue)
{
    string game;

    if (playervalue > 21)
    {
        cout << "You bust!!" << endl;
        dealerwins++;
        return false;
    }
    if (playervalue == 21)
    {
        cout << "you win!!" << endl;
        playerwins++;
        return false;
    }
    if (dealervalue > 21)
    {
        cout << " Dealer busts, You Win!!!" << endl;
        playerwins++;
        return false;
    }

    if (dealervalue > 17)
    {
        return true;
    }

    return true;
}
int deck()
{
    int cardvalue[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 11};
    string cardface[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    size_t n = sizeof(cardface) / sizeof(cardvalue[0]);
    return 0;
}
// play function 
void CardDeck::play()
{
    string game, choice;
    int card, size;
    int playervalue = 0;
    int dealervalue = 0;
       cout << "Input deck size: (-1 for 52)" << endl;
        cin >> size;
    if (size == -1)
    {
        size = 52; 
    }
    this->size = size;  
    Cards.resize(size);

    while (true)
    {
        // print out a test of the deck shuffle
        printshuffle();
        cout << "End Test" << endl;
        cout << "Welcome to Black Jack" << endl;  
        
        cout << "Player wins: " << playerwins << endl;
        cout << "Dealer wins: " << dealerwins << endl;
        int playervalue = 0;
        int dealervalue = 0;
        shuffle();
        cout << "Your cards: ";
        playervalue += dealcard();
        playervalue += dealcard();
        cout << "\nThe house: ";
        dealervalue += dealcard();
        dealervalue += dealcard();
        cout << endl;

        while (true)
        {
            cout << " Hit or stand? " << endl;
            cin >> choice;
            if (choice == "hit")
            {
                playervalue += dealcard();
                cout << endl;
                cout << "You have: " << playervalue << endl;
            }
            else if (choice == "stand")
            {
                while (dealervalue < 17)
                {
                    dealervalue += dealcard();
                }

                cout << endl;
                cout << "The house has: " << dealervalue << endl;

                if (playervalue > dealervalue && playervalue <= 21)
                {
                    cout << " You Win !!!" << endl;
                    break;
                }
                if (playervalue < dealervalue && dealervalue <= 21)
                {
                    cout << "You Lose" << endl;
                    break;
                }
                if (playervalue == dealervalue)
                {
                    cout << " Its a tie" << endl;
                    break;
                }
                if (checkwin(playervalue, dealervalue) == false)
                {

                    break;
                }

            }
            if (checkwin(playervalue, dealervalue) == false)
            {
                break;
            }
        }
        cout << " Want to play another game ? (y/n) " << endl;
        cin >> game;
        if (game != "y")
        {
            break;
        }  
    }

}

void CardDeck::refill()
{
    Cards.clear();
    for (int i = 0; i < size; i++)
    {
        Cards.push_back((i % 13) + 1);
    }
    shuffle();
}