#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <queue>
#define ll long long
#define MAX_V 405
#define INF 987654321

using namespace std;

int C[MAX_V][MAX_V];
int F[MAX_V][MAX_V];
vector<int> graph[MAX_V];
int ans;

int main(){
	int n, p;
	scanf("%d %d", &n, &p);
	for (int i=0;i<p;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
		C[u][v] += 1;
	}
	while(1){
		int prev[MAX_V];
		fill(prev, prev+MAX_V, -1);
		queue<int> Q;
		Q.push(1);
		while(!Q.empty() && prev[2] == -1){
			int curr = Q.front();
			Q.pop();
			for (int next: graph[curr]){
				if (C[curr][next] - F[curr][next] > 0 && prev[2] == -1){
					Q.push(next);
					prev[next] = curr;
					if (next == 2) break;
				}
			}
		}
		if (prev[2] == -1) break;

		int flow = INF;
		for (int i=2;i!=1;i=prev[i]){
			flow = min(flow, C[prev[i]][i] - F[prev[i]][i]);
		}

		for(int i=2;i!=1;i=prev[i]){
			F[prev[i]][i] += flow;
			F[i][prev[i]] -= flow;
		}
		ans += flow;
	}
	printf("%d\n", ans);
}