#define _USE_MATH_DEFINES
 
#include <cmath>
#include <iostream>

double calcAngle(double angle){
	double result = (2 * M_PI) / 360 * angle;		//diese funktion convertiert die eingabe in bogenmas um dann vom program verwendet werden zu können
	return result;
}

double changeX(double x){
	(x < - M_PI) ? x = x + changeX(x + 2 * M_PI) 
		: (x > M_PI) ? x = x - changeX( x - 2 * M_PI)
			: x = x;
	return x;
}

double taylor_sin(double x){
	x = calcAngle(x);
	x = x-(x * x * x) / 6;							//annäherungs funktion für sinus
	return x;
}

double pump_sin(double sin_third){
	//double approximation = taylor_sin(sin_third)/ 3;
	//double approximation = sin_third / 3;
	sin_third = calcAngle(sin_third);
	double approx = 3 * sin_third - 4 * (sin_third * sin_third * sin_third);
	return approx;
}

double my_sin(double x){
	//double bogenmas = calcAngle(x);
	(std::abs(x) <= 9) ? x = taylor_sin(x) 
		: x = my_sin(x / 3.0);
	pump_sin(x);
	return x;
}

double calcSin(double angle){
	angle = calcAngle(angle);
	double implemented = std::sin(angle);	
	return implemented;
}

int main(){
	std::string cont;
	while(cont != "no"){								//eingefügt um das program nicht für jeden neuen wert jedes mal neu srarten zu müssen
		double angle, input, calc, approx, approx1, approx2, x;	// variable decleration
		std::cout << "This program will take an angle and calculate the Sin value based on a Sin approximation and the implemented Sin function" << std::endl;
		std::cout << "Please enter an Angle" << std::endl;
		std::cin >> input;							// annahme des winkels
		//angle = calcAngle(input);					// winkel zu bogenmas convertieren
		x = changeX(input);
		approx = my_sin(x);
		approx1 = taylor_sin(x);				// rufen der funktion um sinus anzunähern
		approx2 = pump_sin(x / 3);					// rufen der funktion um sinus anzunähern
		calc = calcSin(input);						// rufen der function um sinus genau zu berechnen
		std::cout << "The answer for the approximation is:		" << approx << std::endl;
		std::cout << "The answer for the first approximation is:	" << approx1 << std::endl;
		std::cout << "The answer for the second approximation is:	" << approx2 << std::endl;
		std::cout << "The implemented version of Sin resulted in:	" << calc << std::endl;
		std::cout << "Would you like to enter another number? 'yes' to continue, 'no' to quit" << std::endl; 
		std::cin >> cont;							// annahme der break variable
	}
	
}