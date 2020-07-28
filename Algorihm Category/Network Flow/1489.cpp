#include <bits/stdc++.h>

const int MAX = 1000;
const int S = 2*MAX+2;
const int E = 2*MAX+3;
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int C[2*MAX+5][2*MAX+5], F[2*MAX+5][2*MAX+5], D[2*MAX+5][2*MAX+5];
vector<int> graph[2*MAX+5];
vector<int> A, B;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		int temp;
		scanf("%d", &temp);
		A.push_back(temp);
	}
	for (int i=0;i<N;i++){
		int temp;
		scanf("%d", &temp);
		B.push_back(temp);
	}
	
	for (int i=0;i<N;i++){
		graph[S].push_back(i);
		graph[i].push_back(S);
		C[S][i] = 1;
		graph[i+MAX].push_back(E);
		graph[E].push_back(i+MAX);
		C[i+MAX][E] = 1;
	}
	
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			int u_score = A[i], v_score = B[j];
			graph[i].push_back(MAX+j);
			graph[MAX+j].push_back(i);
			C[i][MAX+j] = 1;
			if (u_score > v_score) {
				D[i][MAX+j] = -2;
				D[MAX+j][i] = 2;
			}
			else if (u_score == v_score) {
				D[i][MAX+j] = -1;
				D[MAX+j][i] = 1;
			}
		}
	}
	
	int ans = 0;
	while(1){
		int pre[2*MAX+5], dist[2*MAX+5];
		memset(pre, -1, sizeof(pre));
		memset(dist, 0x3f, sizeof(dist));
		bool inQ[2*MAX+5] = {0,};
		queue<int> Q;
		dist[S] = 0;
		Q.push(S);
		inQ[S] = true;
		
		while(!Q.empty()){
			int curr = Q.front(); Q.pop(); inQ[curr] = false;
			for (int next: graph[curr]){
				if (C[curr][next] - F[curr][next] > 0 && dist[curr] + D[curr][next] < dist[next]){
					dist[next] = dist[curr] + D[curr][next];
					pre[next] = curr;
					if (!inQ[next]){
						Q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if (pre[E] == -1) break;
		
		int flow = INF;
		for (int i=E;i!=S;i=pre[i]){
			flow = min(flow, C[pre[i]][i] - F[pre[i]][i]);
		}
		for (int i=E;i!=S;i=pre[i]){
			ans += flow * D[pre[i]][i];
			F[pre[i]][i] += flow;
			F[i][pre[i]] -= flow;
		}
	}
	printf("%d\n", -ans);
	
	
	
	return 0;
}


