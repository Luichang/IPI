#include <iostream>

double sq(double x){
	x = x * x;
	return x;
}

double even(double x, int n){
	std::cout << "Even" << std::endl;
	x = sq(x);
	return x;
}

double odd(double x, int n){
	std::cout << "not woking yet" << std::endl;
	return x;
}

double power(double x, int n){
	std::cout << x << std::endl;
	(n > 0) ? (n == 1) ? x = x : (n % 2 == 1) ? x, n = odd(x, n) : x = even(x, n), n = n / 2 : x = x;
	std::cout << x << std::endl;
	(n > 0) ? (n == 1) ? x = x : (n % 2 == 1) ? x, n = odd(x, n) : x = even(x, n), n = n / 2 : x = x;
	std::cout << x << std::endl;
	(n > 0) ? (n == 1) ? x = x : (n % 2 == 1) ? x, n = odd(x, n) : x = even(x, n), n = n / 2 : x = x;
	std::cout << x << std::endl;
	return x;
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