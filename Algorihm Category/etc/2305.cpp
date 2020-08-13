#include <bits/stdc++.h>
const int MAX = 42;
using namespace std;

int fib[MAX];
int psum[MAX];
int dp[MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, K;
	scanf("%d %d", &N, &K);
	
	fib[0] = fib[1] = 1;
	for (int i=2;i<=40;i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	psum[0] = fib[0];
	for (int i=1;i<=40;i++){
		psum[i] = psum[i-1] + fib[i];
	}
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for (int i=3;i<=40;i++){
		dp[i] = dp[i-1] + dp[i-2] + psum[i-2] + psum[i-3];
	}
	int ans = dp[N-K+1] * fib[K-1] + dp[K] * fib[N-K] - fib[K-1] * fib[N-K];
	printf("%d\n", ans);
	
	
	return 0;
}

