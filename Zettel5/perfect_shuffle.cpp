#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<int> cards){
	for(int i = 0; i < cards.size(); ++i){						//I keep forgetting how to use for_each and how to force the terminal to use c++11
		int outInt = cards[i];
		cout << outInt;
	}
}

vector<int> init_deck(){
	vector<int> deck;
	for(int i = 0; i < 10; ++i){
		deck.push_back(i);
	}
	return deck;
}

bool check_deck(vector<int> cards){
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
	int maxI = 10;
	if(out){
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
	vector<int> shuffled_deck_in = shuffle(init_deck(), false);
	vector<int> shuffled_deck_out = shuffle(init_deck(), true);
	while(!check_deck(shuffled_deck_in)){
		shuffled_deck_in = shuffle(shuffled_deck_in, false);
		++counter_in;
		cout << "Counter in is at " << counter_in << endl;
	}
	cout << endl;
	while(!check_deck(shuffled_deck_out)){
		shuffled_deck_out = shuffle(shuffled_deck_out, true);
		++counter_out;
		cout << "Counter in is at " << counter_out << endl;
	}
	cout << "Counter in resulted in " << counter_in << ", Counter out resulted in " << counter_out;
	return 0;
}