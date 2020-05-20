#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with.stdio(0); cin.tie(0); cout.tie(0);

    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 1) printf("0\n");
        else if (n == 2) printf("%d\n", m);
        else printf("%d\n", 2*m);
        
    }

    return 0;
}



