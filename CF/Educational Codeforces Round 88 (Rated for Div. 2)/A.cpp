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
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        if (n/k >= m) printf("%d\n", m);
        else{
            printf("%d\n", n/k - (int)ceil((double)(m - n/k) / (double)(k-1)));
//            printf("%lf %lf\n", (double)(m - n/k) , (double)(k-1));
        }
    }

    return 0;
}



