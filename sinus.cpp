#define _USE_MATH_DEFINES
 
#include <cmath>
#include <iostream>


double reduceX(double x){
	double twoPi = 2 * M_PI;
	x = x -(int(x / twoPi) * twoPi);
	return x;
}

double calcAngle(double angle){
	double result = (angle * M_PI) / 180.;		//diese funktion convertiert die eingabe in bogenmas um dann vom program verwendet werden zu können
	return result;
}

double taylor_sin(double x){
	//x = calcAngle(x);
	x = x-((x * x * x) / 6);							//annäherungs funktion für sinus
	return x;
}

double pump_sin(double sin_third){
	double approx = 3 * sin_third - 4 * (sin_third * sin_third * sin_third);
	return approx;
}

double my_sin(double x){
	double y = calcAngle(x);
	y = reduceX(y);
	(std::abs(x) <= 9) ? y = taylor_sin(y) : y = pump_sin(my_sin(x / 3.0));
	return y;
}

double calcSin(double angle){
	angle = calcAngle(angle);
	double implemented = std::sin(angle);	
	return implemented;
}

void printSins(){  												// einfache methode alle werte schnell und einfach zu zeigen.
	int angles[20] = {-315, -270, -225, -180, -135, -90, -45, -20, -19, -5, 5, 10, 20, 45, 90, 135, 180, 225, 270, 315};	
	double tS[20];												// die frage bezüglich welche grad Zahl darf nicht überschritten werden 
	double rS[20];												// weil die annäherung sonst zu ungenau ist lautet 9° 
	double diff[20];
	double print;													
	for(int i = 0; i < 20; i++){
		double x = calcAngle(angles[i]);
		print = taylor_sin(x);
		std::cout << "Die Annaherung von taylor_sin fuer " << angles[i] << "	Grad ist " << print << std::endl;
	}
	std::cout << std::endl;
	for(int i = 0; i < 20; i++){
		print = my_sin(angles[i]);
		tS[i] = print;
		std::cout << "Die Annaherung von my_sin fuer " << angles[i] << "	Grad ist " << print << std::endl;
	}
	std::cout << std::endl;
	for(int i = 0; i < 20; i++){
		print = calcSin(angles[i]);
		rS[i] = print;
		diff[i] = rS[i] - tS[i];
		std::cout << "Der richtige Sinus hat als loesung " << angles[i] << "	Grad ist " << print << std::endl;
	}
	std::cout << std::endl;
	for(int i = 0; i < 20; i++){
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
		//angle = calcAngle(input);					// winkel zu bogenmas convertieren
		approx = my_sin(input);
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