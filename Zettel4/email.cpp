#include <iostream>									// #kann man sich möglicherweise denken, aber wenn ein kommentar mit '#' anfängt wird 
#include <cctype>									// #er den Code NICHT erklären
using namespace std;

void breakCode(){									// #void ist so was schönes. Da muss man NICHTS ausgeben... was ein konzept... versteh ich auch kaum

	cout << "You entered an invalid email address."; // Funktion eingeführt sollte ich mehr als nur dem user sagen möchte das seine email falsch ist
	
}													// #was?? hier musste echt kein return? ich bin erstaunt

bool checkPeriod(string &s){
	bool Validated = true;
	int length = s.size();
	string::size_type position = 0;
	if(s.find('.') != string::npos){	// hier wird der erste und letzte character der "mail" gecheckt ob es ein punkt ist
	
		position = s.find('.');			// #da nicht gefordert wurde, dass zwischen jedem punkt mindestens ein erlaubtes zeichen ist
	}									// #suche ich nicht danach
	if(position == 0 && position == length - 1){
		Validated = false;
	} /*else {
		 cout << "it works" << endl;	diese zeile war ursprünglich zum testen
	}*/
	return Validated;	// #bool wird ausgegeben weil die Aufgabe UNBEDINGT ein bool hier möchte
}

bool checkChar(string &s, int start, int end){
	char c;
	char period = '.', underscore = '_', minus = '-';	// stellt sich heraus einzelne charakter muss man mit '' declarieren und darf sie nicht mit ""
	bool charIsValid = true;
	for (int i = start; i < end; ++i){
		c = s[i];										// arrays sind eine wunderbare erfindung mit der man so schöne Sachen machen kann
		if(isalnum(c)){

		} else {
			if(c == period){							// #so halb sinnvolle if's die man bestimmt mit mehr zeit investition entsorgen kann... zu faul

			} else if(c == underscore){					// #kennt man sicherlich

			} else if(c == minus){

			} else {
				charIsValid = false;
			}
		}
	}
	return charIsValid;									// #erneute bool ausgabe weil man ja eh nichts besseres zu tun hat
}

bool checkAt(string &s){
	bool dontWork = false;
	string::size_type position = 0;						// faszinierend das der int hier einen etra variabel Typ hat, fragt sich welche sprachen das 
	int length = s.size();								// mit dem size_type noch verwenden
	if(s.find('@') != string::npos){
		position = s.find('@');
	}
	if(position != 0){
		string preAt = s.substr(0, position);
		string postAt = s.substr(position + 1);			// hier wird + 1 gerechnet, damit man das '@' nicht noch mit im string hat
		if(checkChar(s, 0, position)){
			if(checkChar(s, position + 1, length)){
				if(checkPeriod(postAt)){
					if(checkPeriod(preAt)){				// #viel zu viele if's... weiterhin zu faul das zu verkürzen
						dontWork = true;
					}
				}
			}
		}
	}
	return dontWork;									// #was soll man denn noch alles returnen?
}

bool is_email(string &s){
	bool isEmail = true;								// hätte hier fast eine ausgabe vergessen... #die ist ja auch so wichtig
	int length = s.length();
	char c;
	int atLocation = 0;
	if(!checkAt(s)){
		isEmail = false;
	}
	return isEmail;
}

int main(){
	string s;
	cout << "Please enter an E-Mail you wish to validate:\n";
	getline(cin, s);
	if(!is_email(s)){
		breakCode();
	} else{
		cout << "You have entered a 'Valid' email address" << endl << endl << endl;
		cout << "* Please note, this program is mearly guidance and can not be held accountable " << endl; 	// hier benutze ich mehrere Zeilen, dass
		cout << "for if your email address actually is wrong." << endl;										// man in meinem n++ nicht scrollen muss
	}
}