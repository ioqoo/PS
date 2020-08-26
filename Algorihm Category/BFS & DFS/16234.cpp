#include <iostream>
#include <queue>
#include <cstring>

const int NMAX = 55;
const int MAX = 2505;
using namespace std;

struct P{
	int i, j;
};

int N, L, R;
int grid[NMAX][NMAX];
int comp_num[NMAX][NMAX];
int comp_total[MAX];
int comp_total_cnt[MAX];
bool visited[NMAX][NMAX];
int comp_cnt = 0;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

bool is_out(int i, int j){
	if (i < 0 || i >= N || j < 0 || j >= N) return true;
	return false;
}


void init(){
	memset(comp_num, 0, sizeof(comp_num));
	memset(comp_total, 0, sizeof(comp_total));
	memset(comp_total_cnt, 0, sizeof(comp_total_cnt));
	memset(visited, 0, sizeof(visited));
}

void BFS(){
	init();
	comp_cnt = 0;
	
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (visited[i][j]) continue;
			
			comp_cnt++;
			queue<P> Q;
			Q.push({i, j});
			visited[i][j] = true;
			comp_num[i][j] = comp_cnt;
			comp_total_cnt[comp_cnt]++;
			comp_total[comp_cnt] += grid[i][j];
			while(!Q.empty()){
				auto p = Q.front(); Q.pop();
				for (int d=0;d<4;d++){
					int ni = p.i + di[d], nj = p.j + dj[d];
					if (is_out(ni, nj)) continue;
					int diff = abs(grid[p.i][p.j] - grid[ni][nj]);
					if (diff < L || diff > R) continue;
					if (visited[ni][nj]) continue;
					comp_num[ni][nj] = comp_cnt;
					visited[ni][nj] = true;
					comp_total[comp_cnt] += grid[ni][nj];
					comp_total_cnt[comp_cnt]++;
					Q.push({ni, nj});
				}
			}
		}
	}
}

bool chk(){
	int comp = grid[0][0];
	bool ret = false;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (grid[i][j] != comp){
				ret = true;
			}
		}
	}
	return ret;
}

void move(){
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			grid[i][j] = comp_total[comp_num[i][j]] / comp_total_cnt[comp_num[i][j]];
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d %d", &N, &L, &R);
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			scanf("%d", &grid[i][j]);
		}
	}
	
//	for (int i=0;i<N;i++){
//		for (int j=0;j<N;j++){
//			printf("%d ", comp_num[i][j]);
//		}
//		printf("\n");
//	}
	
	int ans = 0;
	while(1){
		BFS();
		if (comp_cnt == N*N) break;
		if (chk()){
			move();
			ans++;
		}
		else break;
	}
	printf("%d\n", ans);
	
	
	
	return 0;
}


