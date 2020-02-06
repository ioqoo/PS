#include <bits/stdc++.h>
#define ll long long
#define MAX 1234567890
#define MAX_NODE 52

using namespace std;

int AtoI(char c){
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

// Edmonds-Karp Algorithm
// O(VE^2)
// Ford-Fulkerson과 다른 점은, FF는 증가 경로를 DFS로 찾는데 반해 EK는 BFS로 찾는다. 다시 말해
// 가장 짧은 증가 경로를 그때마다 찾고, 유량을 흘려 주는 것
// FF는 O((V+E)f)
// 이 f는 최대 유량인데, 이게 너무 크면 FF는 못 쓰게 됨
// 그래서 대체할 수 있는 게 EK

// cf) DFS : O(V+E) (매번)

int n;
int C[MAX_NODE][MAX_NODE];
int F[MAX_NODE][MAX_NODE];
vector<int> graph[MAX_NODE];


int main() {
	scanf("%d", &n);
	for (int i=0;i<n;i++){
		char u, v;
		int w;
		scanf("\n%c %c %d", &u, &v, &w);
		int U = AtoI(u);
		int V = AtoI(v);
		graph[U].push_back(V);
		graph[V].push_back(U);
		C[U][V] = C[V][U] += w;
	}

	int ans = 0, S = AtoI('A'), E = AtoI('Z');
	while(1){
		int prev[MAX_NODE];
		fill(prev, prev+MAX_NODE, -1);
		queue<int> Q;
		Q.push(S);
		while(!Q.empty() && prev[E] == -1){
			int curr = Q.front();
			Q.pop();
			for(auto next: graph[curr]){
				if (C[curr][next] - F[curr][next] > 0 && prev[next] == -1){
					Q.push(next);
					prev[next] = curr;
					if(next == E) break;
				}
			}
		}	
		if (prev[E] == -1) break;

		int flow = MAX;
		for (int i=E;i!=S;i=prev[i]){ // E부터 S까지 거꾸로
			flow = min(flow, C[prev[i]][i] - F[prev[i]][i]);
		}
		for (int i=E;i!=S;i=prev[i]){
			F[prev[i]][i] += flow;
			F[i][prev[i]] -= flow;
		}
		ans += flow;
	}
	printf("%d\n", ans);
}

