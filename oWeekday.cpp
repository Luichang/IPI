#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cmath> 

template<typename T>
std::string to_string(const T& value)
{
    std::ostringstream stream;
    stream << value;
    return stream.str();
} //to string fix

int weekday2001(int d, int m, int y){
	int z, j1, p, schalt, w;
	std::string Tag;
	
	z = y - 2001;
	j1 = (365 * z + (z / 4) - (z / 100) + (z / 400)) % 7;
	//std::cout << "wd2001	j1: " << j1 << std::endl;
	(((y % 4) == 0 && (y % 100) != 0 ) || (y % 400) == 0 ) ? schalt = 1 
		:  schalt = 0;	
	//std::cout << "schalt: " << schalt << std::endl;
	(m == 1)? p = d  : 
		(m == 2)? p = d + 31 : 
			(m > 2 && schalt == 0)? p = d + 59 + ((153 * m - 457) / 5) : 
				(m > 2 && schalt == 1)? p = d + 60 + ((153 * m - 457) / 5)  :
					m = m;
	//std::cout << "wd2001	p: " << p << std::endl;
	w = (j1 + p - 1) % 7;
	//std::cout << "wd2001	w: " << w << std::endl;
	(w == 0)? Tag = "Montag" 
		: (w == 1)? Tag = "Dienstag"
			: (w == 2)? Tag = "Mittwoch"
				: (w == 3)? Tag = "Donnerstag"
					: (w == 4)? Tag = "Freitag"
						: (w == 5)? Tag = "Samstag"
							: (w == 6)? Tag = "Sonntag"
								: Tag = "Fehler";
	
	//std::cout << "Durch weekday2001: " << to_string(d) << "." << to_string(m) << "." << to_string(y)  << " war ein " << Tag << " \n";
}

int floorDiv(int a, int b){
	int test, r;
	int c = std::abs(b) - 1;
	test = a / b;
	(test > 0)? r = a / b
		: r = (-( std::abs(a) + c / std::abs(b))); 
	return r;
}
/* bei - (|a| + c) / |b| muss c in Abhängigkeit von a und b eigentlich 
c=a%b, wobei floorMod(a,b) verwendet wird, sein*/

int floorMod(int a, int b) {
	int r;
	r = a - floorDiv (a,b) * b;
}  
/*Wie unterscheidet sich floorMod () von der %-operation in c++? (aufgabe 2c)
	
*/

int weekday(int d, int m, int y){
	int z, j1, p, schalt, w, useless1, useless2, useless3, useless4;
	std::string Tag;
	
	z = y - 2001;
	useless1 = floorDiv(z, 4);
	std::cout << "wd	ul1: " << useless1 << std::endl;
	useless2 = floorDiv(z, 100);
	std::cout << "wd	ul2: " << useless2 << std::endl;
	useless3 = floorDiv(z, 400);
	std::cout << "wd	ul3: " << useless3 << std::endl;
	useless4 = (365 * z + useless1 - useless2 + useless3);
	std::cout << "wd	ul4: " << useless4 << std::endl;
	j1 = floorMod(useless4, 7) ;
	std::cout << "wd	j1: " << j1 << std::endl;
	(((y % 4) == 0 && (y % 100) != 0 ) || (y % 400) == 0 ) ? schalt = 1 
		:  schalt = 0;	  //funktioniert jedesmal nach dem schaltjahr komisch: vor schaltjahr richtig --> nach schaltjahr falsch --> nach nächstem schaltjahr wieder richtig
	std::cout << "schalt: " << schalt << std::endl;
	(m == 1)? p = d  : 
		(m == 2)? p = d + 31 : 
			(m > 2 && schalt == 0)? p = d + 59 + floorDiv((153 * m - 457), 5) : 
				(m > 2 && schalt == 1)? p = d + 60 + floorDiv((153 * m - 457), 5) :
					m = m;
	std::cout << "wd	p: " << p << std::endl;
	w = floorMod((j1 + p - 1), 7);
	std::cout << "wd	w: " << w << std::endl;
	(w == 0)? Tag = "Montag" 
		: (w == 1)? Tag = "Dienstag"
			: (w == 2)? Tag = "Mittwoch"
				: (w == 3)? Tag = "Donnerstag"
					: (w == 4)? Tag = "Freitag"
						: (w == 5)? Tag = "Samstag"
							: (w == 6)? Tag = "Sonntag"
								: Tag = "Fehler";
	
	std::cout << "Durch floor-Rechnung: " << to_string(d) << "." << to_string(m) << "." << to_string(y)  << " war ein " << Tag << " \n";
}

int weekday1(int d, int m, int y){
	int z, j1, p, schalt, w, useless1, useless2, useless3;
	std::string Tag;
	
	z = y - 1;
	useless1 = (z/4);
	std::cout << "wd0001	ul1: " << useless1 << std::endl; // habe mir nicht viele gedanken hierzu gemacht vonwegen warum es stimmt bzw nicht stimmt... müsste man noch machen
	useless2 = (z/100);
	std::cout << "wd0001	ul2: " << useless2 << std::endl;
	useless3 = (z/400);
	std::cout << "wd0001	ul3: " << useless3 << std::endl;
	j1 = (365 * z + useless1 - useless2 + useless3);
	//j1 = ( 365*z + (z/4) - (z/100) + (z/400) ) % 7;
	std::cout << "wd0001	j1: " << j1 << std::endl;
	( ( (y%4) == 0 && (y%100) != 0 ) || (y%400) == 0 ) ? schalt = 1 
		:  schalt =0;	
	std::cout << "schalt: " << schalt << std::endl;
	(m == 1)? p = d  : 
		(m == 2)? p = d + 31 : 
			(m > 2 && schalt == 0)? p = d + 59 + ((153*m - 457) / 5) : 
				(m > 2 && schalt == 1)? p = d + 60 + ((153*m - 457) / 5)  :
					m = m;
	std::cout << "wd0001	p: " << p << std::endl;
	w = (j1 + p -1) % 7;
	std::cout << "wd0001	w: " << w << std::endl;
	(w == 0)? Tag = "Montag" 
		: (w == 1)? Tag = "Dienstag"
			: (w == 2)? Tag = "Mittwoch"
				: (w == 3)? Tag = "Donnerstag"
					: (w == 4)? Tag = "Freitag"
						: (w == 5)? Tag = "Samstag"
							: (w == 6)? Tag = "Sonntag"
								: Tag = "Fehler";
	
	std::cout << "Durch weekday1: "<< to_string(d) << "." << to_string(m) << "." << to_string(y)  << " war ein " << Tag << " \n";
}

int main () {
	int d, m, y;
	std::cout << "Geben sie den Tag ein" << std::endl;
	std::cin >> d;
	std::cout << "Geben sie den Monat ein" << std::endl;
	std::cin >> m;
	std::cout << "Geben sie die Jahreszahl ein" << std::endl;
	std::cin >> y;
	//assert(y > 1583);
	weekday2001(d, m, y);
	weekday(d, m, y);
	weekday1(d, m, y);
}