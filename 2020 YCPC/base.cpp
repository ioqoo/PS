#include <bits/stdc++.h>
const int MAX = 500005;

using namespace std;

int N, W;
vector<int> graph[MAX];
bool visited[MAX];
int leaf = 0;

void dfs(int curr){
	visited[curr] = true;
	bool flag = false;
	for (int next: graph[curr]){
		if (visited[next]) continue;
		flag = true;
		dfs(next);
	}
	if (!flag) {
		leaf++;
		return;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d", &N, &W);
	for (int i=0;i<N-1;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}	
	
	dfs(1);
	printf("%lf\n", W*1. / leaf);
	
	
	return 0;
}


