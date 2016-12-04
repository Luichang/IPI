#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "format_numbers.hpp"

using namespace std;
		
template<typename T>
string toString(const T& value)
{
    std::ostringstream stream;
    stream << fixed << value;
    return stream.str();
}

int addPointFive(double in){					// simple lambda function to be reused at a later point
	if(in < 0)
		return in - 0.5;
	return in + 0.5;
}

vector<int> vector_to_int(vector<double> v){
	vector<int> newIntVector(v.size());
	transform(v.begin(), v.end(), newIntVector.begin(), addPointFive);
	return newIntVector;
}

vector<double> vec_rounded(vector<double> v){
	vector<double> newDoubleVector(v.size());
	transform(v.begin(), v.end(), v.begin(), [](double i) {return i * 100;});		// bulky way to have the vectors be transformed into the wanted result
	transform(v.begin(), v.end(), newDoubleVector.begin(), addPointFive);
	transform(newDoubleVector.begin(), newDoubleVector.end(), newDoubleVector.begin(), [](double i) {return i / 100;});
	return newDoubleVector;
}

string addZeros(string s){
	int periodPosition;
	for(int i = 0; i < 4; ++i){		// OK so since the toString function at first did not add the zeros at the end I was adding zeros here at one point
		s.pop_back();				// had to use the non implemented way to get it to work on my computer for some reason... thought I had the right
	}								// version... oh well. this will not clash with the std to_string, seeing as I cleverly changed the name 
	return s;
}

string addApostophe(string s){
	int position = s.find('.');
	while(position > 3){
		if(s[position - 4] != '-'){						// just going through each number and making sure that the aposophe is
			s.insert(position - 3, "'");				// every 3 numbers (for numbers like thousands)
		}
		position = position - 3;
	}
	return s;
}

string double_to_string(double x){
	x = x * 100;
	x = addPointFive(x);
	x = x / 100;
	string s = toString(x);
	s = addZeros(s);
	s = addApostophe(s);
	while(s.size() < 16){
		s.insert(0, " ");
	}
	return s;
}

vector<string> format_numbers(vector<double> v){
	vector<string> newstringVector(v.size());
	transform(v.begin(), v.end(), newstringVector.begin(), double_to_string);
	return newstringVector;
}

int main(){
	/*vector<double> madeOfDoubeles = {12485.3, 19.5, 2.28754, 4.8654};
	vector<int> madeOfInts = vector_to_int(madeOfDoubeles);
	for(auto i : madeOfInts){												// comenting out the previous assignment parts and just leaving the final part
		cout << double_to_string(i) << endl;
	}
	vector<double> madeOfNewDoubles = vec_rounded(madeOfDoubeles);
	for(auto i : madeOfNewDoubles){
		cout << double_to_string(i) << endl;
	}*/
	vector<string> madeOfStrings = format_numbers(numbers);
	for(auto i : madeOfStrings){
		cout << i << endl;
	}
}