#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    while(t--){
        ll n;
        scanf("%lld", &n);
        ll ans = 0;
        for (ll i=1LL;i<=n/2;i++){
            ans += i * i * 8LL;
        }
        printf("%lld\n", ans);
    }

    return 0;
}



