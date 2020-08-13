#include <bits/stdc++.h>
const int MAX = 10005;
using namespace std;

int N;
int pop[MAX];
vector<int> graph[MAX];
int dp[MAX][2];

int solve(int curr, bool is_good){
	int &ret = dp[curr][is_good];
	if (ret != -1) return ret;
	
	
	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		scanf("%d", &pop[i]);
	}
	
	for (int i=0;i<N-1;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	
	
	return 0;
}

