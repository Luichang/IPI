/*#include <iostream>	
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector <string> split_words(string s)
{
    vector<string> v1;    
    v1.push_back(s);
    
    //s.find(" ");
    
    return v1;
}

int main () {
    string s = "Alpha";
	vector<string> b = split_words(s);
	for(int i = 0; i < b.size(); ++i){
		cout << b[i] << endl;
	}
    
    return 0;
}*/
#include <iostream>	
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector <string> findeLeerzeichen(string s){
    vector<string> Leerzeichen;
    
    int length = s.size();
    int pos = s.find(' ');
    int i;     
	string pickName;
    for(int i = 0; i < length; ++i){
		if(s[i] == ' '){
			Leerzeichen.push_back(pickName);			// sollte ein leerzeichen vorkommen, wird das wort in den vector eingefügt
			pickName = "";								// danach wird der string wieder resettet um keine doppelten zeichen zu übertragen
		}else{
			pickName += s[i];							// sollte der character kein leerzeichen sein wird er dem hilfs string angefügt
		}
	}
	Leerzeichen.push_back(pickName);					// hier wird das letzte wort auch noch hinzu gefügt, weil normalerweise der letzte character kein leerzeichen ist
    return Leerzeichen;
}

string randomizeWord(string s){
	//add some way to detect first and last character, make sure there are not multiple non alphabetic characters
	random_shuffle(s.begin(), s.end());
	return s;
}

vector <string> split_words(string s)					// diese funktion wurde übertragen aus dem was ich ursprünglich gezeigt bekommen habe
{
    vector<string> v1;    
    v1.push_back(s);
    
    //s.find(' ');
    
    return v1;
}

int main () {
    string s;
	cout << "Please enter a sentence" << endl;
	getline(cin, s);
    
    vector<string> c = findeLeerzeichen(s);
	vector<string> b = split_words(s);
    
	for(int i = 0; i < c.size(); ++i){					// hier wird jedes wort einzeln ausgespuckt
		c[i] = randomizeWord(c[i]);
		cout << c[i] << endl;
	}
    
    return 0;
}