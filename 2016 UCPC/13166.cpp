#include <bits/stdc++.h>

using namespace std;

const int MAX = 200005;
const int INF = 1e9;

int N, A[MAX], B[MAX], dist[MAX];
bool used[MAX];
vector<int> graph[MAX];

void bfs(){
	queue<int> Q;
	for (int i=0;i<N;i++){
		if (!used[i]){
			dist[i] = 0;
			Q.push(i);
		}
		else dist[i] = INF;
	}
	
	while(!Q.empty()){
		int a = Q.front();
		Q.pop();
		for (int b: graph[a]){
			if (B[b] != -1 && dist[B[b]] == INF){
				dist[B[b]] = dist[a] + 1;
				Q.push(B[b]);
			}
		}
	}
}

bool dfs(int a){
	for (int b: graph[a]){
		if (B[b] == -1 || dist[B[b]] == dist[a]+1 && dfs(B[b])){
			used[a] = true;
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

struct query{
	int u, a, k_a, b, k_b;
};

vector<query> Q;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		int a, k_a, b, k_b;
		scanf("%d %d %d %d", &a, &k_a, &b, &k_b);
		a--; b--;
		Q.push_back({i, a, k_a, b, k_b});
	}
	
	int l = 0, r = 1000000;
	int ans = 1987654321;
	int mid;
	while(l <= r){
		mid =  (l+r) / 2;
		for (int i=0;i<MAX;i++){
			graph[i].clear();
		}
		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));
		memset(dist, 0, sizeof(dist));
		memset(used, 0, sizeof(used));
		
		for (auto q : Q){
			if (mid >= q.k_a){
				graph[q.u].push_back(q.a);
			}
			if (mid >= q.k_b){
				graph[q.u].push_back(q.b);
			}
		}
		
		int match = 0;
		while(1){
			bfs();
			int flow = 0;
			for (int i=0;i<N;i++){
				if (!used[i] && dfs(i)) flow++;
			}
			if (flow == 0) break;
			match += flow;
		}
		if (match == N){
			r = mid-1;
			ans = mid;
		}
		else{
			l = mid+1;
		}
	}
	if (mid!=1987654321){
		printf("%d\n", ans);
	}
	else{
		printf("-1\n");
	}
	
	return 0;
}


