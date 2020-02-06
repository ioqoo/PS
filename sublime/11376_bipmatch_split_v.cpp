#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MAX 1001

using namespace std;

int n, m, A[2*MAX], B[MAX];
vector<int> graph[2*MAX];
int visited[2*MAX];

bool dfs(int a){
	visited[a] = true;
	for (int b: graph[a]){
		if (B[b] == 0 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i=1;i<=n;i++){
		int S;
		scanf("%d", &S);
		for (int j=1;j<=S;j++){
			int temp;
			scanf("%d", &temp);
			graph[2*i-1].push_back(temp);
			graph[2*i].push_back(temp);
		}
	}

	int match = 0;
	for (int i=1;i<=2*n;i++){
		if (A[i]==0){
			fill(visited+1, visited+2*n+1, false);
			if (dfs(i)) match++;
		}
	}
	printf("%d\n", match);
}