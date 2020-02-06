#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

multiset<pll> ms;
multiset<int> bag;
ll ans;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0;i<n;i++){
		ll m, v;
		scanf("%lld %lld", &m, &v);
		ms.insert(pll(v, m));
	}
	for (int i=0;i<k;i++){
		int c;
		scanf("%d", &c);
		bag.insert(c);
	}
	for (multiset<pll>::iterator iter = --ms.end() ; iter!= --ms.begin();--iter){
		pll curr = *iter;
		ll curr_v = curr.first;
		ll curr_m = curr.second;
		if (bag.lower_bound(curr_m)!=bag.end()){
			ans += curr_v;
			bag.erase(bag.find(*bag.lower_bound(curr_m)));
			k--;
		}
		if (k==0) break;
	}
	printf("%lld\n", ans);
}