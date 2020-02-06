#include <bits/stdc++.h>
#define INF 123456789
#define pii pair<int, int>

using namespace std;

int N, M;
int dist[500];
vector<pii> graph[500];

int main(){
	scanf("%d %d", &N, &M);
	fill (dist, dist+N, INF);
	for(int i=0;i<M;i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u-1].push_back(pii(v-1, w));
	}
	dist[0] = 0;
	bool neg_cycle = false;
	for (int i=0;i<N;i++){ // N-1번 루프 돌고 마지막 1번은 음수 사이클 확인용
		for (int j=0;j<N;j++){
			for(auto &p: graph[j]){
				int next = p.first, d = p.second;
				if (dist[j]!=INF && dist[next] > dist[j] + d){
					dist[next] = dist[j] + d;
					if (i == N-1) neg_cycle = true;
					// N번째에도 값이 갱신되면 음수 사이클 존재
				}
			}
		}
	}
	if (neg_cycle) printf("-1\n");
	else {
		for (int i=1;i<N;i++){
			printf("%d\n", dist[i]==INF ? -1 : dist[i]);
		}
	}
}