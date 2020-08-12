#include <bits/stdc++.h>
const int MAX = 105;
const int INF = 0x3f3f3f3f;
using namespace std;

struct info{
	int curr_dist, curr_cost, curr;
	
};

bool operator < (const info& a, const info &b){
	return a.curr_dist > b.curr_dist;
}

struct edge{
	int to, time, cost;
};

int N, M, K;
vector<edge> graph[MAX];
int dist[MAX][10005]; // dp[i][j] : i번 공항까지 j원을 써서 갈 수 있는 최단 시간 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &N, &M, &K);
		memset(dist, 0x3f, sizeof(dist));
		for (int i=1;i<=N;i++){
			graph[i].clear();
		}
		for (int i=0;i<K;i++){
			int u, v, c, d;
			scanf("%d %d %d %d", &u, &v, &c, &d);
			graph[u].push_back({v, d, c});
		}
		
		priority_queue<info> PQ;
		dist[1][0] = 0;
		PQ.push({0, 0, 1});
		while(!PQ.empty()){
			auto p = PQ.top(); PQ.pop();
			if (dist[p.curr][p.curr_cost] < p.curr_dist) continue;
			for (auto pp: graph[p.curr]){
//				printf("%d %d %d\n", pp.to, p.curr_cost, pp.cost);
				if (p.curr_cost + pp.cost > M) continue;
				if (dist[pp.to][p.curr_cost + pp.cost] > dist[p.curr][p.curr_cost] + pp.time){
					dist[pp.to][p.curr_cost + pp.cost] = dist[p.curr][p.curr_cost] + pp.time;
					PQ.push({dist[p.curr][p.curr_cost] + pp.time, p.curr_cost + pp.cost, pp.to});
				}
			}
		}
		int ans = INF;
		for (int i=1;i<=M;i++){
			ans = min(ans, dist[N][i]);
		}
		if (ans == INF) printf("Poor KCM\n");
		else printf("%d\n", ans);
		
	}	
	
	return 0;
}


