#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream out("sample_TC.txt");
	for (int i=0;i<10;i++){
		out << i << endl;
	}
	out.close();
}
