#include <iostream>
#include <cstdio>
#include <vector>

#define MAX 205
#define INF 987654321
#define pii pair<int, int>
#define ll long long

using namespace std;

int N, K;
int colors[MAX];
int dp[MAX][MAX][21];

void DEBUG(){
	for (int k=1;k<=3;k++){
		for (int i=1;i<=N;i++){
			for (int j=1;j<=N;j++){
				printf("%d ", dp[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
		printf("\n");
	}
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

	scanf("%d %d", &N, &K);
	for (int i=1;i<=N;i++){
		scanf("%d", &colors[i]);
	}
	
	
	for (int i=1;i<=N-1;i++){
		int color_l = colors[i], color_r = colors[i+1];
		if (color_l == color_r) continue;
		dp[i][i+1][color_l] = 1;
		dp[i][i+1][color_r] = 1;
	}
	
	for (int d=2;d<=N-1;d++){
		for (int i=1;i<=N-d;i++){
			int j = i + d;
			int curr_min = INF;
			for (int k=i;k<j;k++){
				int left_leftcol = dp[i][k][colors[i]];
				int right_leftcol = dp[k+1][j][colors[k+1]];
				if (colors[i] == colors[k+1]){
					curr_min = min(curr_min, left_leftcol + right_leftcol);
				}
				else{
					curr_min = min(curr_min, left_leftcol + right_leftcol + 1);
				}
			}
			dp[i][j][colors[i]] = curr_min;
		}
	}
	
//	DEBUG();
	
	

	printf("%lld\n", dp[1][N][colors[1]]);
	
	

    return 0;
}
    
