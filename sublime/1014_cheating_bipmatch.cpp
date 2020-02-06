#include <bits/stdc++.h>
#define ll long long
using namespace std;

int seat[11][11];
int C[102][102];
int F[102][102];
vector<int> graph[102];
int dx[] = {0, 1, 0, 1};
int dy[] = {-1, -1, 1, 1};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		memset(seat, 0, sizeof(seat));
		memset(C, 0, sizeof(C));
		memset(F, 0, sizeof(F));
		for (int i=0;i<102;i++){
			graph[i].clear();
		}

		int n, m;
		cin >> n >> m;
		int seat_num = 1;
		for (int i=1;i<=n;i++){
			string row;
			cin >> row;
			for (int j=0;j<m;j++){
				if (row[j] == '.'){
					seat[i][j+1] = seat_num++;
				}
				else{
					seat[i][j+1] = -1;
				}
			}
		}

		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				int u = seat[i][j];
				if (u!=-1){
					for (int k=0;k<4;k++){
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (1 <= nx && nx <= n && 1 <= ny && ny <= m){
							if (seat[nx][ny]!=-1){
								int v = seat[nx][ny];
								graph[u].push_back(v);
								graph[v].push_back(u);
								C[u][v] = 1;
							}
						}
					}
				}
			}
		}

		for (int i=1;i<seat_num;i++){
			graph[0].push_back(i);
			C[0][i] = 1;
			graph[i].push_back(101);
			C[i][101] = 1;
		}

		int ans = 0;
		while(1){
			int prev[102];
			fill(prev, prev+102, -1);
			queue<int> Q;
			Q.push(0);
			while(!Q.empty() && prev[101] == -1){
				int curr = Q.front();
				Q.pop();
				for(auto next: graph[curr]){
					if (C[curr][next] - F[curr][next] > 0 && prev[next] == -1){
						Q.push(next);
						prev[next] = curr;
						if (next==101) break;
					}
				}
			}
			if (prev[101] == -1) break;

			for (int i=1;i!=0;i=prev[i]){
				F[prev[i]][i] += 1;
				F[i][prev[i]] -= 1;
			}
			ans += 1;
		}		
		cout << ans << "\n";
	}
}