#include <iostream>
#include <queue>
#include <cstring>
const int NMAX = 2005;
const int PMAX = 100005;

using namespace std;

struct node{
	int i, j;
};

int N, K;
int grid[NMAX][NMAX];
int par[PMAX];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

bool is_out(int i, int j){
	if (i < 0 || i >= N || j < 0 || j >= N) return true;
	return false;
}

int find(int a){
	if (par[a] == -1) return a;
	return par[a] = find(par[a]);
}

void merge(int a, int b){
	int roota = find(a);
	int rootb = find(b);
	if (roota == rootb) return;
	par[roota] = rootb;
	K--;
	return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &K);
	
	memset(par, -1, sizeof(par));
	
	queue<node> UF_Q;
	queue<node> BFS_Q;
	
	// 처음부터 다 붙어있는 코너 케이스 생각해보면
	// merge를 먼저 한 다음 모두 결합 되어있는지 여부를 체크한 뒤에
	// 영토 확장을 하고 햇수를 추가해야 한다는 것을 알 수 있다 
	
	for (int i=0;i<K;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		grid[a][b] = i+1;
		UF_Q.push({a, b});
	}
	
	
	int year = 0;
	while(1){
		while(!UF_Q.empty()){
			auto p = UF_Q.front(); UF_Q.pop(); BFS_Q.push(p);
			int ci = p.i, cj = p.j;
			for (int d=0;d<4;d++){
				int ni = ci + di[d], nj = cj + dj[d];
				if (is_out(ni, nj)) continue;
				if (grid[ni][nj] != 0){
					merge(grid[ci][cj], grid[ni][nj]);
				}
			}
		}
		
		if (K==1) break;
		
		while(!BFS_Q.empty()){
			auto p = BFS_Q.front(); BFS_Q.pop();
			int ci = p.i, cj = p.j;
			for (int d=0;d<4;d++){
				int ni = ci + di[d], nj = cj + dj[d];
				if (is_out(ni, nj)) continue;
				if (grid[ni][nj] == 0){
					grid[ni][nj] = grid[ci][cj];
					UF_Q.push({ni, nj});
				}
			}
		}
		
		year++;
	}
	
	printf("%d\n", year);
	
	return 0;
}
