#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 505;
using namespace std;

struct P{
	int i, j;
	
};

int N, M;
int dist[MAX][MAX];
P S, D;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
bool visited[MAX][MAX];
int dist2[MAX][MAX];

bool is_out(int i, int j){
	if (i < 0 || i >= N || j < 0 || j >= M) return true;
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	string line;
	vector<P> tree;
	queue<P> Q;
//	memset(dist, 0x3f, sizeof(dist));
	for (int i=0;i<N;i++){
		cin >> line;
		for (int j=0;j<M;j++){
			if (line[j] == '+'){
				tree.push_back({i, j});
//				dist[i][j] = 0;
				Q.push({i, j});
				visited[i][j] = true;
			}
			else if (line[j] == 'V'){
				S = {i, j};
			}
			else if (line[j] == 'J'){
				D = {i, j};
			}
		}
	}
	
	
	while(!Q.empty()){
		auto p = Q.front(); Q.pop();
		int ci = p.i, cj = p.j;
		for (int d=0;d<4;d++){
			int ni = ci + di[d], nj = cj + dj[d];
			if (is_out(ni, nj)) continue;
			if (visited[ni][nj]) continue;
			dist[ni][nj] = dist[ci][cj] + 1;
			visited[ni][nj] = true;
			Q.push({ni, nj});
		}
	}
//	for (int i=0;i<N;i++){
//		for (int j=0;j<M;j++){
//			printf("%d ", dist[i][j]);
//		}
//		printf("\n");
//	}
	
	memset(visited, 0, sizeof(visited));
//	memset(dist, 0x3f, sizeof(dist));
	
//	dist[S.i][S.j] = 0;
	visited[S.i][S.j] = true;
	priority_queue<pair<int, pii>> PQ;
	PQ.push({dist[S.i][S.j], {S.i, S.j}});
	int ans = dist[S.i][S.j];
//	printf("%d\n", ans);
	while(!PQ.empty()){
		auto p = PQ.top(); PQ.pop();
		int curr_dist = p.first, ci = p.second.first, cj = p.second.second;
//		printf("%d / %d %d\n", curr_dist, ci, cj);
//		printf("%d\n", ans);
		ans = min(ans, curr_dist);
		if (D.i == ci && D.j == cj) break;
		for (int d=0;d<4;d++){
			int ni = ci + di[d], nj = cj + dj[d];
			if (is_out(ni, nj)) continue;
			if (visited[ni][nj]) continue;
			PQ.push({dist[ni][nj], {ni, nj}});
			visited[ni][nj] = true;
//			ans = min(ans, dist[ni][nj]);
		}
	}
	printf("%d\n", ans);
	
	
	return 0;
}

