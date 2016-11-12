#include <iostream>

double sq(double x){
	x = x * x;
	return x;
}

double power(double x, int n){
	double y = 0;
	double z = 0;
	(n > 0) ? (n == 1) ? y = x : (n % 2 == 1) ? y = sq(x), y = x * y : y = sq(x) : y = x;
	(n > 0) ? (n == 1) ? n = n : (n % 2 == 1) ? n = n - 3 : n = n / 2 : n = n;
	(n > 0) ? (n == 1) ? z = y : (n % 2 == 1) ? z = sq(y), z = y * z : z = sq(y) : z = y;
	(n > 0) ? (n == 1) ? n = n : (n % 2 == 1) ? n = n - 3 : n = n / 2 : n = n;
	return z;
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