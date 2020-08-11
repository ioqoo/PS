#include <bits/stdc++.h>

using namespace std;



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		multiset<int> Q;
		int k;
		cin >> k;
		while(k--){
			char op;
			int n;
			cin >> op >> n;
			if (op == 'I'){
				Q.insert(n);
			}
			else{
				if (Q.empty()) continue;
				if (n == -1){
					Q.erase(Q.begin());
				}
				else if (n == 1){
					Q.erase(prev(Q.end()));
				}
			}
		}
		if (Q.empty()) cout << "EMPTY\n";
		else cout << *(prev(Q.end())) << " " << *(Q.begin()) << "\n";
	}
	
	
	return 0;
}

