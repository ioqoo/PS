#include <iostream>

#define MAX 105
#define INF 1987654321
#define ll long long

using namespace std;

int N, M;
int bytes[MAX];
int costs[MAX];
int dp[MAX][MAX*MAX]; // dp[i][j] = i-th 앱까지 사용하여 j cost로 만들 수 있는 최대 byte 값 

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++){
    	scanf("%d", &bytes[i]);
	}
	
	for (int i=0;i<N;i++){
		scanf("%d", &costs[i]);
	}
	
	dp[0][costs[0]] = bytes[0];
	
	int ans = INF;
	
	for (int i=1;i<N;i++){
		for (int j=0;j<MAX*MAX;j++){
			if (j - costs[i] >= 0){ // i-th 앱을 비활성화할 때 byte 최대화 
				dp[i][j] = max(dp[i][j], dp[i-1][j-costs[i]] + bytes[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i-1][j]); // 이번 앱에서 아무 것도 안 할 때 
			
			if (dp[i][j] >= M) ans = min(ans, j);
		}
	}
	
	printf("%d\n", ans);
	
	
    
    

    return 0;
}
