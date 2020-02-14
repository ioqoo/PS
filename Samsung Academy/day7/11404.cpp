#include <iostream>
#include <cstdio>

#define MAX 103
#define INF 987654321

using namespace std;

int N, M;
int dist[MAX][MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &M);
	
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			if (i==j) continue;
			dist[i][j] = INF;
		}
	}
	for (int x=0;x<M;x++){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		dist[u][v] = min(dist[u][v], c);
	}
	
	for (int k=1;k<=N;k++){
		for (int i=1;i<=N;i++){
			for (int j=1;j<=N;j++){
				if (dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			if (dist[i][j] == INF) {
				printf("0 ");
				continue;
			}
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
} 
