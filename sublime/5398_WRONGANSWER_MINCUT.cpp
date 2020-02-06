#include <bits/stdc++.h>
#define MAX_V 1005

using namespace std;

pair<char, int> grid[2005][2005];
int A[MAX_V], B[MAX_V];
vector<int> graph[1005];
bool visited[MAX_V];

bool dfs(int a){
	visited[a] = true;
	for (int b: graph[a]){
		if (B[b]==0 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		for (int i=0;i<2005;i++){
			for (int j=0;j<2005;j++){
				grid[i][j] = make_pair('0',-1);
			}
		}
		memset(graph, 0, sizeof(graph));
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(visited, false, sizeof(visited));
		int h,v;
		cin >> h >> v;
		for (int i=1;i<=h;i++){
			int m, n;
			string word;
			cin >> m >> n >> word;
			int word_size = word.size();
			for (int j=0;j<word_size;j++){
				grid[n][m+j] = make_pair(word[j], i);
			}
		}
		for (int i=1;i<=v;i++){
			int m, n;
			string word;
			cin >> m >> n >> word;
			int word_size = word.size();
			for (int k=0;k<word_size;k++){
				if (grid[n+k][m].second!=-1){
					if (grid[n+k][m].first != word[k]){
						int u = grid[n+k][m].second;
						graph[u].push_back(500+i);
					}
				}
			}
		}

		int match = 0;
		for (int i=1;i<=h;i++){
			if (A[i]==0){
				fill(visited, visited+h, false);
				if (dfs(i)) match++;
			}
		}
		cout << h+v-match << "\n";
	}

}
