#include <bits/stdc++.h>
#define ll long long
using namespace std;

int fail[500005];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string word;
	cin >> word;
	ll K;
	cin >> K;
	ll N = word.size();
	
	for (int i=1, j=0;i<N;i++){
		while(j > 0 && word[i] != word[j]) j = fail[j-1];
		if (word[i] == word[j]) fail[i] = ++j;
	}
	ll ans = N + (N - (ll)fail[N-1]) * (K-1);	
	cout << ans;
	
	
	return 0;
}


