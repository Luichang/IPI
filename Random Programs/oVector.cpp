#include <iostream>	
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector <string> split_words(string s)
{
    vector<string> v1;    
    v1.push_back(s);
    
    //s.find(" ");
    
    return v1;
}

int main () {
    string s = "Alpha";
	vector<string> b = split_words(s);
	for(int i = 0; i < b.size(); ++i){
		cout << b[i] << endl;
	}
    
    return 0;
}