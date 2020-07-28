#include <bits/stdc++.h>

#define pii pair<int, int>
const int MAX = 200005;

using namespace std;

vector<int> graph[MAX];
int ind[MAX];
bool visited[MAX];
set<pii> undir_edges;

bool dfs(int curr){
	for (int next: graph[curr]){
		if (visited[next]) {
			return false;
		}
		visited[next] = true;
		dfs(next);
		visited[next] = false;
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	scanf("%d", &t);
	while(t--){
		int N, M;
		scanf("%d %d", &N, &M);
		fill(graph, graph+MAX, vector<int>{});
		memset(ind, 0, sizeof(ind));
		memset(visited, 0, sizeof(visited));
		undir_edges.clear();
		
		for (int i=0;i<M;i++){
			int x, u, v;
			scanf("%d %d %d", &x, &u, &v);
			if (x == 1){
				graph[u].push_back(v);
				ind[v]++;
			}
			else{
				undir_edges.insert({u, v});
			}
		}
		bool flag = true;
		for (int i=1;i<=N;i++){
			visited[i] = true;
			bool status = dfs(i);
			if (!status){
				flag = false;
				break;
			}
			visited[i] = false;
		}
		if (!flag){
			printf("NO\n");
			continue;
		}
		memset(visited, 0, sizeof(visited));
		for (auto p: undir_edges){
			int u = p.first, v = p.second;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		queue<int> Q;
		for (int i=1;i<=N;i++){
			if (ind[i] == 0){
				Q.push(i);
			}
		}
		
		vector<pii> ans;
		bool flag2 = true;
		for (int i=0;i<N;i++){
			if (Q.empty()){
				flag2 = false;
				break;
			}
			int curr = Q.front(); Q.pop();
			visited[curr] = true;
			for (int next: graph[curr]){
				if (visited[next]) continue;
				ans.push_back({curr, next});
				if (--ind[next] == 0) Q.push(next);
			}
		}
		if (!flag2) printf("NO\n");
		else {
			printf("YES\n");
			for (auto p: ans){
				printf("%d %d\n", p.first, p.second);
			}
		}
	}
	
	
	return 0;
}


