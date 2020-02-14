#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int T;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> T;
	for (int t=0;t<T;t++){
		string A, B, C;
		cin >> A >> B >> C;
		int N = A.size();
		bool succ = true;
		for (int i=0;i<N;i++){
			char a = A[i], b = B[i], c = C[i];
//			cout << a << " " << b << " " << c << endl;
			if (a == b) {
				if (a != c){
					succ = false;
					cout << "NO\n";
					break;
				}
			}
			else{
				if (a != c && b != c){
					succ = false;
					cout << "NO\n";
					break;
				}
			}
		}
		if (succ){
			cout << "YES\n";
		}
		
		
	}
	
}
