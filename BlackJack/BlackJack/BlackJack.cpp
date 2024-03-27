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
	//Creating a boolean variable to see if the card value need to be changed
	bool changeValue = false;

	//Creating a bool is track if the player went bust
	bool wentBust = false;

	//Creating a bool is track if the dealer got an ace
	bool isAce = false;

	//Creating a variable to see if a blackjack is achieved
	bool isBlackJack = false;

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

	//Getting the first and second card for the player
	playerHand.push_back(playerFirstCard);
	playerHand.push_back(playerSecondCard);

	//Getting the first for the dealer
	dealerHand.push_back(dealerFirstCard);

	//Displaying the player's card values and suits
	cout << "Your cards: " << endl;

	for (size_t item = 0; item < 2; item++)
	{
		//Creating condition to check if the the card value conresponds with card name
		if (playerHand[item].getValue() == 1)
		{
			cout << "Ace" << " of " << playerHand.back().getSuit() << "'s" << endl;

			changeValue = true;
		}
		else if (playerHand[item].getValue() == 11)
		{
			cout << "Jack" << " of " << playerHand.back().getSuit() << "'s" << endl;

			//Setting the value of the card to 10 because in blackjack anything above a ten is also worth ten.
			playerHand[item].setValue(10);

			changeValue = true;
		}
		else if (playerHand[item].getValue() == 12)
		{
			cout << "Queen" << " of " << playerHand.back().getSuit() << "'s" << endl;

			playerHand[item].setValue(10);

			changeValue = true;
		}
		else if (playerHand[item].getValue() == 13)
		{
			cout << "King" << " of " << playerHand.back().getSuit() << "'s" << endl;

			playerHand[item].setValue(10);

			changeValue = true;
		}
		else if (playerHand[item].getValue() == 0)
		{
			playerHand[item].setValue(1);

			cout << "Ace" << " of " << playerHand.back().getSuit() << "'s" << endl;

			changeValue = true;
		}

		//Checking if changeValue is false, as if it is then the the program will display the default card value without change the number to a name like "jack" or Ace
		if (changeValue == false)
		{
			cout << playerHand[item].getValue() << " of " << playerHand.front().getSuit() << "'s" << endl;
		}

		//Changing the value of changeValue to false 
		changeValue = false;

	}

	//Setting the Ace card to 11 if the player has also pulled a 10 so they can get a blackjack
	if (playerHand.back().getValue() == 1 && playerHand.front().getValue() == 10)
	{
		playerHand.back().setValue(11);

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

		dealerHand.back().setValue(10);

		changeValue = true;
	}
	else if (dealerHand.back().getValue() == 12)
	{
		cout << "Queen" << " of " << playerHand.back().getSuit() << "'s" << endl;

		dealerHand.back().setValue(10);

		changeValue = true;
	}
	else if (dealerHand.back().getValue() == 13)
	{
		cout << "King" << " of " << playerHand.back().getSuit() << "'s" << endl;

		dealerHand.back().setValue(10);

		changeValue = true;
	}
	else if (dealerHand.back().getValue() == 0)
	{
		dealerHand.back().setValue(1);

		cout << "Ace" << " of " << playerHand.back().getSuit() << "'s" << endl;

		changeValue = true;
	}

	if (changeValue == false)
	{
		cout << dealerHand.back().getValue() << " of " << playerHand.front().getSuit() << "'s" << endl;
	}


	dealerTotal = dealerHand.back().getValue();

	cout << "Your total is " << dealerTotal << endl;

	cout << endl;

	//Checking if the dealer got an ace then setting isAce to true
	if (dealerHand.back().getValue() == 1)
	{
		isAce = true;
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

			//Making sure that if the player gets a Jack, Queen, King to 10 and an Ace to a 1
			if (playerHand.back().getValue() == 11)
			{
				playerHand.back().setValue(10);
			}
			else if (playerHand.back().getValue() == 12)
			{
				playerHand.back().setValue(10);
			}
			else if (playerHand.back().getValue() == 13)
			{
				playerHand.back().setValue(10);
			}
			else if (playerHand.back().getValue() == 0)
			{
				playerHand.back().setValue(1);
			}

			//Adding the value of the card the player pulled to the player total
			playerTotal += playerHand.back().getValue();

			//Once the card has been added to the players total we can remove it from the deck
			blackJackDeck.cardDeck.pop_back();

			cout << "You new total is: " << playerTotal << endl;

			//Setting the value of hitOrStand to break out of the nested loop
			hitOrStand = "";

			//Checking if the player's total has exceeded 21, which would mean they went bust/lost
			if (playerTotal > 21)
			{
				cout << "Dealer Wins" << endl;

				wentBust = true;

				//Breaking out of the nested loop
				goto Break;
			}
		}

	} while (hitOrStand != "H" && hitOrStand != "S");

	//Creating a while to add cards to the dealers hand as long as the total is below 17
	while (dealerTotal <= 17)
	{
		dealerHand.push_back(blackJackDeck.cardDeck.back());

		if (dealerHand.back().getValue() == 11)
		{
			dealerHand.back().setValue(10);
		}
		else if (dealerHand.back().getValue() == 12)
		{
			dealerHand.back().setValue(10);
		}
		else if (dealerHand.back().getValue() == 13)
		{
			dealerHand.back().setValue(10);
		}
		else if (dealerHand.back().getValue() == 0)
		{
			dealerHand.back().setValue(1);
		}


		//Checking if the player got and Ace and a 10 
		if (isAce == true && dealerHand.back().getValue() == 10)
		{

			isBlackJack = true;

			//Setting Ace the player pulled value's to an 11 as they got a blackjack
			dealerHand.front().setValue(11);

			//Changing the dealer total is the new value
			dealerTotal = dealerHand.front().getValue();

			dealerTotal += dealerHand.back().getValue();

			cout << "Dealer's total is: " << dealerTotal << endl;

			cout << "Dealer got a blackjack" << endl;

			break;
		}

		dealerTotal += dealerHand.back().getValue();

		cout << "Dealer's total is: " << dealerTotal << endl;

		blackJackDeck.cardDeck.pop_back();

		//Checking if the dealer when bust/if the dealer got a higher total than the player
		if (dealerTotal > 21)
		{
			cout << "You win! Dealer went bust!" << endl;
			break;
		}
		//Checking if the dealer's total is greater than the player's
		else if (dealerTotal > playerTotal)
		{
			cout << "Dealer beats player" << endl;
			break;
		}
		//Checking if the player and dealer have drawn
		else if (dealerTotal == playerTotal)
		{
			cout << "It's a draw!!" << endl;
			break;
		}
	}

	Break:

	//Checking if the dealer got a blackjack and they also have a greater total than the player
	if (isBlackJack == true && dealerTotal > playerTotal)
	{
		cout << "You lose!" << endl;
	}
	//Checking if the player got a black jack and they drew with the player
	else if (isBlackJack == true && dealerTotal == playerTotal)
	{
		cout << "You drew with the dealer" << endl;
	}
	//Checking if the player went bust
	else if (wentBust == true)
	{
		cout << "You went bust!!" << endl;
	}
	//Checking if the player got a higher total than the dealer
	else if (playerTotal > dealerTotal)
	{
		cout << "You win!!" << endl;
	}
}


	






	


