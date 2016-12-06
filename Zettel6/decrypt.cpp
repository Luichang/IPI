#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

template<typename K, typename V>		// K = KEy, V = Value, for the possible types to be entered
void printMap(const map<K, V> &m){		// &m ist die referenz, theoretisch kann man hierdurch m direkt verändern, obwohl es eine void funktion ist
	for(auto i:m){
		cout << i.first << " " << i.second << endl;
	}
}

map<char, int> initMap(string text){
	map<char, int> counts;
	for(int i = 'a'; i <= 'z'; ++i){	// char ist auch ein int based daten typ
		counts[i] = 0;
	}
	for(auto i:text){
		if(isalpha(i)){
			char lower;
			lower = tolower(i);
			++counts[lower];		// hier werden die Buchstaben jeweils gezählt
		}
	}
	return counts;
}

map<int, char> sortMap(map<char, int> inMap){
	map<int, char> outMap;
	for(auto i:inMap){
		outMap.insert(pair<int, char> (i.second, i.first));		// weil die map die einträge von .first automatisch sortiert, muss man nicht extra noch einen sortier algorythmus einfügen
	}
	return outMap;
}

map<char, char> decryptedMap(map<int, char> inMap, vector<char> letters){
	map<char, char> outMap;
	int j = 0;							// nicht ganz so schöne art 2 iteratoren zu haben, aber in einer for kann man keine 2 variablen iterieren lassen
	for(auto i:inMap){
		outMap.insert(pair<char, char> (i.second, letters[j]));
		outMap.insert(pair<char, char> (toupper(i.second), toupper(letters[j])));		// hier werden die großbuchstaben noch hinzu gefügt
		++j;
	}
	return outMap;
}

int main(){
	ifstream infile("encrypted_text.txt");
	string text;
	string line;
	while(infile){
		getline(infile, line);
		text += line + "\n";
	}
	map<char, int> counts = initMap(text);
	map<int, char> sorted = sortMap(counts);
	vector<char> letters = {'z', 'j', 'q', 'x', 'k', 'v', 'b', 'y', 'g', 'p', 'w', 'f', 'm', 'c', 'u', 'l', 'd', 'r', 'h', 's', 'n', 'i', 'o', 'a', 't', 'e'}; // hardcoding the letter sequence is so much fun
	map<char, char> decrypt = decryptedMap(sorted, letters);
	for(auto &i: text){		//das &i gibt die refferenz weiter, also kann das für den outpus decodiert werden
		if(isalpha(i)){
			i = decrypt.at(i);
		}
	}
	ofstream outfile("decrypted_text.txt");
	outfile << text;
}