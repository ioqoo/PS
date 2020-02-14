#include <iostream>
#include <cstdio>


#define MAX 1005
#define ll long long

using namespace std;

int N, M;
int grid[MAX][MAX];
int dp[MAX][MAX];
int ans;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
	scanf("%d %d", &N, &M);
	for (int i=1;i<=N;i++){
		for (int j=1;j<=M;j++){
			scanf("%1d", &grid[i][j]);
		}
	}
	
	for (int i=1;i<=N;i++){
		for (int j=1;j<=M;j++){
			if (grid[i][j] == 0) continue;
			dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n", ans*ans);
	
	return 0;
}
