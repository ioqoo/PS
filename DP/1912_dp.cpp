// https://www.acmicpc.net/problem/1912

#include <bits/stdc++.h>

using namespace std;

int MAX = -10001;
int n;
int dp[100010];

int main(){
	scanf("%d", &n);
	for (int i=0;i<n;++i){
		scanf("%d", &dp[i]);
	}
	for (int i=1;i<n;++i){
		if (dp[i-1] > 0 && dp[i] + dp[i-1] > 0){
			dp[i] += dp[i-1];
			MAX = max(MAX, dp[i]);
		}
	}
	if (MAX == -10001){
		printf("%d\n", *max_element(dp, dp+n));
	}
	else{
		printf("%d\n", MAX);
	}

}
