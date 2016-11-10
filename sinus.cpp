#define _USE_MATH_DEFINES
 
#include <cmath>
#include <iostream>

double taylor_sin(double x){
	x = x-(x*x*x)/6;								//annäherungs funktion für sinus
	return x;
}

double calcAngle(double angle){
	double result = (2 * M_PI)/360 * angle;			//diese funktion convertiert die eingabe in bogenmas um dann vom program verwendet werden zu können
	return result;
}

double approxSin(double angle){
	double approximation = taylor_sin(angle);		// sollte man öfters sinus berechnen wollen
	return approximation;
}

double pump_sin(double sin_third){
	//double approximation = taylor_sin(sin_third)/3;
	double approximation = sin_third /3;
	double approx1 = approximation;
	double approx2 = 3 * approximation - 4 * (approx1 * approx1 * approx1);
	return approx2;
}

double calcSin(double angle){
	double implemented = std::sin(angle);	
	return implemented;
}

int main(){
	std::string cont;
	while(cont != "no"){							//eingefügt um das program nicht für jeden neuen wert jedes mal neu srarten zu müssen
		double angle;								// variablen decleration
		double angle2;
		double calc;
		double approx1;
		double approx2;
		double approx3;
		std::cout << "This program will take an angle and calculate the Sin value based on a Sin approximation and the implemented Sin function" << std::endl;
		std::cout << "Please enter an Angle" << std::endl;
		std::cin >> angle;							// annahme des winkels
		angle2 = calcAngle(angle);					// winkel zu bogenmas convertieren
		approx1 = approxSin(angle2);				// rufen der funktion um sinus anzunähern
		approx2 = pump_sin(angle2);					// rufen der funktion um sinus anzunähern
		approx3 = pump_sin(approx2);					// rufen der funktion um sinus anzunähern
		calc = calcSin(angle2);						// rufen der function um sinus genau zu berechnen
		std::cout << "The answer for the first approximation is:  " << approx1 << std::endl;
		std::cout << "The answer for the second approximation is: " << approx2 << std::endl;
		std::cout << "The answer for the third approximation is:  " << approx3 << std::endl;
		std::cout << "The implemented version of Sin resulted in: " << calc << std::endl;
		std::cout << "Would you like to enter another number? 'yes' to continue, 'no' to quit" << std::endl; 
		std::cin >> cont;							// annahme der break variable
	}
	
}