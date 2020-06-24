#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        if (n < m) swap(n, m); // n > m
        if (m%2 == 1){
            printf("%d\n", n * (m/2) + (n+1)/2);
        }
        else{
            printf("%d\n", n*(m/2));
        }
        
    }

    return 0;
}



