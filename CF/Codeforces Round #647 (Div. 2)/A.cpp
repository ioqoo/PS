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
        ll a, b;
        scanf("%lld %lld", &a, &b);
        if (a>b) swap(a,b);
        int ans = 0;
        if (b%a != 0) {
            printf("-1\n");
            continue;
        }
        b /= a;
        bool succ = true;
        while(b > 1){
            if (b%8 == 0){
                b /= 8;
                ans++;
            }
            else if (b%4 == 0){
                b /= 4;
                ans++;
            }
            else if (b%2 == 0){
                b /= 2;
                ans++;
            }
            else{
                succ = false;
                break;
            }
        }
        if (!succ) {
            printf("-1\n");
            continue;
        }
        printf("%d\n", ans);
    }

    return 0;
}



