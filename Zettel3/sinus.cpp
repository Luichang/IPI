#define _USE_MATH_DEFINES
 
#include <cmath>
#include <iostream>


double reduceX(double x){				// weil sinus rekkursiv brauht man nur ein x was zwischen -Pi und Pi liegz
	double twoPi = 2 * M_PI;			// wenn man also den floorMod von dem gegebenen x mit 2 mal Pi nimmt wird der rest 
	x = x -(int(x / twoPi) * twoPi);	// sprich das ergebnis innerhalb des erwünschten intervalles liegen
	return x;
}

double calcAngle(double angle){
	double result = (angle * M_PI) / 180.;		//diese funktion convertiert das x in Bogenmaß um dann zum Sinus berechnen vervendet werden zu können
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

double calcSin(double angle){						// die von c++ implimentierte sinus funktion
	angle = calcAngle(angle);
	double implemented = std::sin(angle);	
	return implemented;
}

void printSins(){  												// einfache methode alle werte schnell und einfach zu zeigen. Relevant für a und d
	int angles[20] = {-315, -270, -225, -180, -135, -90, -45, -20, -10, -5, 5, 10, 20, 45, 90, 135, 180, 225, 270, 315};	// leider ist die tabelle an den stellen wo die antwort keine lange komma Zahl hat nicht übereinstimmend, ging nicht anders
	std::cout << "angle	|taylor_sin	|my_sin		"/*|Sinus*/		"|Abweichungen(taylor)	|(my_sin)" << std::endl; // man sieht hier beide abweichungstabellen
	std::cout << "___________________________________________________________________________" << std::endl;
	for(int i = 0; i < 20; i++){
		std::cout << angles[i] << "	|" << taylor_sin(calcAngle(angles[i])) << "  	|" << my_sin(angles[i]) << "	|" 
		<< /*calcSin(angles[i]) << "	|" << */std::abs(taylor_sin(calcAngle(angles[i])) - calcSin(angles[i])) << "	|" 
		<< std::abs(my_sin(angles[i]) - calcSin(angles[i])) << std::endl;
	}
	std::cout << std::endl;
}

int main(){
	double input, calc, approx, x;	// variable decleration
	//std::string cont;
	printSins();
	//while(cont != "no"){								//eingefügt um das program nicht für jeden neuen wert jedes mal neu srarten zu müssen
		std::cout << "This program will take an angle and calculate the Sin value based on a Sin approximation and the implemented Sin function" << std::endl;
		std::cout << "Please enter an Angle" << std::endl;
		std::cin >> input;							// annahme des winkels
		approx = my_sin(input);
		calc = calcSin(input);						// rufen der function um sinus genau zu berechnen
		std::cout << "The answer for the my_sin is:			" << approx << std::endl;
		std::cout << "The implemented version of Sin resulted in:	" << calc << std::endl;
		/*std::cout << "Would you like to enter another number? 'yes' to continue, 'no' to quit" << std::endl; 
		std::cin >> cont;							// annahme der break variable
	}*/
	
}
