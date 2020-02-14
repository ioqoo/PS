#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 105
#define INF 987654321
#define ll long long

using namespace std;

int N, K;
int coins[MAX];
int dp[10005];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    scanf("%d %d", &N, &K);
    for (int i=0;i<N;i++){
    	scanf("%d", &coins[i]);
	}
	
	for (int i=1;i<=K;i++){
		dp[i] = INF;
	}
	
	for (int i=0;i<N;i++){
		for (int j=1;j<=K;j++){
			if (j - coins[i] < 0) continue;
			dp[j] = min(dp[j], dp[j-coins[i]] + 1);
		}
	}
    
    if (dp[K] == INF) printf("-1");
    else printf("%d\n", dp[K]);

    return 0;
}
