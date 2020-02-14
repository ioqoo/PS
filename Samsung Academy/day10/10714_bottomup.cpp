#include <iostream>

#define MAX 2005
#define ll long long

using namespace std;

int N;
ll cakes[MAX];
ll dp[MAX][MAX][2]; // 0: first, 1: second; 

void DEBUG(){
	for (int k=0;k<=1;k++){
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				printf("%d ", dp[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n\n");
	}
	printf("-----------\n");
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
    	scanf("%lld", &cakes[i]);
	}
	
	for (int i=0;i<N;i++){
		dp[i][i][0] = cakes[i];
		dp[i][i][1] = cakes[i];
	}
	
	for (int i=0;i<N;i++){
		ll left = cakes[i], right = (i==N-1) ? cakes[0] : cakes[i+1];
		dp[i][i+1][0] = max(left, right);
		dp[i][i+1][1] = max(left, right);
	}
	
	for (int d=2;d<N-1;d++){
		for (int i=0;i<N;i++){
			int j = (i+d)%N;
			if (i < j){
				dp[i][j][0] = max(dp[i][j-1][1] + cakes[j], dp[i+1][j][1] + cakes[i]);
				if (cakes[i] < cakes[j]){
					dp[i][j][1] = cakes[j] + max(dp[i][j-1][1]
				}
			}
		}
	}
	
	DEBUG();
	

    return 0;
}
