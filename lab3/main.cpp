/*  
Judah benjamin 
CS202 lab 3
sources: 
geeks4geeks: learning how to shuffle in c++
used notes for copy constructor and destructor
stackoverflow: "how to refill something in C++" pushback/popback
geeks4geeks: seg fault that i couldnt figure out
Office hours: formating and how to use the right type of shuffle
*/
void play(CardDeck *deck);

#include "CardDeck.h"   
int main() {
  // pointer to a single C4Board object
  CardDeck *deck = new CardDeck();
  play(deck);
  delete deck;
  return 0;
//   CardDeck deck;   
//     play(&deck);  
//     deck.play();
}

// play function needs to take in card deck pointer every method instide take in deck arrow then thing
void play(CardDeck *deck)
{
  
    string game, choice;
    int card;
    int playervalue = 0;
    int dealervalue = 0;
    while (true)
    {
      int size;
      int playerwins = 0;
    int dealerwins = 0;
        // print out a test of the deck shuffle
        deck->printshuffle();
        cout << "End Test" << endl;
        cout << "Welcome to Black Jack" << endl;
        cout << "Input deak size: (-1 for 52)" << endl;
        cin >> size;
        if (size == -1)
        {
            size = 52;
        }else
        {
          return;
        }
        deck->refill();
        deck->shuffle();
        cout << "Deck size: " << size << endl;
        cout << "Player wins: " << playerwins << endl;
        cout << "Dealer wins: " << dealerwins << endl;
        int playervalue = 0;
        int dealervalue = 0;
        deck->shuffle();
        cout << "Your cards: ";
        playervalue += deck->dealcard();
        playervalue += deck->dealcard();
        cout << "\nThe house: ";
        dealervalue += deck->dealcard();
        dealervalue += deck->dealcard();
        cout << endl;
        while (true)
        {
            cout << " Hit or stand? " << endl;
            cin >> choice;
            if (choice == "hit")
            {
                playervalue += deck->dealcard();
                cout << endl;
                cout << "You have: " << playervalue << endl;
            }
            else if (choice == "stand")
            {
                while (dealervalue < 17)
                {
                    dealervalue += deck->dealcard();
                }
                // checkwin(playervalue, dealervalue);
                cout << endl;
                cout << "The house has: " << dealervalue << endl;
                // checkwin(playervalue, dealervalue);
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
                if (deck->checkwin(playervalue, dealervalue) == false)
                {

                    break;
                }

            }
            if (deck->checkwin(playervalue, dealervalue) == false)
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
    if (deck->getsize() < 15)
    {
        delete deck;
        deck = new CardDeck();
        
        // delete &Cards;
        // // new Cards.size();
    }

}