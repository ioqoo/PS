#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream out("sample_TC.txt");
	out << "1\n";
	out << "200000\n";
	for (int i=0;i<200000;i++){
		out << "1" << " ";
	}
	out << "\n";
	for (int i=0;i<200000;i++){
		out << "1000000000" << " ";
	}	
	
	out.close();
}
