#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

template<typename T>
std::string toString(const T& value)
{
    std::ostringstream stream;
    stream << value;
    return stream.str();
}

int addPointFive(double in){
	return in + 0.5;
}

vector<int> vector_to_int(vector<double> v){
	vector<int> newIntVector(v.size());
	transform(v.begin(), v.end(), newIntVector.begin(), addPointFive);
	return newIntVector;
}

vector<double> vec_rounded(vector<double> v){
	vector<double> newDoubleVector(v.size());
	transform(v.begin(), v.end(), v.begin(), [](double i) {return i * 100;});
	transform(v.begin(), v.end(), newDoubleVector.begin(), addPointFive);
	transform(newDoubleVector.begin(), newDoubleVector.end(), newDoubleVector.begin(), [](double i) {return i / 100;});
	return newDoubleVector;
}

string addZeros(string s){
	int periodPosition;
	if(s.find('.') != string::npos){
		periodPosition = s.find('.');
		if(periodPosition == s.size() - 2){
			s += "0";
		}
	}else{
		s += ".00";
	}
	return s;
}

string addApostophe(string s){
	if(s.size() > 6){
		s.insert(s.size() - 6, "'");
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
	vector<double> madeOfDoubeles = {12485.3, 19.5, 2.28754, 4.8654};
	vector<int> madeOfInts = vec_rounded(madeOfDoubeles);
	for(auto i : madeOfInts){
		cout << double_to_string(i) << endl;
	}
	vector<string> madeOfStrings = format_numbers(madeOfDoubeles);
	for(auto i : madeOfStrings){
		cout << i << endl;
	}
}