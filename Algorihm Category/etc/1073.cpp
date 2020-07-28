#include <bits/stdc++.h>

#define ll long long

using namespace std;

int degree[10];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        int a = temp/10, b = temp%10;
        degree[a]++; degree[b]++;
    }
    
    
    ll ans = 1;
    for (int i=0;i<=9;i++){
        int curr_degree = degree[i];
        if (curr_degree == 0) continue;
        if (curr_degree % 2 == 1) {
            printf("0\n");
            return 0;
        }
        for (int i=1;i<=curr_degree-1;i+=2){
            ans *= (ll)i;
        }
    }
    printf("%lld\n", ans);

    return 0;
}



