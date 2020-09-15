#include <bits/stdc++.h>
#define ll long long
const int MAX = 300005;
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	setbuf(stdout, NULL);
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;
	scanf("%d", &T);
	for (int t=1;t<=T;t++){
		printf("Case #%d\n", t);
		int N;
		ll M;
		scanf("%d %lld", &N, &M);
		vector<ll> arr(N);
		for (int i=0;i<N;i++){
			scanf("%lld", &arr[i]);
		}
		vector<ll> psum(N);
		for (int i=0;i<N;i++){
			if (i==0) psum[0] = arr[0];
			else psum[i] = psum[i-1] + arr[i];
		}
		
		ll ans = 0;
		multiset<ll> MS;
		for (int i=0;i<N;i++){
			ll curr = psum[i];
			if (i==0) {
				if (curr <= M) ans = max(ans, curr);
				MS.insert(curr);
				continue;
			}
			ll diff = curr - M;
			auto it = MS.lower_bound(diff);
			if (it == MS.end()) {
				if (curr <= M) ans = max(ans, curr);
				MS.insert(curr);
				continue;
			}
//			printf("curr : %lld / sum : %lld\n", curr, curr - *it);
			ans = max(ans, (curr - *it));
			if (curr <= M) ans = max(ans, curr);
			MS.insert(curr);
		}
		printf("%lld\n", ans);
		
		
	}
	
	
	return 0;
}


