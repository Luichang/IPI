#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;
double cbrt(double y){	// ich soll diese formel her leiten? Wie seh ich aus? Wie ein Mathematiker?
	double x = y/3;		// wenn man mir ein Program gibt was ähnlich funktioniert wie das was ich will nehme ich das und mach es zu dem was ich brauch...
	while(fabs(x * x * x - y) > 1e-15){	// hier habe ich eigentlich nur den code den wir im tutorium besprochen 
		x = (y + 2 * (x * x * x)) / (3 * x * x); // hatten umgewandelt in eine funktion die das mach was ich brauch
		//cout << x << endl;
	}
	return x;
}

int main(){
	double y;
	cout << "Please enter a number to have its cube root be pulled" << endl,  cin >> y;
	int cbrtAnswers[4];	// hier wird ein array declariert nur für die asserts, es ist int weil sonst mir das program sagt, dass 4 ungleich 4 ist
	int powAnswers[4];	// mir war die Toleranz zu blöd
	for(int i = 0;  i < 4; ++i){
		int j = i + 1;
		j = j * j;
		powAnswers[i] = pow(j, 1.0/3.0);
		cbrtAnswers[i] = cbrt(j);
		assert(powAnswers[i] == cbrtAnswers[i]);
	}
	assert(-cbrt(y) == cbrt(-y));
	cout << cbrt(y) << endl;
}