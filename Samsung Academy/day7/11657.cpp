#include <iostream>
#include <cstdio>
#include <vector>

#define MAX 505
#define INF 987654321
#define pii pair<int, int>

using namespace std;

int N, M;
int dist[MAX];
vector<pii> graph[MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &M);
	for (int i=0;i<M;i++){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		graph[u].push_back(pii(v, c));
	}
	
	for (int i=1;i<=N;i++){
		dist[i] = INF;
	}
	dist[1] = 0;
	bool negcycle = false;
	
	for (int n=1;n<=N;n++){
		for (int curr=1;curr<=N;curr++){
			for (auto p: graph[curr]){
				int next = p.first, weight = p.second;
				if (dist[curr] != INF && dist[next] > dist[curr] + weight){
					dist[next] = dist[curr] + weight;
					
					if (n == N) negcycle = true;
				}
			}
		}
	}
	
	if (negcycle){
		printf("-1\n");
		return 0;
	} 
	
	for (int i=2;i<=N;i++){
		if (dist[i] == INF) printf("-1\n");
		else printf("%d\n", dist[i]);
	}
	
	return 0;
} 
