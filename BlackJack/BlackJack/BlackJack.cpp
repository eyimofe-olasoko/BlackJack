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
	int playerTotal = 0;
	int dealerTotal = 0;

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

	
	bool changeValue;


	for (size_t item = 0; item < 2; item++)
	{
		//Setting the value of changeValue to false 
		changeValue = false;

		//Creating condition to check if the the card value conresponds with card name
		if (playerHand[item].getValue() == 1)
		{
			cout << "Ace" << " of " << playerHand.back().getSuit() << "'s" << endl;

			changeValue = true;
		}
		else if (playerHand[item].getValue() == 11)
		{
			cout << "Jack" << " of " << playerHand.back().getSuit() << "'s" << endl;

			changeValue = true;
		}
		else if (playerHand[item].getValue() == 12)
		{
			cout << "Queen" << " of " << playerHand.back().getSuit() << "'s" << endl;

			changeValue = true;
		}
		else if (playerHand[item].getValue() == 13)
		{
			cout << "King" << " of " << playerHand.back().getSuit() << "'s" << endl;

			changeValue = true;
		}

		//Checking if changeValue is false, as if it is then the the program will display the default card value without change the number to a name like "jack" or Ace
		if (changeValue == false)
		{
			cout << playerHand[item].getValue() << " of " << playerHand.front().getSuit() << "'s" << endl;
		}
		
	}

	//Display the player's total card value from the two cards they pulled
	playerTotal = playerHand.back().getValue() + playerHand.front().getValue();
	cout << "Your total is " << playerTotal << endl;

	cout << endl;

	//Displaying the dealer's card values and suits
	cout << "The dealers cards: " << endl;

	changeValue = false;

	//Creating condition to check if the the card value conresponds with card name
	if (dealerHand.back().getValue() == 1)
	{
		cout << "Ace" << " of " << playerHand.back().getSuit() << "'s" << endl;

		changeValue = true;
	}
	else if (dealerHand.back().getValue() == 11)
	{
		cout << "Jack" << " of " << playerHand.back().getSuit() << "'s" << endl;

		changeValue = true;
	}
	else if (dealerHand.back().getValue() == 12)
	{
		cout << "Queen" << " of " << playerHand.back().getSuit() << "'s" << endl;

		changeValue = true;
	}
	else if (dealerHand.back().getValue() == 13)
	{
		cout << "King" << " of " << playerHand.back().getSuit() << "'s" << endl;

		changeValue = true;
	}

	if (changeValue == false)
	{
		cout << dealerHand.back().getValue() << " of " << playerHand.front().getSuit() << "'s" << endl;
	}
	
	cout << "CARD CONCEALED" << endl;

	dealerTotal += dealerHand.back().getValue();// Add dealerHand.back.front().getValue() on later
	cout << "Your total is " << dealerTotal << endl;

	cout << endl;

	if (playerTotal == 21)
	{
		//player got a blackjack
	}


	//Creating a do while loop to make sure the player input is either (H) or (S)
	do
	{
		//Getting player input
		cout << "Do you want to Hit or Stand? " << endl;
		cout << "Press (H) for Hit or (S) for stand: ";
		cin >> hitOrStand;

		if (hitOrStand != "H" && hitOrStand != "S")
		{
			//Displaying a prompt to notify the player they entered a wrong input
			cout << "Please enter (H) for Hit or (S) for stand" << endl;
		}

		while (hitOrStand == "H")
		{
			//Adding another card from the card deck to the player's hand then adding the card number to player total
			playerHand.push_back(blackJackDeck.cardDeck.back());

			playerTotal += blackJackDeck.cardDeck.back().getValue();

			//Once the card has been added to the players total we can remove it from the deck
			blackJackDeck.cardDeck.pop_back();

			cout << playerTotal << endl;

			//Setting the value of hitOrStand to break out of the nested loop
			hitOrStand = "";

			//Checking if the player's total has exceeded 21, which would mean they went bust/lost
			if (playerTotal > 21)
			{
				cout << "Sorry! You went bust" << endl;

				cout << "Dealer Wins" << endl;

				//goto DisplayDealerHand;
			}
		}

	} while (hitOrStand != "H" && hitOrStand != "S");

	//DisplayDealerHand:

	do
	{


	} while (dealerTotal < 17);



	if (dealerTotal > playerTotal)
	{
		// loss
	}
	else if (dealerTotal == playerTotal)
	{
		// Draw
	}
	else 
	{
		//Win
	}

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

	


	






	


