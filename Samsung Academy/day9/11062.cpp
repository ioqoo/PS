#include <iostream>
#include <cstring>

#define MAX 1005

using namespace std;

int T;
int N;
int cards[MAX];
int dp[MAX][MAX][2]; // 0 : ³ª, 1 : »ó

void DEBUG(){
	for (int k=0;k<2;k++){
		for (int i=1;i<=N;i++){
			for (int j=1;j<=N;j++){
				printf("%d ", dp[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	printf("\n");
	printf("\n");
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d", &T);
	for (int t=0;t<T;t++){
		memset(cards, 0, sizeof(cards));
		memset(dp, 0, sizeof(dp));
		scanf("%d", &N);
		for (int i=1;i<=N;i++){
			scanf("%d", &cards[i]);
		}
		
		for (int i=1;i<=N;i++){
			dp[i][i][0] = cards[i];
		}
		
		for (int i=1;i<=N-1;i++){
			dp[i][i+1][0] = max(cards[i], cards[i+1]);
			dp[i][i+1][1] = min(cards[i], cards[i+1]); 
		}
		
		for (int d=2;d<=N-1;d++){
			for (int i=1;i+d<=N;i++){
				int j = i + d;
				dp[i][j][0] = max(cards[i] + dp[i+1][j][1], dp[i][j-1][1] + cards[j]);
				dp[i][j][1] = min(dp[i+1][j][0], dp[i][j-1][0]);
			}
		}
//		DEBUG();
		printf("%d\n", dp[1][N][0]);
	}
	
	
	
	return 0;
}
