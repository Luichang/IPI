#include <iostream> 
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main (){    
    //Aufgabe 3a
    ifstream infile("encrypted_text.txt"); // Datei öffnen
    string text; // leerer String für den eingelesenen Text
    string line; // leerer String für die aktuelle Zeile
    while(infile){
        getline(infile, line); // nächste Zeile einlesen ...
        text += line + "\n"; // ... und an den Text anhängen
    }
    
    //Aufgabe 3b
	map <char, int> counts;  //3b
    for (char i = 97; i <= 122; ++i){   //den count aller Buchstaben auf 0 setzen 
        counts [i] = 0;                 // 97 - 'a' und 122 - 'z'
    }
    
    for(int iter = 0; iter < text.length(); ++iter) {
        char current = text[iter];
        if (isalpha(current)){
            current = tolower(text[iter]);      //damit 'A' und 'a' der gleiche Buchstabe ist
            ++counts[current];	
        }
    }
    
    //Aufgabe 3c
	map <int, char> sorted;  //3c
    for (char i = 97; i <= 122; ++i){   //schlüssel und wert von counts vertauschen
        sorted[counts[i]] = i;

    }
    vector<char> letters = {'z', 'j', 'q', 'x', 'k', 'v', 'b', 'y', 'g', 'p', 'w', 'f', 'm', 'c', 'u', 'l', 'd', 'r', 'h', 's', 'n', 'i', 'o', 'a', 't', 'e'};
	
	//Aufgabe 3d
	map <char, char> decrypt; //3d
	//for (int iter = 0; iter < sorted.size(); ++iter){   //letters den schlüsseln von sorted zuordnen --> schlüssel von decrypt sind die verschlüsselten Buchstaben
    int j = 0;
	for(auto i:sorted){
		decrypt[i.second] = letters[j];
		decrypt[toupper(i.second)] = toupper(letters[j]); //damit auch großbuchstaben ausgegeben werden 
		//cout << i.second << " " << decrypt[i.second] <<endl;
		++j;		
    }
	
	//Aufgabe 3e
	ofstream outFile("decrypted_text.txt");
	for(int iter = 0; iter < text.length(); ++iter) {
        if(isalpha(text[iter])){
			outFile << decrypt[text[iter]];
			//cout << decrypt[current];
		}else{
			outFile << text[iter];
		}
    }
}