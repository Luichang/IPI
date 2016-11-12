#include <iostream>

double sq(double x){
	x = x * x;
	return x;
}

double even(double x, int n){
	//std::cout << "Even" << std::endl;
	x = sq(x);
	return x;
}

bool oddNumber;

double odd(double x, int n){
	//std::cout << "Odd" << std::endl;
	x = even(x, n);
	oddNumber = true;
	return x;
}

double power(double x, int n){ // this works for every n between 1 and 8 except for n = 6 and n = 7
	oddNumber = false;
	double y = x;
	int m = n;
	//int test = 0;
	(n > 0) ? (n == 1) ? x = x/*, test = test + 1*/ : (n % 2 == 1) ? x = odd(x, n)/*, test = test + 2*/, m = n - 1 : x = even(x, n), m = n / 2/*, test = test + 4*/ : x = x/*, test = test + 8*/;
	n = m;
	/*std::cout << x << " " << test << std::endl;
	test = 0;*/
	(n > 0) ? (n == 1) ? x = x/*, test = test + 1*/ : (n % 2 == 1) ? x = odd(x, n)/*, test = test + 2*/, m = n - 1 : x = even(x, n), m = n / 2/*, test = test + 4*/ : x = x/*, test = test + 8*/;
	n = m;
	/*std::cout << x << " " << test << std::endl;
	test = 0;*/
	(n > 0) ? (n == 1) ? x = x/*, test = test + 1*/ : (n % 2 == 1) ? x = odd(x, n)/*, test = test + 2*/, m = n - 1 : x = even(x, n), m = n / 2/*, test = test + 4*/ : x = x/*, test = test + 8*/;
	n = m;
	/*std::cout << x << " " << test << std::endl;
	test = 0;
	std::cout << oddNumber << std::endl;*/
	(oddNumber == 1) ? x = x * y : x = x;
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