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
	//Setting the seed of srand to 0 so a different number generates on each run of the game.
	srand(time(0));

	//Creating a vector to store all of the card in the player's hand
	vector<Cards> playerHand;
	vector<Cards> dealerHand;

	string hitOrStand;
	
	Deck blackJackDeck = Deck();

	//Shuffles card deck
	blackJackDeck.shuffle();

	//Gaining asset to the last value in the vector
	Cards firstCard = blackJackDeck.cardDeck.back();

	//Remove last element in the vector
	blackJackDeck.cardDeck.pop_back();

	Cards secondCard = blackJackDeck.cardDeck.back();

	blackJackDeck.cardDeck.pop_back();

	//Getting the first and second card for the player
	playerHand.push_back(firstCard);
	playerHand.push_back(secondCard);

	//Getting the first and second card for the dealer
	dealerHand.push_back(firstCard);
	dealerHand.push_back(secondCard);


	//
	int playerTotal = playerHand.back().getValue() + playerHand.front().getValue();
	int dealerTotal = dealerHand.back().getValue() + dealerHand.front().getValue();



	if (playerTotal == 21)
	{
		//BLACK JACK
	}
	else if (playerTotal < dealerTotal) {
		//LOST
	}


	if (hitOrStand == "Hit")
	{
		//Add card
	}
	else if (hitOrStand == "Stand") 
	{
		//Don't add card
	}


	






	
}

