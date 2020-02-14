#include <bits/stdc++.h>
#define MAX 205
#define ll long long
#define MOD 100000LL

using namespace std;

ll facts[21] = {1LL, };
int seq[21];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
	int N, op;
	scanf("%d %d", &N, &op);
	
	if (N==1) {
		printf("1\n");
		return 0;
	}
	
	for (ll i = 1LL;i<=N;i++){
		facts[i] = facts[i-1]*i;
	}

	vector<int> nums;
	for (int i=1;i<=N;i++){
		nums.push_back(i);
	}
    
    if (op == 1){
    	ll k;
    	scanf("%lld", &k); k--;
		
		for (int i=1;i<=N;i++){
			ll mod = facts[N-i];
			int pos = k / mod;
			printf("%lld ", nums[pos]);
			nums.erase(nums.begin() + pos);
			k = k % mod;
		}
	}
	else{
		for (int i=1;i<=N;i++){
			scanf("%d", &seq[i]);
		}
		
		ll ans = 0LL;
		
		for (int i=1;i<=N;i++){
			int pos = find(nums.begin(), nums.end(), seq[i]) - nums.begin();
			ans += (pos) * facts[N-i];
			nums.erase(nums.begin() + pos);
		}
		printf("%lld\n", ans+1);
	}
    
    return 0;
}
