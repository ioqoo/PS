#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[22][22][2];

ll solve(int L, int R, bool getting_higher){
	if (L + R == 0) return 1;
	ll &ret = dp[L][R][getting_higher];
	if (ret != -1) return ret;
	ret = 0;
	
	if (!getting_higher){ // choose L
		for (int next=0;next<L;next++){ 
			// .....curr.....
			// <-L->    <-R->
			// ..next...curr.....
			// choose next in L
			ret += solve(next, (L+R) - (next+1), 1);
		}
	}
	else{
		for (int next=0;next<R;next++){
			// .....curr.....
			// <-L->    <-R->
			// .....curr..next...
			// choose next in R
			ret += solve((L+R) - (next+1), next, 0);
		}
	}
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(dp, -1, sizeof(dp));
	
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		if (n == 1) {
			printf("1\n");
			continue;
		}
		ll ans = 0;
		for (int i=0;i<n;i++){
			ans += solve(i, n - (i+1), 0);
			ans += solve(i, n - (i+1), 1);
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}


