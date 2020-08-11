#include <bits/stdc++.h>
const int MAX = 105;
#define pii pair<int, int>
using namespace std;

int W, H;
int grid[MAX][MAX];
vector<pii> C;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int dist[MAX][MAX];
bool visited[MAX][MAX][4];

bool is_out(int i, int j){
	if (i < 0 || i >= H || j < 0 || j >= W) return true;
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	
	scanf("%d %d\n", &W, &H);
	memset(dist, 0x3f, sizeof(dist));
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			char temp;
			scanf("%c", &temp);
			if (temp == '.') grid[i][j] = 1;
			else if (temp == '*') grid[i][j] = 0;
			else if (temp == 'C') {
				grid[i][j] = 1;
				C.push_back({i, j});
			}
		}
		scanf("\n");
	}	
	
	pii S = C[0];
	queue<pair<pii, pii>> Q; // up down left right ~ 0 1 2 3
	dist[S.first][S.second] = 0;
	fill(visited[S.first][S.second], visited[S.first][S.second]+4, true);
	for (int d=0;d<4;d++){
		int ni = S.first + di[d], nj = S.second + dj[d];
		if (is_out(ni, nj)) continue;
		if (grid[ni][nj] == 0) continue;
		dist[ni][nj] = 0;
		Q.push({{ni, nj}, {d, 0}});
		visited[ni][nj][d] = true;
	}
	while(!Q.empty()){
//		for (int i=0;i<H;i++){
//			for (int j=0;j<W;j++){
//				printf("%3d ", dist[i][j] == 0x3f3f3f3f ? -1 : dist[i][j]);
//			}
//			printf("\n");
//		}
//		
//		printf("\n");
		
		
		auto p = Q.front(); Q.pop();
		for (int d=0;d<4;d++){
			int ni = p.first.first + di[d], nj = p.first.second + dj[d];
			if (is_out(ni, nj)) continue;
			if (grid[ni][nj] == 0) continue;
//			if (visited[ni][nj][d]) continue;
			if (p.second.first == 0 || p.second.first == 1){ // up down
				if (d == 0 || d == 1){
					if (p.second.first != d) continue;
//					if (p.second.second >= dist[ni][nj]) continue;
					dist[ni][nj] = min(dist[ni][nj], p.second.second);
					Q.push({{ni, nj}, {d, p.second.second}});
//					visited[ni][nj][d] = true;
				}
				else if (d == 2 || d == 3){
					if (p.second.second+1 > dist[ni][nj]) continue;
					dist[ni][nj] = min(dist[ni][nj], p.second.second + 1);
					Q.push({{ni, nj}, {d, p.second.second+1}});
//					visited[ni][nj][d] = true;
				}
			}
			else if (p.second.first == 2 || p.second.first == 3){
				if (d == 0 || d == 1){
					if (p.second.second+1 > dist[ni][nj]) continue;
					dist[ni][nj] = min(dist[ni][nj], p.second.second + 1);
					Q.push({{ni, nj}, {d, p.second.second+1}});
//					visited[ni][nj][d] = true;
				}
				else if (d == 2 || d == 3){			
					if (p.second.first != d) continue;
					if (p.second.second >= dist[ni][nj]) continue;
					dist[ni][nj] = min(dist[ni][nj], p.second.second);
					Q.push({{ni, nj}, {d, p.second.second}});
//					visited[ni][nj][d] = true;
				}
			}
		}
	}
//	for (int i=0;i<H;i++){
//		for (int j=0;j<W;j++){
//			printf("%3d ", dist[i][j] == 0x3f3f3f3f ? -1 : dist[i][j]);
//		}
//		printf("\n");
//	}
	
	printf("%d\n", dist[C[1].first][C[1].second]);
	
	return 0;
}


