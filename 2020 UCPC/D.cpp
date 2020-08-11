#include <bits/stdc++.h>
#define ll long long
const int MAX = 3005;
using namespace std;

int N, M;
ll up[MAX], down[MAX];
ll L;
ll dp[MAX][MAX];
ll ans[MAX][MAX];

ll dist(ll x1, ll x2){
	return (x1-x2)*(x1-x2) + L*L;
}

ll solve(int u, int d){
//	printf("u : %d / d : %d \n", u, d);
//	for (int i=0;i<N+M;i++){
//		printf("%d ", ans[i]);
//	}
//	printf("\n");
	
	
	ll &ret = dp[u][d];
	if (ret != -1) return ret;
	
	if (u == N && d == M){
//		ans[u][d] = dist(up[u], down[d]);
		return ret = dist(up[u], down[d]);
	}
	
	if (u == N && d < M){
		ans[u][d] = 1;
		return ret = solve(u, d+1) + dist(up[u], down[d]);
	}
	
	if (u < N && d == M){
		ans[u][d] = 0;
		return ret = solve(u+1, d) + dist(up[u], down[d]);
	}
	
	ll A = solve(u+1, d);
	ll B = solve(u, d+1);
	if (A < B) ans[u][d] = 0;
	else ans[u][d] = 1;
	return ret = min(A, B) + dist(up[u], down[d]);
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(ans, -1, sizeof(ans));
	scanf("%d %d %lld", &N, &M, &L);
	for (int i=1;i<=N;i++){
		scanf("%lld", &up[i]);
	}
	for (int i=1;i<=M;i++){
		scanf("%lld", &down[i]);
	}
	memset(dp, -1, sizeof(dp));
	
	solve(1, 1);
	

	for (int i=1;i<=N;i++){
		for (int j=1;j<=M;j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i=1;i<=N;i++){
		for (int j=1;j<=M;j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	
	ll REAL_ANS = 0;
//	vector<ll> ans_arr;
	for (int i=1, j=1;i+j<=N+M; ){
		printf("%lld\n", dist(up[i], down[j]));
		REAL_ANS = dist(up[i], down[j]);
		if (ans[i][j] == 1){
			j++;
		}
		else{
			i++;
		}
	}
//	printf("%lld\n", REAL_ANS * (N+M-1));
//	for (int n: ans_arr){
//		printf("%d ", n);
//	}
	
	
//	ll real_ans = 0;
//	for (int i=0;i<N+M-2;i++){
//		for (int j=i+1;j<N+M-1;j++){
//			real_ans += ans_arr[i] - ans_arr[j];
//		}
//	}
//	for (int i=0;i<N+M-1;i++){
//		real_ans += ans_arr[i];
//	}
//	printf("%lld\n", real_ans);
//	for (int i=1;i<=N;i++){
//		for (int j=1;j<=M;j++){
//			printf("%lld ", dp[i][j]);
//		}
//		printf("===\n");
//	}
	
	
	
	return 0;
}


