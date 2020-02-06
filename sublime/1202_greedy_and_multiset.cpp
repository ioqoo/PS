#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

multiset<pii> jew;
multiset<int> bag;
ll ans;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0;i<n;i++){
		int m, v;
		scanf("%d %d", &m, &v);
		jew.insert(pii(v, m));
	}
	for (int i=0;i<k;i++){
		int c;
		scanf("%d", &c);
		bag.insert(c);
	}
	for(multiset<pii>::reverse_iterator iter=jew.rbegin();iter!=jew.rend();++iter){
		pii curr = *iter;
		int curr_v = curr.first;
		int curr_m = curr.second;
		if (bag.lower_bound(curr_m)!=bag.end()){
			bag.erase(bag.lower_bound(curr_m));
			ans += curr_v;
		}
	}
	printf("%lld\n", ans);
}