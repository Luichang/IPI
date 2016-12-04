#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "sort_versions.hpp"

using namespace std;

template<typename T>
void printVectors(const vector<T> printV){		// starting to get the hang of templates, trying to remember the following:
	for(auto i:printV){							// you add a typename variable, this can be anything like an int, or string etc
		cout << i << endl;						// then as the variable to receive just use const, and the ambiguous variable
	}											// pretend like it's a normal function
	cout << endl;
}

vector<int> split_version(string version){
	int periodPosition = 0;
	string partial;
	vector<int> splitedVersion;
	for(int i = 0; i < version.size(); ++i){
		if(version[i] == '.'){									// this looks for reach period and adds the "substring", from between the last period,
			partial = version.substr(periodPosition, i);		// with out the period it self, to a new vector
			periodPosition = i + 1;								// the position of the period will be marked for the next substring
			splitedVersion.push_back(atoi(partial.c_str()));
		}
	}
	partial = version.substr(periodPosition, version.size());	// adds the last bit that does not have a following period
	splitedVersion.push_back(atoi(partial.c_str()));
	return splitedVersion;
}

bool version_less(string v1, string v2){
	vector<int> version1 = split_version(v1);
	vector<int> version2 = split_version(v2);
	while(version1.size() < version2.size()){			// ugly way to ensure that vectors to be compared are the same length to properly compare them
		version1.push_back(0);
	}
	while(version1.size() > version2.size()){
		version2.push_back(0);
	}
	for(int i = 0; i < version1.size(); ++i){
		if(version1[i] < version2[i])					// simple check to see which is larger by comparing each sub part of the vector
			return true;
		if(version1[i] > version2[i])
			return false;
	}
	return false;
}

int main(){
	/*string version1 = "4.31";
	string version2 = "4.31.1";
	vector<int> sVersion1 = split_version(version1);			// just commenting this out because not relevant in last parts of the assignment
	vector<int> sVersion2 = split_version(version2);
	printVectors(sVersion1);
	printVectors(sVersion2);
	vector<string> combined;
	combined.push_back(version1);
	combined.push_back(version2);
	printVectors(combined);
	sort(combined.begin(), combined.end(), version_less);
	printVectors(combined);*/
	sort(versions.begin(), versions.end(), version_less);
	printVectors(versions);
}