#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "sort_versions.hpp"

using namespace std;

vector<int> split_version(string version){
	int periodPosition = 0;
	string partial;
	vector<int> splitedVersion;
	for(int i = 0; i < version.size(); ++i){
		if(version[i] == '.'){
			partial = version.substr(periodPosition, i);
			periodPosition = i + 1;
			splitedVersion.push_back(atoi(partial.c_str()));
		}
	}
	partial = version.substr(periodPosition, version.size());
	splitedVersion.push_back(atoi(partial.c_str()));
	return splitedVersion;
}

bool version_less(string v1, string v2){
	vector<int> version1 = split_version(v1);
	vector<int> version2 = split_version(v2);
	for(int i = 0; i < version1.size(); ++i){
		if(version1[i] < version2[i])
			return true;
		if(version1[i] > version2[i])
			return false;
	}
	return false;
}

int main(){
	string version1 = "4.31.53";
	string version2 = "4.31.5";
	vector<int> sVersion = split_version(version1);
	for(auto i:sVersion){
		cout << i << endl;
	}
	cout << version_less(version1, version2);
	sort(versions.begin(), versions.end(), version_less);
	for(auto i:versions){
		cout << i << endl;
	}
}