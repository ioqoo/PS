#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream out("sample_TC.txt");
	out << "20000\n";
	for (int i=0;i<19999;i++){
		out << i << " " << i+1 << " " << "100\n";
	}
	out << "0";
	
	out.close();
}
