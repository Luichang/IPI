#include <iostream>

double sq(double x){
	return x * x;
}

double repeatTwice(double x, int n){
	double y;
	std::cout << "to test x = " << x << " n = " << n << std::endl;
	//(n % 2 == 0) ? y = sq(x), n = n/2 : (n == 1) ? y = x : y = x * x, n = n - 1;
	y = sq(x), n = n/2;
	std::cout << "y = " << y << std::endl;
	return y;
}

double power(double x, int n){
	double y;
	int m;
	y = repeatTwice(x, n);
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