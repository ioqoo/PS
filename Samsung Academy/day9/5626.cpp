#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX 10005
#define ll long long
#define MOD 1000000007

using namespace std;

int N;
int height[MAX];
ll dp[2][MAX/2]; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

	scanf("%d", &N);
	for (int i=0;i<N;i++){
		scanf("%d", &height[i]);
	}
	
	if (N==1 && height[0] != -1 && height[0] != 0){
		printf("0\n");
		return 0;
	}
	
	dp[0][0] = 1LL;
	for (int i=1;i<N;i++){
		int curr_height = height[i];
		if (curr_height != -1){
			dp[1][curr_height] += dp[0][curr_height+1]; dp[1][curr_height] %= MOD;
			dp[1][curr_height] += dp[0][curr_height]; dp[1][curr_height] %= MOD;
			if (curr_height-1>=0) {
				dp[1][curr_height] += dp[0][curr_height-1];
				dp[1][curr_height] %= MOD;
			}
		}
		else{
			for (int j=0;j<=N/2;j++){
				dp[1][j] += dp[0][j]; dp[1][j] %= MOD;
				dp[1][j] += dp[0][j+1]; dp[1][j] %= MOD;
				if (j-1>=0) {
					dp[1][j] += dp[0][j-1];
					dp[1][j] %= MOD;
				}
			}
		}
		for (int i=0;i<N;i++){
			dp[0][i] = dp[1][i];
		}
		memset(dp[1], 0, sizeof(dp[1]));		
//		for (int i=0;i<N;i++){
//			printf("%lld ", dp[0][i]);
//		}
//		printf("\n");
	}
	printf("%lld\n", dp[0][0]);
	

    return 0;
}
    
