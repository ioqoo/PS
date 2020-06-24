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
        ll x1, y1, x2, y2;;
        scanf("%lld %lld %lld %lld\n", &x1, &y1, &x2, &y2);
        ll total = y2 - y1 + x2 - x1 - 1;
        ll ans = 0;
//        if (total%2 == 0){
        ll temp = min(y2-y1, x2-x1);
        ans += 2*(temp*(temp+1)/2);
        ans += temp * (total - (2*temp));
        printf("%lld\n", ans+1);
//        }
//        else{
//            
//        }
    }
    
    return 0;
}



