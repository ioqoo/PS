#include <bits/stdc++.h>

const int MAX = 500005;
using namespace std;

map<char, int> mp;

vector<int> get_fail(string W){
	vector<int> fail(W.size());
	for (int i=1, j=0;i<W.size();i++){
		while(j>0 && W[i] != W[j]) j = fail[j-1];
		if (W[i] == W[j]) fail[i] = ++j;
	}
	return fail;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		mp.clear();
		
		string order, W, S;
		cin >> order >> W >> S;
		int order_size = order.size();
		int W_size = W.size();
		int S_size = S.size();
		
		for (int i=0;i<order_size;i++){
			mp[order[i]] = i;
		}
		
		vector<int> ans_shift_val;
		
		for (int s=0;s<order_size;s++){
			string N = "";
			for (int i=0;i<W_size;i++){
				N += order[(mp[W[i]]+s)%order_size];
			}
//			cout << N << endl;
			vector<int> fail = get_fail(N);
			vector<int> match_pos;
			for (int i=0, j=0;i<S_size;i++){
				while(j>0 && S[i] != N[j]) j = fail[j-1];
				if (S[i] == N[j]) {
					if (j == W_size-1) {
						match_pos.push_back(i);
						j = fail[j];
					}
					else j++;
				}
			}
			if (match_pos.size() == 1){
				ans_shift_val.push_back(s);
			}
		}
		
		if (ans_shift_val.size() == 1){
			cout << "unique: " << ans_shift_val[0] << "\n";
		}
		else if (ans_shift_val.size() > 1){
			sort(ans_shift_val.begin(), ans_shift_val.end());
			cout << "ambiguous: ";
			for (int n: ans_shift_val){
				cout << n << " ";
			}
			cout << "\n";
		}
		else cout << "no solution\n";
		
	}
	
	
	
	return 0;
}


