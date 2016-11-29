#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void ruinAll(){
	ifstream inFile("troll.cpp");
    ofstream outFile("new.cpp");
    string content = "";
    int i;

    for(i = 0; inFile.eof()!= true; ++i){ // get content of inFile
        content += inFile.get();
	}
    --i;
    content.erase(content.end()-1);     // erase last character
    inFile.close();

    outFile << content;                 // output
    outFile.close();
	
	cout << "Gathering error report ";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << endl << "Recalculating Program" << endl;
	Sleep(1000);
	remove( "troll.cpp" );
}

int main()
{
	ruinAll();
    return 0;
}