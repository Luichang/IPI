#include <iostream>
#include <cmath>

using namespace std;
double cbrt(double y){
	double x = y;
	while(fabs(x * x * x - y) > 1e-10){
		cout << x << endl;
		x = x/*sollte hier nicht x hoch 2 oder so sein? O.o*/ + (y - x * x * x) / (3 * x * x);
	}
	return x;
}

int main(){
	cout << cbrt(-27) << endl;
}