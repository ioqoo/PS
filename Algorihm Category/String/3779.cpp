#include <iostream>
#include <string>
#include <cstring>
const int MAX = 1000005;
using namespace std;

int fail[MAX];

int GCD(int a, int b){
	while(b != 0){
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 0;
	while(1){
		int N;
		cin >> N;
		t++;
		if (N==0) return 0;
		fill(fail, fail+N+2, 0);
		
		string word;
		cin >> word;
		cout << "Test case #" << t << "\n";
		for (int i=1, j=0;i<N;i++){
			while(j > 0 && word[i] != word[j]) j = fail[j-1];
			if (word[i] == word[j]) fail[i] = ++j;
		}
		for (int i=1;i<N;i++){
			if (fail[i] == 0) continue;
			if ( i+1 == fail[i] + GCD((i+1), fail[i]) ) {
				cout << i+1 << " " << (i+1) / GCD(fail[i], i+1) << "\n";
			}
		}
		cout << "\n";
	}
	
	
	
	
	return 0;
}


