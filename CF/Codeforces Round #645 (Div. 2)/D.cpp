#include <bits/stdc++.h>

#define ll long long
using namespace std;

int N;
ll X;
ll arr[600044];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %lld", &N, &X);
    
    for (int i=0;i<N;i++){
        int temp;
        scanf("%lld", &temp);
        arr[i] = arr[i+N] = arr[i+2*N] = temp;
    }
    
    int a = 0, b = 0;
    ll daycnt = 0;
    ll total = 0;
    ll ans = 0;
    while(a <= 3*N){
//        printf("a : %d / b : %d\n", a, b);
        if (b <= 3*N && daycnt <= X){
            daycnt += arr[b];
            total += arr[b] * (arr[b]+1)/2;
            b++;
        }
        else{
            ll temp = daycnt - X;
//            printf("%lld\n", temp);
            ans = max(ans, total - (temp*(temp+1)/2));
            daycnt -= arr[a];
            total -= arr[a] * (arr[a]+1)/2;
            a++;
        }        
    }
    printf("%lld\n", ans);
    
    
    

    return 0;
}



