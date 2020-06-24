#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N, X;
    scanf("%d %d", &N, &X);
    int ans = 0;
    for (int i=0;i<N;i++){
        int p1, p2;
        scanf("%d %d", &p1, &p2);
        if (abs(p1 - p2) <= X){
            ans += max(p1, p2);
        }
        else{
            int p3;
            scanf("%d", &p3);
            ans += p3;
        }
    }
    printf("%d\n", ans);

    return 0;
}



