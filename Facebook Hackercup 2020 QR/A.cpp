#include <bits/stdc++.h>
const int MAX = 53;
using namespace std;

int N;
char grid[MAX][MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for (int T=1;T<=t;T++){
		cin >> N;
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				grid[i][j] = 'N';
			}
		}
		string I, O;
		cin >> I >> O;
		for (int i=0;i<N;i++){
			if (O[i] == 'N'){
				for (int j=0;j<N;j++){
					if (i==j) grid[i][j] = 'Y';
					else grid[i][j] = 'N';
				}
			}
			else grid[i][i] = 'Y';
		}
		for (int i=0;i<N;i++){
			if (O[i] == 'N') continue;
			if (i==0){
				int pos = 1;
				while(pos < N){
					if (I[pos] == 'N') break;
					grid[i][pos] = 'Y';
					if (O[pos] == 'N') break;
					pos++;
				}
			}
			else if (i == N-1){
				int pos = i-1;
				while(pos >= 0){
					if (I[pos] == 'N') break;
					grid[i][pos] = 'Y';
					if (O[pos] == 'N') break;
					pos--;
				}
			}
			else{
				int pos = i-1;
				while(pos >= 0){
					if (I[pos] == 'N') break;
					grid[i][pos] = 'Y';
					if (O[pos] == 'N') break;
					pos--;
				}
				pos = i+1;
				while(pos < N){
					if (I[pos] == 'N') break;
					grid[i][pos] = 'Y';
					if (O[pos] == 'N') break;
					pos++;
				}
			}
		}
		cout << "Case #" << T << ":\n";
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				cout << grid[i][j];
			}
			cout << "\n";
		}
		
	}
	
	
	return 0;
}


