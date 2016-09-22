#include <iostream>
#include "card.h"
#include "deck.h"
#include "card_functions.h"
#include <vector>

using namespace std;


int main()
{
/*	Deck d;
	d.shuffle();
	vector<Card> h1;
	for(size_t i = 0; i < 5; i++)
	{
		h1.push_back(d.draw());
	}
	*/
	
	
	vector<Card> h1;
	h1.push_back(Card(Card::Hearts, Card::K));
	h1.push_back(Card(Card::Clubs, Card::K));
	h1.push_back(Card(Card::Spades, Card::K));
	h1.push_back(Card(Card::Hearts, Card::_10));
	h1.push_back(Card(Card::Diamonds, Card::Q));
	cout << get_hand_type(h1) << std::endl;
	
}
