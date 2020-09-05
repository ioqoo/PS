#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[105][10005];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &K);
	vector<int> coin(N+1);
	for (int i=1;i<=N;i++){
		scanf("%d", &coin[i]);
	}
	
	memset(dp, 0x3f, sizeof(dp));
	for (int i=0;i<=N;i++){
		dp[i][0] = 0;
	}
	for (int i=1;i<=N;i++){
		for (int j=1;j<=K;j++){
			if (j < coin[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = min(dp[i-1][j], dp[i][j-coin[i]] + 1);
		}
	}
//	
//	for (int i=0;i<=N;i++){
//		for (int j=0;j<=K;j++){
//			printf("%d ", dp[i][j] == 0x3f3f3f3f ? -1 : dp[i][j]);
//		}
//		printf("\n");
//	}
	
	printf("%d\n", dp[N][K] == 0x3f3f3f3f? -1 : dp[N][K]);
	
	return 0;
} 
