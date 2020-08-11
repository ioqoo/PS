#include <bits/stdc++.h>
#define ll long long
const int MAX = 100005;
using namespace std;

ll N;
ll arr[MAX];

ll chk(ll c){
	ll ret = 0;
	for (int i=0;i<N;i++){
		ret += (arr[i]-1)/c + 1;
	}
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%lld", &N);
	for (int i=0;i<N;i++){
		scanf("%lld", &arr[i]);
	}
	
	ll l = 1, r = 1e9;
	ll ans = 1e9+7;
	while(l<=r){
		ll mid = (l + r) / 2;
		if (chk(mid) <= 2*N-1){
			ans = min(ans, mid);
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	printf("%lld\n", ans);
		
	
	return 0;
}


