#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sortList(vector<int> v, int insertInt){		
	int vectorLength = v.size();						
	if(vectorLength == 0){
		v.push_back(insertInt);						// this will initialize the vector for the future run throughs of this function
	}else{
		for(int i = 0; i < vectorLength; ++i){		// itreration through every value to make sure there is no number bigger than the entered number 
			if(v[i] > insertInt){
				int pass = v[vectorLength];
				v.push_back(pass);					// once a number bigger than the entered one was found the whole vector adds one slot to its size
				for(int j = vectorLength; j > i; --j){	// to then add the new number
					v[j] = v[j-1];						// this goes through every bigger number and just 'pushes' it to the right
				}
				v[i] = insertInt;					// finally we enter the new number to the vector
				i = v.size();						// setting the value of i equal to the size so it won't continue to iterate,
			}										// I prefer this over break for no particular reason
		}
		if(vectorLength == v.size()){				// should the vector not have a bigger number than the one entered it will simply place the new
			v.push_back(insertInt);					// number at the end of the vector
		}
	}
	return v;
}

int main(){
	int input;
	vector<int> orderedInsert;
	bool endCode = false;
	while(!endCode){
		cin >> input;
		if(abs(input) != input){
			endCode = true;
			for(int i = 0; i < orderedInsert.size(); ++i){				// tried for(int i; orderedInsert) but it would not work... need to look more into foreach
				cout << orderedInsert[i] << " ,";				// lazy way of outputting and seperating elements of the vector
			}
		}else {
			orderedInsert = sortList(orderedInsert, input);		// if the number was not negative enter it into the vector
		}
	}
}