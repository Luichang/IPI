#include <iostream>

using namespace std;
double sqt(double y){
	double x = y;
	while(fabs(x * x - y) > 10){
		cout << x << endl;
		x = x + (y - x * x) / (2 * x);
	}
}

double cbrt(double y){
	
}

int main(){
	
}