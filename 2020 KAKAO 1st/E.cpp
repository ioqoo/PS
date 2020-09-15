#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
const int INF = 10000;
using namespace std;

int dp[1<<17][4][4];
int grid[4][4];
int dist[4][4];
map<pii, pii> Link;
int init;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

int pii_to_int(int a, int b){
	return a*4 + b;
}

pii int_to_pii(int a){
	return make_pair(a/4, a%4);
}

void pre_grid(vector<vector<int>> board){
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			grid[i][j] = board[i][j];
			if (grid[i][j] != 0){
				init |= (1 << pii_to_int(i, j));
			}
		}
	}
	
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			if (grid[i][j] == 0) continue;
			for (int k=0;k<4;k++){
				for (int l=0;l<4;l++){
					if (i==k && j==l) continue;
					if (grid[i][j] == grid[k][l]){
						Link[{i, j}] = {k, l};
						Link[{k, l}] = {i, j};
					}
				}
			}
		}
	}
}

pii ctrlup(int stat, int i, int j){
	while(i>0){
		i--;
		if (stat & (1 << pii_to_int(i, j)) break;
	}
	return {i, j};
}

pii ctrlleft(int stat, int i, int j){
	while(j > 0){
		j--;
		if (stat & (1 << pii_to_int(i, j)) break;
	}
	return {i, j};
}

pii ctrldown(int stat, int i, int j){
	while(i < 3){
		i++;
		if (stat & (1 << pii_to_int(i, j)) break;
	}
	return {i, j};
}

pii ctrlright(int stat, int i, int j){
	while(j < 3){
		j++;
		if (stat & (1 << pii_to_int(i, j)) break;
	}
	return {i, j};
}


int get_dist(int stat, int si, int sj, int ei, int ej){
	memset(dist, 0x3f, sizeof(dist));
	dist[si][sj] = 0;
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> PQ;
	PQ.push({0, (si, sj));
	while(!PQ.empty()){
		auto p = PQ.top(); PQ.pop();
		int curr_dist = p.f.f;
		auto curr = p.s;
		if (curr_dist > dist[curr.f][curr.s]) continue;
		int ci = curr.f, cj = curr.s;
		for (int d=0;d<4;d++){
			int ni = ci + di[d], nj = cj + dj[d];
			if (ni < 0 || ni > 4 || nj < 0 || nj > 4) continue;
			if (dist[ni][nj] > dist[ci][cj] + 1){
				dist[ni][nj] = dist[ci][cj] + 1;
				PQ.push({dist[ni][nj], {ni, nj}});
			}
		}
		
		pii goup = ctrlup(ci, cj);
		if (dist[goup.f][goup.s] > dist[ci][cj] + 1) {
			dist[goup.f][goup.s] = dist[ci][cj] + 1;
			PQ.push({dist[goup.f][goup.s], {goup.f, goup.s}});
		}
		
		pii godown = ctrldown(Ci, cj);
		if (Dist[godown.f][godown.s] > dist[ci][cj] + 1){
			dist[goup.f][goup.s] = dist[ci][cj]+1;
			PQ.push({dist[goup.}
		}
		
		
//		if ( (curr%4) > 0 ) PQ.push({curr_dist + 1, curr-1});
//		if ( (curr%4) < 3 ) PQ.push({curr_dist + 1, curr+1});
//		if ( (curr/4) > 0) PQ.push({curr_dist + 1, curr - 4});
//		if ( (curr/4) < 3 ) PQ.push({curr_dist + 1, curr + 4});
//		
//		int ctrlup = (curr%4);
//		for (int temp = curr - 4; temp >= 0; temp -= 4){
//			if (stat & (1 << temp)) {
//				ctrlup = temp;
//				break;
//			}
//		}
//		PQ.push({curr_dist + 1, ctrlup});
//		
//		int ctrlleft = (curr/4) * 4;
//		for (int temp = curr - 1; temp >= (temp/4)*4; temp--){
//			if (stat & (1 << temp)) {
//				ctrlleft = temp;
//				break;
//			}
//		}
//		PQ.push({curr_dist + 1, ctrlleft});
//		
//		int ctrlright = (curr/4 + 1) * 4 - 1;
//		for (int temp = curr + 1; temp <= (temp/4 + 1) * 4 - 1; temp++){
//			if (stat & (1 << temp)){
//				ctrlright = temp;
//				break;
//			}
//		}
//		PQ.push({curr_dist + 1, ctrlright});
//		
//		int ctrldown = 12 + (curr%4);
//		for (int temp = curr + 4; temp <= 15; temp += 4){
//			if (stat & (1 << temp)){
//				ctrldown = temp;
//				break;
//			}
//		}
//		PQ.push({curr_dist + 1, ctrldown});
	}
	return dist[pii_to_int(ei, ej)];
}

int solve(int stat, int r, int c){
	if (stat == 0) return 0;
	
	int &ret = dp[stat][r][c];
	if (ret != -1) return ret;
	
	int temp = INF;
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			if (stat && (1 << (pii_to_int(i, j)))) {
				temp = min(temp, get_dist(stat, r, c, i, j) + get_dist(stat, i, j, Link[{i, j}].f, Link[{i, j}].s) + solve( (stat ^ (1 << pii_to_int(i, j)) ^ (1 << pii_to_int(Link[{i, j}].f, Link[{i, j}].s))) , Link[{i, j}].f, Link[{i, j}].s ) + 2);
			}
		}
	}
	return ret = temp;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    memset(dp, -1, sizeof(dp));
    pre_grid(board);
    answer = solve(init, r, c);
    
    return answer;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<vector<int>> G;
	for (int i=0;i<4;i++){
		vector<int> row;
		for (int j=0;j<4;j++){
			int temp;
			scanf("%d", &temp);
			row.push_back(temp);
		}
		G.push_back(row);
	}
//	pre_grid(G);
	
//	printf("%d\n", get_dist(init, 1, 1, 0, 0));
	
	printf("%d", solution(G, 1, 0));
	
	return 0;
}

