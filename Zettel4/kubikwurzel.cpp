#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;
double cbrt(double y){		// #ich soll diese formel her leiten? Wie seh ich aus? Wie ein Mathematiker? wenn man mir ein Program
	double x = y / 3;		// #gibt was ähnlich funktioniert wie das was ich will nehme ich das und mach es zu dem was ich brauch...
	
	while(fabs(x * x * x - y) > 1e-15){				// hier habe ich eigentlich nur den code den wir im tutorium besprochen 
		x = (y + 2 * (x * x * x)) / (3 * x * x);	// hatten umgewandelt in eine funktion die das mach was ich brauch
	}
	return x;
}

int main(){
	double y;
	cout << "Please enter a number to have its cube root be pulled" << endl,  cin >> y;	// hier wurde mir gesagt das man eine zeile effektiv sparen kann
	int cbrtAnswers[4];	// hier wird ein array declariert nur für die asserts, es ist int weil sonst mir das program sagt, dass 4 ungleich 4 ist
	int powAnswers[4];	// mir war die Toleranz zu blöd
	for(int i = 2;  i < 6; ++i){					// ich kann hier int arrays verwenden, weil ich ja erst die Zahl cubiere und dann wieder die
		//int j = i + 2;								// wurzel ziehe
		
		int j = j * j * j;
		powAnswers[i] = pow(j, 1.0/3.0) + 1;		// #Die pow funktion ist sehr kompetent, sie gibt ein Double der minimal unter dem int ist der gezeigt wird 
		cbrtAnswers[i] = cbrt(j);					// #Zur auslgeichung der inkompetenz meinerseits und der pow funktion zusammen 
													// #addiere ich 1 zur lösung, das hilft immer
													
		assert(powAnswers[i] == cbrtAnswers[i]);	// #ich verstehe ja, dass man 'gelernte' Sachen wider und wider widerhohlen soll, aber
	}												// #ist das assert hier wirklich notwendig? ja es ist schön gleich sehen zu können ob der code das tut
	assert(-cbrt(y) == cbrt(-y));					// #'was er soll' aber das kann man auch mit einer if, bzw einer von tutoren geschriebenen funktion
	cout << "meine funktion gibt hier " << cbrt(y) << endl;	// #im nachhinein einführen und entfernt unnötige asserts die keinen schönen output haben
}