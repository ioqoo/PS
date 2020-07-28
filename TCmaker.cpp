#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream out("sample_TC.txt");
	out << "1\n";
	out << "300000\n";
	for (int i=0;i<300000;i++){
		out << "2 ";
	}
	
	out.close();
}
