#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<int> cards){
	for(int i = 0; i < cards.size(); ++i){						//I keep forgetting how to use for_each and how to force the terminal to use c++11
		int outInt = cards[i];
		cout << outInt;
	}
}

vector<int> init_deck(){										// not sure if this is the most self explanatory function ever or what
	vector<int> deck;											// but it initialises the deck of cards
	for(int i = 0; i < 52; ++i){
		deck.push_back(i);
	}
	return deck;
}

bool check_deck(vector<int> cards){								// this just wants to check if the cards are back to a non shuffled state
	if(cards == init_deck()){
		return true;
	}else{
		return false;
	}
}

vector<int> shuffle(vector<int> cards, bool out){		// out seems like not the best variable choice, could mean output...
	vector<int> new_deck;
	//displayVector(cards);
	int counter = 0;
	int maxI = 52;		// at one point I was having huge problems with the vector getting messed up so I just added 
	if(out){			// this variable to try and stop it from not working
		for(int i = 0; i < maxI; ++i){
			if(i % 2 == 0){
				new_deck.push_back(cards[counter]);
			}else{
				new_deck.push_back(cards[counter + (maxI / 2)]);
				++counter;
			}
		}
		//cout << endl;
	}else{
		for(int i = 0; i < maxI; ++i){
			if(i % 2 != 0){
				new_deck.push_back(cards[counter]);
				++counter;
			}else{
				new_deck.push_back(cards[counter + (maxI / 2)]);
			}
		}
		//cout << endl;
	}
	//displayVector(new_deck);
	return new_deck;
}

int main(){
	int counter_in = 0;
	int counter_out = 0;
	vector<int> shuffled_deck_in = shuffle(init_deck(), false);		// the dumbest thing that can happen to you is if you are copying working
	vector<int> shuffled_deck_out = shuffle(init_deck(), true);		// code and use it for something new, and only change half the variable names
	while(!check_deck(shuffled_deck_in)){
		shuffled_deck_in = shuffle(shuffled_deck_in, false);
		++counter_in;
		cout << "Counter in is at " << counter_in << endl;
	}
	cout << endl;
	while(!check_deck(shuffled_deck_out)){							// took me far too long to realize I had the .._in variable name here
		shuffled_deck_out = shuffle(shuffled_deck_out, true);		// remember kods, always check your variable names before saying your code won't work
		++counter_out;
		cout << "Counter in is at " << counter_out << endl;
	}
	cout << "Counter in resulted in " << counter_in << ", Counter out resulted in " << counter_out;
	return 0;
}