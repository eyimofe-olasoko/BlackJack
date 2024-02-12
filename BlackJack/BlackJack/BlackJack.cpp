// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include "Cards.h"
#include <vector>
#include <random>
using namespace std;

int main()
{
	srand(time(0));

	Cards Cards0 = Cards("Diamond", 10);
	Cards Cards1 = Cards("Clubs", 4);

	

	vector<Cards> Deck;
	vector<Cards> PlayerHand;

	for (size_t item = 0; item < 13; item++)
	{
		Deck.push_back(Cards("Diamond", item));

		// Don't change the ACE in the loop probably
		//Deck[0] = Cards("Diamond", 1);
	}
	for (size_t item = 0; item < 13; item++)
	{
		Deck.push_back(Cards("Clubs", item));
	}
	for (size_t item = 0; item < 13; item++)
	{
		Deck.push_back(Cards("Hearts", item));
	}
	for (size_t item = 0; item < 13; item++)
	{
		Deck.push_back(Cards("Spades", item));
	}

	for (size_t item = 0; item < 52; item++)
	{
		cout << Deck[item].getSuit() << Deck[item].getValue() << endl;
	}
	
	random_shuffle(Deck.begin(), Deck.end());

	cout << "" << endl;

	Cards FirstCard = Deck.back();
	Deck.pop_back();

	PlayerHand.push_back(FirstCard);


	/*
	int ages[] = {1, 2, 5, 7, 3};
	int sum = 0;

	for (size_t item = 0; item < 5; item++)
	{
		cout << ages[item] << endl;

		sum += ages[item];
	}

	cout << "The sum of the your numbers: " << sum << endl;
	*/
}

