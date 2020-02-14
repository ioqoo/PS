#include <iostream>
#include <cstdio>


#define MAX 303
#define ll long long

using namespace std;

int N;
int stair[MAX];
int dp[MAX][3];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		scanf("%d", &stair[i]);
	}
	
	dp[1][1] = stair[1];
	dp[1][2] = stair[1];
	
	for (int i=2;i<=N;i++){
		dp[i][1] = dp[i-1][2] + stair[i];
		dp[i][2] = max(dp[i-2][1], dp[i-2][2]) + stair[i];
	}
	
	printf("%d\n", max(dp[N][1], dp[N][2]));
	
	
	
	return 0;
}
