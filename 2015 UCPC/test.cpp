#include <bits/stdc++.h>
typedef long long ll;
const ll MOD = 1234567891;
using namespace std;

map<ll, ll> mp;

void solve(ll N, ll M){
	if (N==1){
		mp[M]++;
		mp[M] %= MOD;
		return;
	}
	else if (M==1){
		mp[N]++;
		mp[N] %= MOD;
		return;
	}
	
	ll a = (ll)floor(N/2.), b = (ll)floor(M/2.), c = (ll)ceil(N/2.), d = (ll)ceil(M/2.);
	solve(a, b);
	solve(a, d);
	solve(c, b);
	solve(c, d);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	scanf("%d", &t);
	while(t--){
		mp.clear();
		ll N, M;
		scanf("%lld %lld\n", &N, &M);
		solve(N, M);
		printf("%lld\n", mp.size());
		for (auto it=mp.begin();it!=mp.end();it++){
			printf("%lld %lld\n", it->first, (it->second)%MOD);
		}
		
	}
	
	return 0;
}


