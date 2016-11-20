#include <iostream>
#include <cctype>
using namespace std;
/* 
es darf nur 1 @ vorkommen
rechts von dem @muss mindestenz 1 punkts sein
links vom @ muss 1 eröaubtes zeichen vorkommen
zwischen @ und punkten muss ein zeichen vorkommen
nach dem punkt muss ein zeichen vorkommen
*/
void breakCode(){
	cout << "You entered an invalid email address.";
}

bool checkPeriod(string &s){
	bool Validated = true;
	int length = s.size();
	string::size_type position = 0;
	if(s.find('.') != string::npos){
		position = s.find('.');
	}
	if(position == 0 && position == length - 1){
		Validated = false;
	} else {
		cout << "it works" << endl;
	}
	return Validated;
}

bool checkChar(string &s, int start, int end){
	char c;
	char period = '.', underscore = '_', minus = '-';
	bool charIsValid = true;
	for (int i = start; i < end; ++i){
		c = s[i];
		if(isalnum(c)){

		} else {
			if(c == period){

			} else if(c == underscore){

			} else if(c == minus){

			} else {
				charIsValid = false;
			}
		}
	}
	return charIsValid;
}

bool checkAt(string &s){
	bool dontWork = false;
	string::size_type position = 0;
	int length = s.size();
	if(s.find('@') != string::npos){
		position = s.find('@');
	}
	if(position != 0){
		string preAt = s.substr(0, position);
		string postAt = s.substr(position + 1);
		if(checkChar(s, 0, position)){
			if(checkChar(s, position + 1, length)){
				if(checkPeriod(postAt)){
					if(checkPeriod(preAt)){
						dontWork = true;
					}
				}
			}
		}
	}
	return dontWork;
}

bool is_email(string &s){
	int length = s.length();
	char c;
	int atLocation = 0;
	if(!checkAt(s)){
		breakCode();
	}
}

int main(){
	string s;
	cout << "Please enter an E-Mail you wish to validate:\n";
	getline(cin, s);
	is_email(s);
}