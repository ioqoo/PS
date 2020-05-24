#include <bits/stdc++.h>

const int MAX = 2e9;
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        
        int ans = n;
        int temp = n;
        while(n > 0){
            bool succ = false;
            for (int i=1;i*i<=n;i++){
                if (i > k) break;
                if (n%i == 0){
                    ans = min(ans, n/i);
                    n /= i;
                    succ = true;
                    break;
                }
            }
            if (!succ){
                ans = min(ans, max(ans, temp/ans));
                break;
            }            
        }
        printf("%d\n", ans);
        
//        if (n <= k) {
//            printf("1\n");
//            continue;
//        }
//        if (k == 1){
//            printf("%d\n", n);
//            continue;
//        }
//        if (n/2 <= k && n < k && n%2==0){
//            printf("2\n");
//            continue;
//        }
//        int ans = n;
//        for (int i=2;i*i<=n;i++){
//            if (i > k) break;
//            if (n%i == 0) {
//                ans = min(ans, min(i, n/i));
//            }
//        }
//        printf("%d\n", ans);
    }

    return 0;
}



