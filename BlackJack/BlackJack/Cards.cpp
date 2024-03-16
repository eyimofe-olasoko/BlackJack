#include "Cards.h"

Cards::Cards(string CardSuit, int CardValue) {

	suit = CardSuit;
	value = CardValue;

}

Cards::Cards() {

}


string Cards::getSuit() {
	return suit;
}

int Cards::getValue() {
	return value;
}

