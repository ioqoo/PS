#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define pii pair<int, int>
const int MAX = 20005;

using namespace std;

int N;
vector<pii> graph[MAX];
bool visited[MAX];
ll dp1[MAX];
ll dp2[MAX];
int st[MAX], en[MAX];
int cnt;

void ordering(int curr){
	st[curr] = cnt++;
	for (pii next: graph[curr]){
		if (st[next.first] != -1) continue;
		ordering(next.first);
	}
	en[curr] = cnt;
}

ll get_child(int curr){
	return en[curr] - st[curr];
}

ll dfs(int curr){
	visited[curr] = true;
	ll &ret = dp1[curr];
	for (pii next: graph[curr]){
		if (visited[next.first]) continue;
		ret += (ll)next.second * get_child(next.first);
		ret += dfs(next.first);
	}
	return ret;
}

void bfs(int curr){
	memset(visited, 0, sizeof(visited));
	queue<int> Q;
	Q.push(curr);
	visited[curr] = true;
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for (pii next: graph[curr]){
			if (visited[next.first]) continue;
			dp2[next.first] = dp2[curr] + (ll)next.second * ((ll)N - get_child(next.first)) + (dp1[curr] - (dp1[next.first] + (ll)next.second * get_child(next.first)));
			Q.push(next.first);
			visited[next.first] = true;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	while(1){
		scanf("%d", &N);
		if (N==0) break;
		for (int i=0;i<N;i++){
			graph[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		memset(st, -1, sizeof(st));
		memset(en, 0, sizeof(en));
		cnt = 0;
		
		for (int i=0;i<N-1;i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});
		}
		ordering(0);
		
		dfs(0);
		bfs(0);
		for (int i=0;i<N;i++){
			dp1[i] += dp2[i];
		}
		printf("%lld\n", *min_element(dp1, dp1+N));
	}
	
	
	return 0;
}


