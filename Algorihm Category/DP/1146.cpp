#include <bits/stdc++.h>
#define ll long long
const int MAX = 105;
const ll MOD = 1e6;
using namespace std;

ll dp[MAX][MAX][2];

ll solve(int L, int R, bool getting_higher){
	if (L+R == 0) return 1;
	ll &ret = dp[L][R][getting_higher];
	if (ret != -1) return ret;
	ret = 0;
	
	if (!getting_higher){
		for (int next=0;next<L;next++){
			ret += solve(next, (L+R) - (next+1), 1);
			ret %= MOD;
		}
	}
	else{
		for(int next=0;next<R;next++){
			ret += solve((L+R) - (next+1), next, 0);
			ret %= MOD;
		}
	}
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	if (N==1) {
		printf("1\n");
		return 0;
	}
	ll ans = 0;
	for (int i=0;i<N;i++){
		ans = (ans + solve(i, N-i-1, 0))%MOD;
		ans = (ans + solve(i, N-i-1, 1))%MOD;
	}
	printf("%lld\n", ans);
	
	
	return 0;
}


