#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N;
    scanf("%d", &N);
    ll lb = -2e9 + 333, ub = 2e9 + 333;
    ll pre = 0;
    for (int i=1;i<=N;i++){
        ll curr;
        scanf("%lld", &curr);
        curr *= 2;
        ll b = curr - pre;
        if ((i+1)%2 == 1){
            ub = min(ub, (b-pre)/2);
        }
        else{
            lb = max(lb, (pre-b)/2);
        }
        pre = b;
    }
    if (lb > ub) printf("0\n");
    else printf("%lld\n", ub-lb+1);
    
//    for (int i=0;i<N;i++){
//        int curr = arr[i] - pre;
//        if ((i+1)%2 == 1){
//            ub = min(ub, (curr - pre) / 2);
//            printf("ub : %d\n", (curr - pre) / 2);
//        }
//        else {
//            lb = max(lb, (pre - curr) / 2);
//            printf("lb : %d\n", (pre - curr) / 2);
//        }Q
//        pre = curr;
//    }
//    printf("%d %d\n", lb, ub);
//    printf("%d\n", ub-lb+1);
    
    

    return 0;
}



