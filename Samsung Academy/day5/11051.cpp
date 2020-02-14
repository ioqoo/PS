#include <bits/stdc++.h>
#define MAX 10005
#define ll long long
#define MOD 10007LL

using namespace std;

ll grid[1001][1001]; //nCk

ll comb(ll n, ll k){
	if (grid[n][k]) return grid[n][k];
	
	if (k == 0LL) return 1LL;
	
	if (k == 1LL) return n;
	
	if (n == k) return 1LL;
	
	return grid[n][k] = (comb(n-1, k-1) + comb(n-1, k)) % MOD ; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    ll N, K;
    scanf("%lld %lld", &N, &K);
    
    printf("%lld\n", comb(N, K));
    
    return 0;
}
