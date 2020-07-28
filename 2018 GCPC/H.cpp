#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//    ll ans = 0;
//    for (ll i=1;i<=2147;i++){
//        ans += pow(i, 4);
//    }
//    printf("%lld\n", ans);
    
    ll N;
    scanf("%lld", &N);
    
    for (ll s=1;s<=1000000;s++){
        if (s*(s+1)*(2*s+1) == 6*N){
            printf("%lld %lld\n", 3, s);
            return 0;
        }
    }
    for (ll n=3;n<=64;n++){
        ll temp = 0;
        for (ll s=1;s<=1000000;s++){
            temp += (ll)pow(s, n);
            if (temp > N) break;
            if (temp == N){
                printf("%lld %lld\n", n+1, s);
                return 0;
            }
        }
    }
    printf("impossible\n");

    return 0;
}



