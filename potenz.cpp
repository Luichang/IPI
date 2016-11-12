#include <iostream>

double sq(double x){
	x = x * x;
	return x;
}

double power(double x, int n){
	int m = n;
	double y = 0;
	double z = 0;
	double result = 0;
	(n > 7) ? ((m % 2 == 0) ? y = sq(x) : y = sq(x), m = m / 2) : y = x;
	(n > 3) ? ((m % 2 == 0) ? z = sq(y) : z = sq(y), m = m / 2) : z = y;
	(m > 0) ? (m == 1) ? result = z : (m % 2 == 1) ? result = sq(z), result = x * result : result = sq(z) : result = z;
	return result;
}

int main(){
	std::string cont;
	while(cont != "no"){
		double x = 0;
		int n = 0;
		double result = 0;
		std::cout << "Please enter a value for x" << std::endl;
		std::cin >> x;
		std::cout << "Please enter the potenz of x" << std::endl;
		std::cin >> n;
		
		result = power(x, n);
		std::cout << "the answer provided was: " << result << std::endl;
		std::cout << "Would you like to enter another number? 'yes' to continue, 'no' to quit" << std::endl; 
		std::cin >> cont;							// annahme der break variable
	}
}