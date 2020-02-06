#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		ll str_size = str.size();
		ll ans = 0LL;
		ll prev = str[0] - '0';
		ans += (prev << (str_size-1LL));
		// cout << ans << "\n";
		for (ll i=1LL;i<str_size;i++){
			ll curr = str[i] - '0';
			ans += ((prev ^ curr) << (str_size-i-1LL));
			prev ^= curr;
		}
		cout << ans << "\n";
	}

}