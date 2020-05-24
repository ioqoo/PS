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
        int a, b;
        scanf("%d %d", &a, &b);
        if (a==b) {
            printf("%d\n", 4*a*a);
            continue;
        }
        if (a<b) swap(a,b);
        if (a>b){
            if (a < 2*b){
                printf("%d\n", 4*b*b);
                continue;
            }
            else{
                printf("%d\n", a*a);
            }
        }
        
    }
    
    
    
    return 0;
}



