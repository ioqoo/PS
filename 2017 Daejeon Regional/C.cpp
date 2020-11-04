#include <bits/stdc++.h>
const int MAX = 100005;
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

int N, M;
vector<int> graph[MAX];
int dp[MAX];
int degree[MAX];
vector<pii> edges;

int go(int curr){
	int &ret = dp[curr];
	if (ret != -1) return ret;
	ret = 1;
	for (int next: graph[curr]){
		ret = max(ret, go(next) + 1);
	}
	return ret;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d", &N, &M);
	memset(dp, -1, sizeof(dp));
	
	for (int i=0;i<M;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		degree[u]++; degree[v]++;
		edges.push_back({u, v});
	}
	
	for (auto p: edges){
		int u = p.f, v = p.s;
		int deg_u = degree[u], deg_v = degree[v];
		if (deg_u > deg_v){
			graph[v].push_back(u);
		}
		else if (deg_u < deg_v){
			graph[u].push_back(v);
		}
	}
	
	int ans = 0;
	for (int i=0;i<N;i++){
		ans = max(ans, go(i));
	}
	printf("%d\n", ans);
	
	
	
	return 0;
}


