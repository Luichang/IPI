#include <iostream>

double sq(double x){
	x = x * x;
	return x;
}

double power(double x, int n){
	double y = 0;
	(n == 1) ? y = x
		:(n % 2 == 0) ? y = sq(power(x, n / 2))		// using recursive functions
			: y = x * (power(x, n - 1));
    return y;
}	

int main(){
	//std::string cont;
	//while(cont != "no"){ 	// while used to test various potenzes and make writing the answers
		double x = 0;		// variable decleration
		int n = 0;
		double result = 0;
		std::cout << "Please enter a value for x" << std::endl;
		std::cin >> x;
		std::cout << "Please enter the potenz of x" << std::endl;
		std::cin >> n;
		result = power(x, n);
		std::cout << "the answer provided was: " << result << std::endl;
		//std::cout << "Would you like to enter another number? 'yes' to continue, 'no' to quit" << std::endl; 
		//std::cin >> cont;							// annahme der break variable
	//}
}

/* 
schlechte idee im fall "n ist gerade" frage:
wie bei so vielem anderen in der informatik geht es auch hier bei um den effizientesten weg.
mit unserer methode müssen wir so wenig rechen operationen durch gehen wie nötig um auf das selbe ergebnis zu kommen
für und Menschen heißt das das wir unsere lösung "schneller" bekommen
*/
