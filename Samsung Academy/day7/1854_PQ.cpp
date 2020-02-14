#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

#define pii pair<int, int>
#define MAX 1003
#define INF 987654321

using namespace std;

int N, M, K;
vector<pii> graph[MAX];
priority_queue<int> PQ[MAX]; 
priority_queue<pii, vector<pii>, greater<pii>> dijk_PQ; // (dist, node)



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d %d", &N, &M, &K);
	for (int i=0;i<M;i++){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		graph[u].push_back(pii(v, c));
	}
	
	PQ[1].push(0);
	dijk_PQ.push(pii(0, 1));
	while(!dijk_PQ.empty()){
		auto p = dijk_PQ.top();
		dijk_PQ.pop();
		int curr_dist = p.first, curr = p.second;
		for (auto pp: graph[curr]){
			int next = pp.first, weight = pp.second;
			int cand = curr_dist + weight;
			if (PQ[next].size() < K){
				PQ[next].push(cand);
				dijk_PQ.push(pii(cand, next));
			}
			else if (PQ[next].top() > cand){
				PQ[next].pop();
				PQ[next].push(cand);
				dijk_PQ.push(pii(cand, next));
			}
		}
	}
	for (int i=1;i<=N;i++){
		if (PQ[i].size() < K) printf("-1\n");
		else printf("%d\n", PQ[i].top());
	}
	
	
	
	return 0;
} 
