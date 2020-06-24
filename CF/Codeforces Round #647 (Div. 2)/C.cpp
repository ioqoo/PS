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
    // cin >> t;
    while(t--){
        ll N;
        scanf("%lld", &N);
        ll ans = 0;
        for (int i=0;i<63;i++){
//            printf("%lld\n", 1LL<<i);
            if ((N & (1LL<<i)) != 0){
                ans += (1LL << i+1) - 1LL;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}



