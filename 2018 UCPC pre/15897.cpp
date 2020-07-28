#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll N;
    scanf("%lld", &N);
//    ll ans = 0;
//    ll end = sqrt(N-1);
//    for(int i=1;i<=end;i++){
//        ans += 1LL + (N-1)/i;
//    }
//    ans += ((N-1) - (end) + 1) * 2LL;
//    ans++;
//    
//    printf("%lld\n", ans);

//    for (int t=1;t<=100;t++){
//        ll ans = 0;
//        for (int i=1;i<=t;i++){
//            for (int j=1;j<=t;j+=i){
//                ans++;
//            }
//        }    
//        
//        printf("%d : %lld\n", t, ans);
//        
//    }
    int ans = 1;
    for (int i=sqrt(N-1);i>=2;i--){
        ans += i * ((N-1)/(i-1) - (N-1)/i + 1);
    }
    for (int i=1;i<(N-1)/sqrt(N-1);i++){
        ans += (N-1)/i;
    }
    ans += N;
    printf("%d\n", ans);

    return 0;
}



