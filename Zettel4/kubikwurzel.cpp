#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;
double cbrt(double y){	// ich soll diese formel her leiten? Wie seh ich aus? Wie ein Mathematiker?
	double x = y/3;		// wenn man mir ein Program gibt was ähnlich funktioniert wie das was ich will nehme ich das und mach es zu dem was ich brauch...
	while(fabs(x * x * x - y) > 1e-15){
		x = x/*sollte hier nicht x hoch 2 oder so sein? O.o*/ + (y - x * x * x) / (3 * x * x);
		//cout << x << endl;
	}
	return x;
}

int main(){
	cout << "Please enter a number to have its cube root be pulled" << endl;
	double y;
	cin >> y;
	assert(pow(8, 1.0/3.0) == cbrt(8));
	assert(pow(27, 1.0/3.0) == cbrt(27));
	//assert(pow(64, 1.0/3.0) == cbrt(64));
	cout << "testing 0 = false 1 = true: " << (pow(64, 1.0/3.0) == cbrt(64)) << " " << pow(64, 1.0/3.0) << " " << cbrt(64) << endl;
	//assert(pow(125, 1.0/3.0) == cbrt(125));
	assert(-cbrt(y) == cbrt(-y));
	//cout << cbrt(y) << endl;
}