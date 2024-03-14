// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include "Cards.h"
#include <vector>
#include <random>
#include "Deck.h"
using namespace std;

int main()
{

	int PlayerMoney = 1000;

	// Adding the player's and dealer's card totals
	int playerTotal;
	int dealerTotal;

	//Setting the seed of srand to 0 so a different number generates on each run of the game.
	srand(time(0));

	//Creating a vector to store all of the card in the player's hand
	vector<Cards> playerHand;
	vector<Cards> dealerHand;

	//Creating a variable to store the user's input 
	string hitOrStand;
	
	//Creating a deck object based on the deck class
	Deck blackJackDeck = Deck();

	//Shuffles card deck
	blackJackDeck.shuffle();

	//Gaining asset to the last value in the vector
	Cards playerFirstCard = blackJackDeck.cardDeck.back();
	//Remove last element in the vector
	blackJackDeck.cardDeck.pop_back();
	Cards playerSecondCard = blackJackDeck.cardDeck.back();
	blackJackDeck.cardDeck.pop_back();

	//Gaining asset to the last value in the vector
	Cards dealerFirstCard = blackJackDeck.cardDeck.back();
	//Remove last element in the vector
	blackJackDeck.cardDeck.pop_back();
	Cards dealerSecondCard = blackJackDeck.cardDeck.back();
	blackJackDeck.cardDeck.pop_back();



	//Getting the first and second card for the player
	playerHand.push_back(playerFirstCard);
	playerHand.push_back(playerSecondCard);

	//Getting the first and second card for the dealer
	dealerHand.push_back(dealerFirstCard);
	dealerHand.push_back(dealerSecondCard);

	//Displaying the player's card values and suits
	cout << "Your cards: " << endl;
	cout << playerHand.back().getValue() << " of " << playerHand.back().getSuit() << "'s" << endl;
	cout << playerHand.front().getValue() << " of " << playerHand.front().getSuit() << "'s" << endl;

	//Display the player's total card value from the two cards they pulled
	cout << "Your total is " << playerHand.back().getValue() + playerHand.front().getValue() << endl;

	cout << endl;

	//Displaying the dealer's card values and suits
	cout << "The dealers cards: " << endl;
	cout << dealerHand.back().getValue() << " of " << dealerHand.back().getSuit() << "'s" << endl;
	cout << dealerHand.front().getValue() << " of " << dealerHand.front().getSuit() << "'s" << endl;

	cout << "Your total is " << dealerHand.back().getValue() + dealerHand.front().getValue() << endl;

	
	do
	{
		cout << "Do you want to Hit or Stand? " << endl;
		cout << "Press (H) for Hit or (S) for stand: ";
		cin >> hitOrStand;

		if (hitOrStand != "H" || hitOrStand != "S")
		{
			cout << "Please enter (H) for Hit or (S) for stand" << endl;
		}

	} while (hitOrStand != "H" || hitOrStand != "S");
	





	//blackJackDeck.cardDeck.back();








	//cout << dealerHand.back().getSuit() << endl;
	//cout << dealerHand.front().getValue() << endl;



	//cout << "The dealer pulled a: " << dealerHand.back() << endl;







	//
	//int playerTotal = playerHand.back().getValue() + playerHand.front().getValue();
	//int dealerTotal = dealerHand.back().getValue() + dealerHand.front().getValue();




	// if (playerHand.getValue() == 1) { //change to an ace maybe}
	if (1 > 12)
	{
		//BLACK JACK
	}
	else if (1 > 2) {
		//LOST
	}
	//playerTotal < dealerTotal

	if (hitOrStand == "Hit")
	{
		//Add card
	}
	else if (hitOrStand == "Stand") 
	{
		//Don't add card
	}


	






	
}

