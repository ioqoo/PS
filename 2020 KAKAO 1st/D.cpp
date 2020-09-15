#include <bits/stdc++.h>
const int MAX = 205;
const int INF = 987654321;
using namespace std;

int N, S, A, B;
int dist[MAX][MAX];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	N = n; S = s; A = a; B = b;
	
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			if (i != j) dist[i][j] = INF;
		}
	}
	
	for (auto vt: fares){
		int u = vt[0], v = vt[1], w = vt[2];
		dist[u][v] = dist[v][u] = w;
	}
	
	for (int k=1;k<=N;k++){
		for (int i=1;i<=N;i++){
			for (int j=1;j<=N;j++){
				if (dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	int answer = INF;
	for (int i=1;i<=N;i++){
		if (dist[S][i] != INF && dist[i][A] != INF && dist[i][B] != INF){
			answer = min(answer, dist[S][i] + dist[i][A] + dist[i][B]);
			
		}
	}
	
    
    return answer;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	return 0;
}

