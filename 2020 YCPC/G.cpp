#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 205;

using namespace std;

int N, M;
char grid[MAX][MAX];
bool keys[26];
int S_i, S_j;
int D_i, D_j;
bool visited[MAX][MAX];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
bool chk[MAX][MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i=0;i<N;i++){
		string row;
		cin >> row;
		for (int j=0;j<M;j++){
			grid[i][j] = row[j];
			if (grid[i][j] == '@'){
				S_i = i, S_j = j;
				grid[i][j] = '*';
			}
			else if (grid[i][j] == '!'){
				D_i = i, D_j = j;
			}
		}
	}
	
	queue<pii> Q;
	Q.push({S_i, S_j});
	vector<pii> ans;
	bool succ = false;
	while(!Q.empty()){
		if (succ) break;
		auto p = Q.front(); Q.pop();
		int ci = p.first, cj = p.second;
		if (!chk[ci][cj]){
			ans.push_back({ci, cj});
			chk[ci][cj] = true;
		}
//		cout << ci+1 << " " << cj+1 << "\n";
		for (int d=0;d<4;d++){
			int ni = ci + di[d], nj = cj + dj[d];
			if (visited[ni][nj]) continue;
			if (grid[ni][nj] == '#') continue;
			if ('a' <= grid[ni][nj] && grid[ni][nj] <= 'z'){
				if (keys[grid[ni][nj]-'a']){
					grid[ni][nj] = '*';
					visited[ni][nj] = true;
					Q.push({ni, nj});
				}
				else{
					keys[grid[ni][nj]-'a'] = true;
					for (int i=0;i<N;i++){
						for (int j=0;j<M;j++){
							if (grid[i][j] == grid[ni][nj]-'a'+'A'){
								grid[i][j] = '*';
							}
						}
					}
					while(!Q.empty()){
						Q.pop();
					}
					memset(visited, 0, sizeof(visited));
					Q.push({ni, nj});
					visited[ni][nj] = true;
					break;
				}
			}
			else if (grid[ni][nj] == '*'){
				visited[ni][nj] = true;
				Q.push({ni, nj});
			}
			else if (grid[ni][nj] == '!'){
				if (!chk[ni][nj]){
					ans.push_back({ni, nj});
					chk[ni][nj] = true;
				}
				succ = true;
//				cout << ni+1 << " " << nj+1 << "\n";
				break;
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto p: ans){
		cout << p.first+1 << " " << p.second+1 << "\n";
	}		
	
	
	
	return 0;
}


