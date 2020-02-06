//#include <iostream>
#include <cstdio>
//#include <string>
//#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K, cnt, ans;
int grid[101][101];
bool visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y){
	visited[x][y] = true;
	for (int i=0;i<4;i++){
		int cx = x+dx[i], cy = y+dy[i];
		if ( cx >=0 || cx <N || cy >=0 || cy <N){
			if (grid[cx][cy] && !visited[cx][cy]) {
				cnt++;
				dfs(cx, cy);
			}
		} 
	}
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	for (int i=0;i<K;i++){
		int r, c;
		scanf("%d %d", &r, &c);
		grid[r-1][c-1] = 1;
	}

	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			if (grid[i][j] == 1 && !visited[i][j]) {
				cnt = 1;
				dfs(i, j);
				if (cnt > ans) ans = cnt;
			}
		}
	}
	printf("%d", ans);
}