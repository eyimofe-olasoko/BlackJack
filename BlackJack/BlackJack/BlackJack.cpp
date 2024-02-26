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
	srand(time(0));

	vector<Cards> PlayerHand;

	
	
	Deck blackJackDeck = Deck();

	blackJackDeck.shuffle();

	cout << "" << endl;

	Cards FirstCard = blackJackDeck.cardDeck.back();
	blackJackDeck.cardDeck.pop_back();

	PlayerHand.push_back(FirstCard);

	//cout << "Player's first card: " << PlayerHand.back() << endl;
	//cout << "Player's second card: " << PlayerHand.back() << endl;

	int total = PlayerHand.back().getValue() + PlayerHand.front().getValue();


	
}

