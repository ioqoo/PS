#include <bits/stdc++.h>
#define MAX 10005
#define ll long long
#define MOD 10007LL

using namespace std;

int N;
ll grid[102][21];
int nums[102];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
    	scanf("%d", &nums[i]);
	}
	
	grid[1][nums[1]] = 1LL;
	
	for (int i=2;i<N;i++){
		int curr = nums[i];
		for (int n=0;n<=20;n++){
			ll prev_val = grid[i-1][n];
			if (prev_val){
				int plus = n + curr;
				int minus = n - curr;
				if (0<=plus && plus<=20) grid[i][plus] += prev_val;
				if (0<=minus && minus<=20) grid[i][minus] += prev_val;
			}
		}
	}
//	for (int i=0;i<=20;i++){
//		printf("%4d ", i);
//	}
//	printf("\n");
	
//	for (int i=1;i<=N;i++){
//		for (int j=0;j<=20;j++){
//			printf("%4d ", grid[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");

	printf("%lld\n", grid[N-1][nums[N]]);
        
    return 0;
}
