#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 1005;
using namespace std;

int N, K;
vector<int> graph[MAX];
int to[MAX];
bool visited[MAX], finished[MAX];
int cmax[MAX], cmin[MAX]; // cmax : component size, cmin : cycle size
int mark[MAX], pre[MAX];
int num = 1;
int dp[MAX];

void dfs(int curr, int num){
	visited[curr] = true;
	cmax[num]++;
	mark[curr] = num;
	for (int next: graph[curr]){
		if (visited[next]) continue;
		dfs(next, num);
	}
}

void detect_cycle(int curr){
	visited[curr] = true;
	int next = to[curr];
	if (visited[next]){
		if (!finished[next]){
			for (int i=curr;i!=next;i=pre[i]){
				cmin[mark[i]]++;
			}
			cmin[mark[curr]]++;
		}
	}
	else {
		pre[next] = curr;
		detect_cycle(next);
	}

	finished[curr] = true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d", &N, &K);
	for (int i=1;i<=N;i++){
		int v;
		scanf("%d", &v);
		graph[i].push_back(v);
		graph[v].push_back(i);
		to[i] = v;
	}
	
	for (int i=1;i<=N;i++){
		if (!visited[i]) dfs(i, num++);
	}
	
	memset(visited, 0, sizeof(visited));
	
	for (int i=1;i<=N;i++){
		if (!visited[i]) detect_cycle(i);
	}
	
	vector<pii> V;
	for (int i=1;i<num;i++){
		V.push_back({cmin[i], cmax[i]});
	}
	sort(V.begin(), V.end());
	
	
	int X = V.size();
	
	for (int i=0;i<X;i++){
		int m = V[i].first, M = V[i].second;
		for (int j=K;j>=0;j--){
			for (int w=M;w>=m;w--){
				if (j - w >= 0){
					dp[j] = max(dp[j], dp[j-w] + w);
				}
			}
		}
	}
	
	
	printf("%d\n", dp[K]);
	
	
	
	return 0;
}

