#include <bits/stdc++.h>
#define ll long long
#define pil pair<int, ll>
const ll INF = 9e18;
const int MAX = 100005;
using namespace std;

struct info{
	int curr;
	ll dist;
//	int parity;
};

struct cmp{
	bool operator () (info A, info B){
		return A.dist > B.dist;
	}
};

int N, M;
vector<pil> graph[MAX];
priority_queue<info, vector<info>, cmp> PQ;
ll dist[MAX][2]; // 0 : even, 1 : odd

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d", &N, &M);
	for (int i=0;i<M;i++){
		int u, v;
		ll w;
		scanf("%d %d %lld\n", &u, &v, &w);
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	
	for (int i=1;i<=N;i++){
		dist[i][0] = dist[i][1] = INF;
	}
	
	dist[1][0] = 0;
	PQ.push({1, 0});
	while(!PQ.empty()){
		auto p = PQ.top(); PQ.pop();
		int curr = p.curr;
		ll curr_dist = p.dist;
//		if (dist[curr][0] != -1 && dist[curr][0] < curr_dist && dist[curr][1] != -1 && dist[curr][0] < curr_dist) continue;
//		int curr_parity = p.parity;
		if (curr_dist%2 == 0){
			if (dist[curr][0] < curr_dist) continue;
		}
		else{
			if (dist[curr][1] < curr_dist) continue;
		}
		for (auto pp: graph[curr]){
			int next = pp.first;
			ll weight = pp.second;

			if ((curr_dist + weight)%2 == 0){ // even
				if (curr_dist + weight < dist[next][0]){
					dist[next][0] = curr_dist + weight;
					PQ.push({next, dist[next][0]});
				}
			}
			else{
				if (curr_dist + weight < dist[next][1]){
					dist[next][1] = curr_dist + weight;
					PQ.push({next, dist[next][1]});
				}
			}
		}
	}
	
	for (int i=1;i<=N;i++){
		printf("%lld %lld\n", dist[i][1]==INF?-1:dist[i][1] , dist[i][0]==INF?-1:dist[i][0]);
	}
	
	return 0;
}


