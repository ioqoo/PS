#include <bits/stdc++.h>
#define MAX_V 1005
using namespace std;

char grid[101][101];
int verti_group[101][101];
int hori_group[101][101];
int A[5005], B[5005];
vector<int> graph[5005];
bool visited[5005];

bool dfs(int a){
	visited[a] = true;
	for (int b: graph[a]){
		if (B[b]==-1 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(A, A+5005, -1);
	fill(B, B+5005, -1);

	int n;
	cin >> n;
	for (int i=0;i<n;i++){
		string row;
		cin >> row;
		for (int j=0;j<n;j++){
			grid[i][j] = row[j];
		}
	}
	int verti_group_num = -1;
	for (int i=0;i<n;i++){
		char prev = 'X';
		for (int j=0;j<n;j++){
			char curr = grid[i][j];
			if (prev == 'X' && curr == '.'){
				verti_group_num++;
				verti_group[i][j] = verti_group_num;
			}
			else if (prev == '.' && curr == '.'){
				verti_group[i][j] = verti_group_num;
			}
			else if (curr == 'X'){
				verti_group[i][j] = -1;
			}
			prev = curr;
		}
	}


	int hori_group_num = -1;
	for (int j=0;j<n;j++){
		char prev = 'X';
		for (int i=0;i<n;i++){
			char curr = grid[i][j];
			if (prev == 'X' && curr == '.'){
				hori_group_num++;
				hori_group[i][j] = hori_group_num;
			}
			else if (prev == '.' && curr == '.'){
				hori_group[i][j] = hori_group_num;
			}
			else if (curr == 'X'){
				hori_group[i][j] = -1;
			}
			prev = curr;			
		}
	}



	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (verti_group[i][j]!=-1 && hori_group[i][j]!=-1){
				graph[verti_group[i][j]].push_back(hori_group[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i=0;i<verti_group_num+1;i++){
		if (A[i] == -1){
			fill(visited, visited+5005, false);
			if (dfs(i)) ans++;
		}
	}
	printf("%d\n", ans);

}