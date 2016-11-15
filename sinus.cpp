#define _USE_MATH_DEFINES
 
#include <cmath>
#include <iostream>


double reduceX(double x){
	double twoPi = 2 * M_PI;
	x = x -(int(x / twoPi) * twoPi);
	std::cout << x << std::endl;
	return x;
}

double calcAngle(double angle){
	double result = (2 * M_PI) / 360 * angle;		//diese funktion convertiert die eingabe in bogenmas um dann vom program verwendet werden zu können
	return result;
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
	sin_third = taylor_sin(sin_third);
	double approx = 3 * sin_third - 4 * (sin_third * sin_third * sin_third);
	return approx;
}

double my_sin(double x){
	//double bogenmas = calcAngle(x);
	(std::abs(x) <= 9) ? x = taylor_sin(x) 
		: x = pump_sin(my_sin(x / 3.0));
	return x;
}

double calcSin(double angle){
	angle = calcAngle(angle);
	double implemented = std::sin(angle);	
	return implemented;
}

void printSins(){  // einfache methode alle werte schnell und einfach zu zeigen.
	int angles[10] = {5, 10, 20, 45, 90, 135, 180, 225, 270, 315};	// die frage bezüglich welche grad Zahl darf nicht überschritten werden 
	double tS[10];													// weil die annäherung sonst zu ungenau ist lautet 9° 
	double rS[10];
	double diff[10];
	double print;													
	for(int i = 0; i < 10; i++){
		print = taylor_sin(angles[i]);
		tS[i] = print;
		std::cout << "Die Annaeherung von taylor_sin fuer " << angles[i] << "	Grad ist " << print << std::endl;
	}
	std::cout << std::endl;
	for(int i = 0; i < 10; i++){
		print = my_sin(angles[i]);
		std::cout << "Die Annaeherung von my_sin fuer " << angles[i] << "	Grad ist " << print << std::endl;
	}
	std::cout << std::endl;
	for(int i = 0; i < 10; i++){
		print = calcSin(angles[i]);
		rS[i] = print;
		diff[i] = rS[i] - tS[i];
		std::cout << "Der richtige Sinus hat als loesung " << angles[i] << "	Grad ist " << print << std::endl;
	}
	std::cout << std::endl;
	for(int i = 0; i < 10; i++){
		print = diff[i];
		std::cout << "Die Abweichung liegt bei " << angles[i] << "		Grad " << print << std::endl;
	}
}

int main(){
	double /*angle,*/ input, calc, approx, /*approx1, approx2,*/ x;	// variable decleration
	std::string cont;
	printSins();
	while(cont != "no"){								//eingefügt um das program nicht für jeden neuen wert jedes mal neu srarten zu müssen
		std::cout << "This program will take an angle and calculate the Sin value based on a Sin approximation and the implemented Sin function" << std::endl;
		std::cout << "Please enter an Angle" << std::endl;
		std::cin >> input;							// annahme des winkels
		x = reduceX(input);
		//angle = calcAngle(input);					// winkel zu bogenmas convertieren
		approx = my_sin(x);
		//approx1 = taylor_sin(x);				// rufen der funktion um sinus anzunähern
		//approx2 = pump_sin(x / 3);				// rufen der funktion um sinus anzunähern
		calc = calcSin(input);						// rufen der function um sinus genau zu berechnen
		std::cout << "The answer for the my_sin is:			" << approx << std::endl;
		//std::cout << "The answer for the taylor_sin is:		" << approx1 << std::endl;
		//std::cout << "The answer for the pump_sin is:			" << approx2 << std::endl;
		std::cout << "The implemented version of Sin resulted in:	" << calc << std::endl;
		std::cout << "Would you like to enter another number? 'yes' to continue, 'no' to quit" << std::endl; 
		std::cin >> cont;							// annahme der break variable
	}
	
}