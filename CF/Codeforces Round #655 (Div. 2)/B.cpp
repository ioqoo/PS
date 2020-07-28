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
        int n;
        scanf("%d", &n);
        int a = (int)sqrt(n);
        bool succ = false;
        for (int i=2;i<=a;i++){
            if (n%i == 0){
                printf("%d %d\n", n/i, n - n/i);
                succ = true;
                break;
            }
        }
        if (!succ){
            printf("%d %d\n", 1, n-1);
        }
    }
    

    return 0;
}



