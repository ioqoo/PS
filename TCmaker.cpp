#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream out("sample_TC.txt");
	
	int cnt = 0;
	out << "1\n";
	out << "48 48 324\n";
	
	for (int i=1;i<=30;i++){
	    for (int j=1;j<=30;j++){
	        if (i%2) out << "#";
	        else {
	            if (cnt == 100*2){
	                out << "#";
                }
                else{
    	            if (j%3 == 0) out << "#";
    	            else {
    	                out << ".";
    	                cnt++;
                    }
                }
            }
        }
        out << endl;
    }
	
	for (int i=0;i<10;i++){
		for (int j=0;j<10;j++){
		    out << (char) (i+'a') << (char) (j + 'a') << " ";
        }
	}
	out.close();
}
