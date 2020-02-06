#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const int MAX_N = 100;
const int MAX_V = 2*(MAX_N+1);
const int S = MAX_V - 2;
const int E = MAX_V - 1;

int N, M;
int C[MAX_V][MAX_V];
int D[MAX_V][MAX_V];
int F[MAX_V][MAX_V];
vector<int> graph[MAX_V];

graph.reserve

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

	scanf("%d %d", &N, &M);
	for (int i=MAX_N;i<MAX_N+N;i++){
		int temp;
		scanf("%d", &temp);
		graph[E].push_back(i);
		graph[i].push_back(E);
		C[i][E] = temp;
	}
	for (int i=0;i<M;i++){
		int temp;
		scanf("%d", &temp);
		graph[S].push_back(i);
		graph[i].push_back(S);
		C[S][i] = temp;
	}
	for (int i=0;i<M;i++){
		for (int j=MAX_N;j<MAX_N+N;j++){
			int temp;
			scanf("%d", &temp);
			D[i][j] = temp;
			D[j][i] = -temp;
			C[i][j] = INF;
			graph[i].push_back(j);
			graph[j].push_back(i);
		}
	}

	int answer = 0;
	while(1){
		int prev[MAX_V], dist[MAX_V];
		bool in_Q[MAX_V] = {0,};
		queue<int> Q;
		fill(prev, prev+MAX_V, -1);
		fill(dist, dist+MAX_V, INF);
		dist[S] = 0;
		in_Q[S] = true;
		Q.push(S);

		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			in_Q[curr] = false; // 꺼냈으면 다시 false로
			for (int next: graph[curr]){
				if (C[curr][next] - F[curr][next] > 0 && dist[next] > dist[curr] + D[curr][next]){
					dist[next] = dist[curr] + D[curr][next];
					prev[next] = curr;
					if(!in_Q[next]){ // 큐에 안들어 있으면 넣기
						Q.push(next);
						in_Q[next] = true;
					}
				}
			}

		}

		if (prev[E] == -1) break;

		int flow = INF;
		for (int i=E;i!=S;i=prev[i]){
			flow = min(flow, C[prev[i]][i] - F[prev[i]][i]);
		}
		for (int i=E;i!=S;i=prev[i]){
			answer += flow * D[prev[i]][i];
			F[prev[i]][i] += flow;
			F[i][prev[i]] -= flow;
		}
	}
	printf("%d\n", answer);
}
