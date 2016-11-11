#include <iostream>

double sq(double x){
	return x * x;
}

double repeatTwice(double x, int n){
	double y;
	(n % 2 == 0) ? y = sq(x) : (n == 1) ? y = x : y = x * x;
	return y;
}

double power(double x, int n){
	double y;
	int m;
	(n % 2 == 0) ? y = repeatTwice(x, n), n = n/2 : (n == 1) ? y = x : y = repeatTwice(x, n), n = n - 1;
	std::cout << "to test x = " << x << " y = " << y << " and m = " << m << std::endl;
	(n != 1) ? y = repeatTwice(y, m) : y = y;
	return y;
}

int main(){
	std::string cont;
	while(cont != "no"){
		double x;
		int n;
		double result;
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