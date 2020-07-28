#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1000005;
using namespace std;

string S;
int N, d;
vector<int> SA, G, LCP;

bool cmp(int i, int j){
	if (G[i] != G[j]) return G[i] < G[j];
	i += d; j += d;
	return (i < N && j < N) ? (G[i] < G[j]) : (i > j);
}

void construct_SA(){
	N = S.size();
	for (int i=0;i<N;i++){
		SA[i] = i;
		G[i] = S[i];
	}
	
	for (d=1; ;d*=2){
		sort(SA.begin(), SA.end(), cmp);
		
		vector<int> temp_G[MAX] = {0,};
		
		for (int i=0;i<N-1;i++){
			temp_G[i+1] = temp_G[i] + cmp(SA[i], SA[i+1]);
		}
		for (int i=0;i<N;i++){
			G[SA[i]] = temp_G[i];
		}
		
		if (temp_G[N-1] == N-1) break;
	}
}

void construct_LCP(){
	for (int i=0, k=0;i<N;i++, k = max(k-1, 0)){
		if (G[i] == N-1) continue;
		for (int j=SA[G[i]+1];S[i+k]==S[j+k];k++);
		LCP[G[i]] = k;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> S;
	SA.resize(S.size());
	G.resize(S.size());
	LCP.resize(S.size());
	construct_SA();
	construct_LCP();
	
	ll ans = N - SA[N-1];
	for (int i=0;i<N-1;i++){
		ans += (ll)(N-SA[i]) - (ll)LCP[i];
	}
	
	cout << ans;
	
	return 0;
}


